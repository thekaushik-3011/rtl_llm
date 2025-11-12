# LLM Prompt Templates

### RTL Generation Prompt
> Given the English spec, produce modular behavioral SystemVerilog RTL using non-blocking assignments and synthesizable code only.

### Verification Prompt
> Given the RTL, create a top-level testbench, directed tests, and coverage collection setup compatible with Verilator.

### Refinement Prompt
> Compare simulation results and re-generate fixed RTL if assertions fail or output mismatches.
