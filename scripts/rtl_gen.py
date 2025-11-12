#!/usr/bin/env python3
"""
rtl_gen.py

Usage:
  - Interactive mode:
      python3 scripts/rtl_gen.py
    The script will prompt for a few high-level fields and save a spec file under spec/.

  - Spec-file mode:
      python3 scripts/rtl_gen.py --spec spec/my_design.yaml

What it does:
  1. Loads or collects a user specification (YAML/JSON/plain-text via CLI).
  2. Builds a focused LLM prompt instructing the model to emit synthesizable SystemVerilog (behavioral).
  3. Calls the configured Google generative AI client (if installed and configured).
     - Attempts reasonable call variants to accommodate different client versions.
  4. Sanitizes the LLM response to remove Markdown, prose, and code fences.
  5. Writes the sanitized RTL to rtl/generated_<timestamp>.sv.
  6. Prints next steps to console.

Notes:
  - This script does not try to run Verilator or other tools; it's purely generation + sanitization.
  - Ensure GOOGLE_API_KEY is set or genai.configure(...) has been run in your environment.
  - Default model can be overridden by environment variable MODEL_NAME.
"""

import os
import sys
import argparse
import json
import re
import datetime
from pathlib import Path
from textwrap import dedent

# Try to import Google generative client (may be available as google.generativeai)
GENAI = None
try:
    import google.generativeai as genai  # preferred wrapper used earlier in this environment
    GENAI = "generativeai"
except Exception:
    try:
        import google.generativelanguage as gl  # fallback name used in some libs
        GENAI = "generativelanguage"
    except Exception:
        GENAI = None

# ---------- Utilities ----------

def mkdir_p(p: str):
    Path(p).mkdir(parents=True, exist_ok=True)

def timestamp_str():
    return datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S")

def read_file_or_none(path: str):
    try:
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    except Exception:
        return None

def write_file(path: str, data: str):
    with open(path, "w", encoding="utf-8") as f:
        f.write(data)

# ---------- Spec ingestion ----------

def collect_spec_interactive() -> dict:
    """Simple interactive CLI to collect a short spec and save as YAML-ish dict."""
    print("Collecting design specification (interactive). Press Enter to accept defaults.")
    design_name = input("Design name [riscv_core]: ").strip() or "riscv_core"
    design_type = input("Design type [processor/controller] (default: processor): ").strip() or "processor"
    isa = input("ISA (e.g., RV32I) [RV32I]: ").strip() or "RV32I"
    pipeline_stages = input("Pipeline stages (1 for single-cycle) [1]: ").strip() or "1"
    try:
        pipeline_stages = int(pipeline_stages)
    except Exception:
        pipeline_stages = 1
    include_interrupt = input("Include interrupt controller? [y/N]: ").strip().lower() in ("y", "yes")
    include_uart = input("Include UART peripheral? [y/N]: ").strip().lower() in ("y", "yes")
    extra = input("Any extra requirements (comma separated, e.g. 'forwarding, byte-enable'): ").strip()

    spec = {
        "design_name": design_name,
        "design_type": design_type,
        "isa": isa,
        "pipeline_stages": pipeline_stages,
        "include_interrupt": include_interrupt,
        "include_uart": include_uart,
        "extras": [x.strip() for x in extra.split(",") if x.strip()]
    }
    # Save spec to file
    mkdir_p("spec")
    spec_path = f"spec/{design_name}_spec_{timestamp_str()}.json"
    write_file(spec_path, json.dumps(spec, indent=2))
    print(f"[INFO] Saved spec to {spec_path}")
    return spec

def load_spec_from_file(path: str) -> dict:
    txt = read_file_or_none(path)
    if txt is None:
        raise FileNotFoundError(f"Spec file not found: {path}")
    # try json
    try:
        return json.loads(txt)
    except Exception:
        # try simple YAML-ish parse (very small)
        try:
            import yaml  # optional dependency; if not present skip
            return yaml.safe_load(txt)
        except Exception:
            # fallback: return raw text in dict
            return {"raw_spec_text": txt}

# ---------- Prompt construction ----------

PROMPT_TEMPLATE = dedent("""
You are an expert hardware design assistant. Generate synthesizable, Verilator-compatible,
behavioral SystemVerilog source for the hardware described below.

Requirements:
1. Output ONLY the SystemVerilog code. Do not write any explanatory text, headings, or markdown.
2. The code must be synthesizable behavioral SystemVerilog (no vendor primitives).
3. Use `module` declarations for each module. Include a top-level module named `{top_module}` that wires submodules.
4. Include minimal comments in-line (//), but no large prose blocks. Do not include markdown fences (```).
5. Use `logic` and SystemVerilog constructs (always_comb, always_ff, typedef where appropriate).
6. Add simple `ifdef FORMAL` assertions for key invariants where relevant (optional).
7. Keep the design modular and clear. Respect the specification below.
8. Avoid generating any file operations or references to external images or URLs.

Specification:
{spec_text}

Produce the RTL files content that will be written to a single .sv file. If the design is large, generate the top-level and modules sequentially in the file.
""").strip()

