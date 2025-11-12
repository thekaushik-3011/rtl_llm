import os
import re
from utils import load_llm, read_file, save_file, timestamp

def main():
    model = load_llm()

    # Read the English specification file
    spec = read_file("spec/design_spec.txt")

    # Collect all generated RTL files to give LLM signal/port context
    rtl_files = [f"rtl/{f}" for f in os.listdir("rtl") if f.endswith(".sv")]
    rtl_code = ""
    for path in rtl_files:
        with open(path, "r") as f:
            rtl_code += f"\n// ===== File: {path} =====\n" + f.read()

    # Construct strong prompt for clean testbench generation
    prompt = f"""
You are a SystemVerilog verification engineer.

Generate a Verilator-compatible SystemVerilog testbench for the following RTL design.
Return only compilable code inside one code block. Do not include explanations, markdown, or text outside the code block.

Rules:
- Verilator-compatible SystemVerilog-2012 subset.
- No markdown, no headings, no English commentary.
- Include `timescale 1ns/1ps` at the top.
- Instantiate the top-level DUT module named `riscv_core_top`.
- Add clock and reset generators.
- Create basic stimulus:
    * Reset sequence.
    * A few example instruction or memory transactions.
    * Display PASS/FAIL messages.
- Use $finish at end of simulation.
- The testbench must be fully self-contained (no includes).
- No dependencies on UVM, DPI, or external files.
- End the file with `endmodule`.

Specification:
---
{spec}
---

Partial RTL Context (for signal and port references):
---
{rtl_code[:10000]}
---

Output only valid SystemVerilog code, starting with `timescale` and ending with `endmodule`.
"""

    print("[INFO] Sending verification prompt to LLM...")
    response = model.generate_content(prompt)
    content = response.text

    # Extract only code blocks if the model adds markdown
    match = re.findall(r'```(?:systemverilog|verilog)?\n([\s\S]*?)```', content)
    if match:
        content = "\n\n".join(match)

    file_path = f"tb/testbench_{timestamp()}.sv"
    save_file(file_path, content)
    print("[INFO] Testbench generation complete:", file_path)


if __name__ == "__main__":
    main()
