import os, re, time
from utils import load_llm, read_file, save_file, timestamp

def clean_verilog(text):
    # Extract all code blocks
    code_blocks = re.findall(r'```(?:systemverilog|verilog)?\n([\s\S]*?)```', text)
    if code_blocks:
        text = "\n".join(code_blocks)
    # Drop any non-Verilog English lines
    text = "\n".join(
        line for line in text.splitlines()
        if not re.match(r'^[A-Za-z#*\-`]|^\s*$', line) or line.strip().startswith(('module', '`timescale'))
    )
    return text

def main():
    model = load_llm()
    spec = read_file("spec/design_spec.txt")

    prompt = f"""
You are a SystemVerilog generator.
Generate **only valid compilable SystemVerilog-2012 code**, no text or markdown.
Target: Verilator-compatible RTL for a single-cycle 32-bit RISC-V core.
Output must start with `timescale 1ns/1ps` and contain full module definitions.
No explanations. No headings. No fences. Just code.

Specification:
{spec}
"""

    print("[INFO] Requesting RTL code from LLM...")
    try:
        response = model.generate_content(prompt)
    except Exception as e:
        print("LLM call failed:", e)
        time.sleep(60)
        response = model.generate_content(prompt)

    verilog = clean_verilog(response.text)
    file_path = f"rtl/generated_{timestamp()}.sv"
    save_file(file_path, verilog)
    print("[INFO] Cleaned RTL saved:", file_path)

if __name__ == "__main__":
    main()
