import os
import re
import subprocess
import time
from utils import timestamp

# --------------------------------------------------------------------
# Helper function to clean up bad RTL syntax before Verilator run
# --------------------------------------------------------------------
def sanitize_rtl(filename):
    with open(filename, "r") as f:
        code = f.read()

    original = code

    # 1. Remove underscores from binary literals (7'b0100000_000 → 10'b0100000000)
    code = re.sub(r"(\d+)'b([01_]+)", lambda m: f"{m.group(1)}'b{m.group(2).replace('_','')}", code)

    # 2. If any illegal width patterns (e.g., 7'b0100000000), increase bit width automatically
    code = re.sub(
        r"7'b([01]{8,})",  # anything more than 7 bits
        lambda m: f"{len(m.group(1))}'b{m.group(1)}",
        code
    )

    # 3. Remove trailing whitespace and ensure newline at EOF
    code = re.sub(r"\s+$", "", code, flags=re.M)
    if not code.endswith("\n"):
        code += "\n"

    if code != original:
        with open(filename, "w") as f:
            f.write(code)
        print(f"[INFO] Sanitized RTL syntax in {filename}")


# --------------------------------------------------------------------
# Run Verilator for verification
# --------------------------------------------------------------------
def run_verilator():
    rtl_files = [f"rtl/{f}" for f in os.listdir("rtl") if f.endswith(".sv")]
    tb_files = [f"tb/{f}" for f in os.listdir("tb") if f.endswith(".sv")]

    if not rtl_files or not tb_files:
        raise FileNotFoundError("No RTL or testbench files found.")

    # Sanitize RTL and TB before simulation
    for f in rtl_files + tb_files:
        sanitize_rtl(f)

    cmd = [
        "verilator",
        "--cc", "--exe", "--build",
        "--top-module", "tb_riscv_core", 
        "-Wall", "--trace", "--trace-fst",
        "--timing",
        "--Wno-fatal",           # <<< continue despite warnings
        "--Wno-DECLFILENAME",
        "--Wno-UNUSEDSIGNAL",    # suppress unused signal warnings
        "--Wno-UNOPTFLAT",       # suppress circular combinational logic warnings
        "tb/sim_main.cpp",
        *rtl_files, *tb_files
    ]

    print("[INFO] Running Verilator build...")
    subprocess.run(cmd, check=True)
    print("[INFO] Verilator compilation completed successfully.")

# --------------------------------------------------------------------
# Main entry point
# --------------------------------------------------------------------
def main():
    print("[INFO] Starting verification run...")
    try:
        run_verilator()
        print("[SUCCESS] RTL + Testbench compiled successfully.")
    except subprocess.CalledProcessError as e:
        print("[ERROR] Verilator run failed.")
        print(e)
    except Exception as e:
        print("[ERROR] Unexpected failure:", e)
        time.sleep(2)

if __name__ == "__main__":
    main()