def build_prompt(spec: dict) -> str:
    # Prepare a human-friendly text block from the spec dict
    if "raw_spec_text" in spec:
        spec_text = spec["raw_spec_text"]
    else:
        lines = []
        for k, v in spec.items():
            lines.append(f"- {k}: {v}")
        spec_text = "\n".join(lines)
    top_module = spec.get("design_name", "top_module") + "_top"
    return PROMPT_TEMPLATE.format(top_module=top_module, spec_text=spec_text), top_module

# ---------- LLM call wrapper ----------

def call_llm(prompt: str, model_name: str = None, max_output_tokens: int = 1500, temperature: float = 0.0) -> str:
    """
    Try a few common call patterns for Google generative API.
    Requires the environment to have GOOGLE_API_KEY or appropriate ADC set up.
    """
    model_name = model_name or os.getenv("MODEL_NAME") or "models/gemini-2.5-pro"

    if GENAI is None:
        raise RuntimeError(
            "No Google generative client installed. Install google.generativeai or google.generativelanguage and set GOOGLE_API_KEY.\n"
            "Example: pip install google-generativeai\n"
            "Then set: export GOOGLE_API_KEY='YOUR_KEY'"
        )

    # configure if possible
    try:
        if GENAI == "generativeai":
            # if user hasn't configured, attempt to auto configure from env var
            apikey = os.getenv("GOOGLE_API_KEY")
            if apikey:
                try:
                    genai.configure(api_key=apikey)
                except Exception:
                    pass
            # try multiple function names
            try:
                resp = genai.generate_text(model=model_name, prompt=prompt, max_output_tokens=max_output_tokens, temperature=temperature)
                # response may be a dict-like; try to extract
                if hasattr(resp, "text"):
                    return resp.text
                if isinstance(resp, dict):
                    # different versions: look for 'candidates' or 'output'
                    if "candidates" in resp and resp["candidates"]:
                        # candidate may be dict with 'content' or 'output'
                        c = resp["candidates"][0]
                        return c.get("content") or c.get("output") or c.get("text") or str(c)
                    if "output" in resp:
                        return resp["output"]
                    # fallback
                    return json.dumps(resp)
            except Exception:
                # try another call pattern
                try:
                    response = genai.generate(
                        model=model_name,
                        prompt=prompt,
                        max_output_tokens=max_output_tokens,
                        temperature=temperature,
                    )
                    if isinstance(response, dict):
                        # many shapes possible
                        if "candidates" in response and response["candidates"]:
                            return response["candidates"][0].get("content", "")
                        if "output" in response:
                            return response["output"]
                    return str(response)
                except Exception as e:
                    raise RuntimeError(f"LLM call failed (generativeai). Last error: {e}")
        elif GENAI == "generativelanguage":
            # different library; try typical pattern
            apikey = os.getenv("GOOGLE_API_KEY")
            if apikey:
                try:
                    gl.configure(api_key=apikey)
                except Exception:
                    pass
            try:
                resp = gl.generate_text(model=model_name, prompt=prompt, max_output_tokens=max_output_tokens)
                # extract text
                if hasattr(resp, "candidates") and resp.candidates:
                    return resp.candidates[0].content
                if isinstance(resp, dict) and "candidates" in resp:
                    return resp["candidates"][0].get("content", "")
                if hasattr(resp, "text"):
                    return resp.text
                return str(resp)
            except Exception as e:
                raise RuntimeError(f"LLM call failed (generativelanguage). Error: {e}")
    except Exception as e:
        raise RuntimeError(f"LLM invocation error: {e}")

# ---------- Sanitization ----------

def sanitize_verilog_blob(text: str) -> str:
    """
    Remove Markdown, narration, and keep only SystemVerilog code.
    Heuristics:
     - Remove code fences ```...```
     - Remove leading prose until first 'module ' is found
     - Remove Markdown headings that start with '#' or '###'
     - Strip trailing prose after last 'endmodule' (keep last endmodule)
     - Ensure file ends with newline
    """
    if not text:
        return ""

    # Normalize line endings
    text = text.replace("\r\n", "\n").replace("\r", "\n")

    # Remove fenced code blocks ```...```
    text = re.sub(r"```(?:systemverilog|verilog)?\n.*?\n```", "", text, flags=re.DOTALL|re.IGNORECASE)
    # Remove any remaining triple backticks
    text = re.sub(r"```.*?```", "", text, flags=re.DOTALL)

    # Remove Markdown headings and lines that look like "### Module ..."
    text = "\n".join([ln for ln in text.splitlines() if not re.match(r'^\s*#{1,6}\s+', ln)])

    # If there is a 'module ' token, keep from its first occurrence
    m = re.search(r'\bmodule\s+[A-Za-z0-9_]+\b', text)
    if m:
        start = m.start()
        text = text[start:]
    else:
        # as a fallback, try to remove long prose header: drop leading paragraph before first semicolon or 'input'
        # but keep whole text if no sign of verilog
        if not re.search(r'\b(input|output|module|endmodule|always|assign)\b', text):
            # nothing looks like verilog; return original trimmed
            return text.strip() + "\n"

    # Keep everything up to last 'endmodule' if present
    last_endmodule = text.rfind("endmodule")
    if last_endmodule != -1:
        text = text[:last_endmodule + len("endmodule")]

    # Remove lines that are clearly plain English (heuristic: lines longer than 200 chars or many spaces and letters)
    filtered_lines = []
    for ln in text.splitlines():
        # if line contains a semicolon, module, input, output, logic, always, endmodule,endmodule - keep
        if re.search(r'\b(module|endmodule|input|output|logic|wire|assign|always|initial|parameter|localparam)\b', ln):
            filtered_lines.append(ln)
            continue
        # lines with only code-like chars including parentheses, commas, ; or brackets -> keep
        if re.search(r'[;{}()\[\]=<>+\-*/%]', ln):
            filtered_lines.append(ln)
            continue
        # otherwise drop if it's plain English (letters + spaces, no code punctuation) and not short signal line
        if len(ln.strip()) == 0:
            filtered_lines.append(ln)
            continue
        # allow short config lines like "parameter WIDTH = 32;"
        if len(ln) < 120:
            filtered_lines.append(ln)
            continue
        # else skip very long prose
    text = "\n".join(filtered_lines)

    # Remove any stray non-ASCII control chars
    text = re.sub(r'[^\x09\x0A\x0D\x20-\x7E]', '', text)

    # Ensure final newline
    if not text.endswith("\n"):
        text = text + "\n"

    return text

