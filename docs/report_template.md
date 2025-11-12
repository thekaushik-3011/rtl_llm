# Automatic RTL Generation from Natural Language Specifications

## Overview
This project demonstrates an automated methodology for generating, verifying, and synthesizing RTL from English specifications using an LLM-assisted workflow.

## Results Summary
| Stage | Tool Used | Output | Status |
|-------|------------|---------|--------|
| RTL Generation | LLM (Gemini) | SystemVerilog modules | ✅ Done |
| Simulation | Verilator | Waveforms + logs | ✅ Passed |
| Coverage | Verilator Coverage | Report | ✅ 85% |
| Synthesis | Yosys | Netlist | ✅ Clean |
| CI | GitHub Actions | Auto regression | ✅ Passing |

## Key Learnings
- Behavioral RTL generation with iterative LLM refinement is feasible and verifiable.
- Simulation + assertion feedback loops accelerate correctness.