# ---------- Main flow ----------

def main():
    parser = argparse.ArgumentParser(description="Generate SystemVerilog RTL from a plain-English spec using an LLM.")
    parser.add_argument("--spec", "-s", help="Path to spec file (JSON/YAML/plain text). If omitted, interactive mode starts.", default=None)
    parser.add_argument("--model", "-m", help="LLM model name to use (overrides MODEL_NAME env var).", default=None)
    parser.add_argument("--outdir", "-o", help="Output directory for generated rtl (default: rtl/)", default="rtl")
    parser.add_argument("--max-tokens", "-t", type=int, default=2000, help="Max output tokens for LLM")
    args = parser.parse_args()

    # 1. Read or collect spec
    if args.spec:
        try:
            spec = load_spec_from_file(args.spec)
        except Exception as e:
            print(f"[ERROR] Failed to load spec file: {e}", file=sys.stderr)
            sys.exit(1)
    else:
        spec = collect_spec_interactive()

    # 2. Build prompt and top module name
    prompt, top_module = build_prompt(spec)

    # 3. Persist prompt (optional)
    mkdir_p("spec")
    prompt_path = f"spec/prompt_{spec.get('design_name','design')}_{timestamp_str()}.txt"
    write_file(prompt_path, prompt)
    print(f"[INFO] Prompt saved to {prompt_path}")

    # 4. Call LLM
    model_name = args.model or os.getenv("MODEL_NAME") or "models/gemini-2.5-pro"
    print(f"[INFO] Sending prompt to LLM (model={model_name}) ...")
    try:
        llm_raw = call_llm(prompt, model_name=model_name, max_output_tokens=args.max_tokens, temperature=0.0)
    except Exception as e:
        print(f"[ERROR] LLM call failed: {e}", file=sys.stderr)
        print("Tip: ensure GOOGLE_API_KEY is set and the google.generativeai / generativelanguage package is installed.")
        # Save prompt for manual use
        sys.exit(1)

    if not llm_raw or llm_raw.strip() == "":
        print("[ERROR] LLM returned empty response", file=sys.stderr)
        sys.exit(1)

    # 5. Sanitize output
    print("[INFO] Sanitizing LLM output (removing prose and non-SV content)...")
    sv_text = sanitize_verilog_blob(llm_raw)

    # Basic sanity check: ensure at least one module appears
    if not re.search(r'\bmodule\s+[A-Za-z0-9_]+\b', sv_text):
        # save llm_raw for debugging
        err_path = f"{args.outdir}/failed_raw_{timestamp_str()}.txt"
        mkdir_p(args.outdir)
        write_file(err_path, llm_raw)
        print(f"[ERROR] Sanitization failed to detect any 'module' in LLM output. Raw response saved to {err_path}", file=sys.stderr)
        # Also save sanitized output for inspection
        debug_path = f"{args.outdir}/failed_sanitized_{timestamp_str()}.sv"
        write_file(debug_path, sv_text)
        print(f"[INFO] Sanitized content (possibly empty) saved to {debug_path}")
        sys.exit(1)

    # 6. Save to file
    mkdir_p(args.outdir)
    fname = f"{args.outdir}/generated_{timestamp_str()}.sv"
    write_file(fname, sv_text)
    print(f"[SUCCESS] SystemVerilog saved to: {fname}")

    # 7. Print next steps
    print("\nNext steps:")
    print("  1) Review the file and make small edits if needed.")
    print("  2) Generate a testbench (use tb_gen.py) and run verification (verify_run.py).")
    print("  3) If simulator errors occur, inspect the saved prompt and raw LLM output under spec/ for debugging.")
    print("\nFiles created:")
    print(f"  - RTL: {fname}")
    print(f"  - Prompt: {prompt_path}")

if __name__ == "__main__":
    main()
