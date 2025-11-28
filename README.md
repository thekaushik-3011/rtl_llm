# RTL Generation from Natural Language

**Automatic generation of synthesizable Verilog RTL from natural language specifications using Large Language Models with comprehensive verification.**

---

## 🎯 Overview

This project implements a complete pipeline that:
1. **Parses** natural language or structured specifications
2. **Generates** synthesizable Verilog RTL using GPT-4
3. **Creates** comprehensive testbenches automatically
4. **Verifies** through linting and simulation
5. **Synthesizes** and analyzes the design
6. **Refines** iteratively based on feedback

---

## 📋 Prerequisites

### System Requirements
- **OS**: Ubuntu 20.04+ or Debian-based Linux
- **Python**: 3.8 or higher
- **RAM**: 4GB minimum, 8GB recommended
- **Disk**: 2GB free space

### Required Tools
- Verilator (for linting and simulation)
- Yosys (for synthesis)
- Icarus Verilog (for simulation)
- GTKWave (for waveform viewing - optional)

---

## 🚀 Quick Start

### 1. Clone and Setup

```bash
# Clone the repository (or create the directory structure)
mkdir rtl-gen-project && cd rtl-gen-project

# Make setup script executable
chmod +x setup.sh

# Run setup (installs all dependencies)
./setup.sh
```

### 2. Configure API Keys

Edit the `.env` file and add your OpenAI API key:

```bash
nano .env
```

Add:
```
OPENAI_API_KEY=sk-your-api-key-here
```

### 3. Activate Environment

```bash
source venv/bin/activate
```

### 4. Run First Example

```bash
# Generate example specifications
python -c "from src.utils import create_example_specs; create_example_specs()"

# Run the pipeline
python src/main.py --spec data/specs/simple/counter.json
```

---

## 📁 Project Structure

```
rtl-gen-project/
├── README.md              # This file
├── setup.sh               # Automated setup script
├── requirements.txt       # Python dependencies
├── .env                   # Environment variables (API keys)
│
├── config/
│   └── config.yaml        # Pipeline configuration
│
├── data/
│   ├── specs/             # Input specifications
│   │   ├── simple/        # Simple designs
│   │   ├── medium/        # Medium complexity
│   │   └── complex/       # Complex designs
│   ├── reference_rtl/     # Reference implementations
│   └── testbenches/       # Reference testbenches
│
├── src/
│   ├── main.py            # Main pipeline orchestrator
│   ├── spec_parser.py     # Specification parser
│   ├── rtl_generator.py   # RTL generation with LLM
│   ├── testbench_generator.py  # Testbench generation
│   ├── verifier.py        # Verification (lint + sim)
│   ├── synthesizer.py     # Synthesis and analysis
│   └── utils.py           # Utility functions
│
├── output/
│   ├── generated_rtl/     # Generated Verilog files
│   ├── testbenches/       # Generated testbenches
│   ├── simulation_results/  # Simulation logs and VCD
│   └── synthesis_reports/ # Synthesis reports
│
└── logs/                  # Pipeline logs
```

---

## 📝 Usage

### Basic Usage

```bash
python src/main.py --spec <path-to-spec-file>
```

### Advanced Options

```bash
python src/main.py \
    --spec data/specs/simple/alu.json \
    --config config/config.yaml \
    --iterations 5 \
    --verbose
```

**Options:**
- `--spec, -s`: Path to specification file (required)
- `--config, -c`: Path to config file (default: config/config.yaml)
- `--iterations, -i`: Max refinement iterations (default: 3)
- `--verbose, -v`: Enable verbose logging

---

## 📄 Specification Formats

### JSON Format

```json
{
  "module": "alu",
  "description": "8-bit ALU with arithmetic and logic operations",
  "timing": "combinational",
  "inputs": [
    {"name": "a", "width": 8, "description": "Operand A"},
    {"name": "b", "width": 8, "description": "Operand B"},
    {"name": "opcode", "width": 3, "description": "Operation code"}
  ],
  "outputs": [
    {"name": "result", "width": 8, "description": "Result"},
    {"name": "zero", "width": 1, "description": "Zero flag"}
  ],
  "operations": ["ADD", "SUB", "AND", "OR", "XOR"]
}
```

### YAML Format

```yaml
module: counter
description: 8-bit up counter with enable
timing: sequential
inputs:
  - name: clk
    width: 1
  - name: rst
    width: 1
  - name: enable
    width: 1
outputs:
  - name: count
    width: 8
```

### Natural Language Format

Create a `.txt` file:

```
Design an 8-bit ALU that takes two 8-bit inputs (a and b) and a 3-bit 
opcode. It should support ADD, SUB, AND, OR, and XOR operations. 
Output the 8-bit result and a zero flag indicating if the result is zero.
This is a combinational circuit.
```

---

## 🔧 Configuration

Edit `config/config.yaml` to customize:

```yaml
# LLM settings
llm:
  model: gpt-4           # or gpt-3.5-turbo
  temperature: 0.2       # Lower = more deterministic
  max_tokens: 2000

# Pipeline settings
max_iterations: 3        # Refinement attempts

# Verification
verification:
  enable_linting: true
  enable_simulation: true
  simulation_timeout: 60

# Synthesis
synthesis:
  enable_synthesis: true
  synthesis_timeout: 60
```

---

## 📊 Output Files

After running the pipeline, you'll find:

### Generated RTL
- Location: `output/generated_rtl/`
- Files: `<module_name>.v`
- Synthesizable Verilog code

### Testbenches
- Location: `output/testbenches/`
- Files: `tb_<module_name>.v`
- Complete testbench with test vectors

### Simulation Results
- Location: `output/simulation_results/`
- Files: 
  - `<module>.log` - Simulation output
  - `<module>.vcd` - Waveform data
  - `<module>.vvp` - Compiled simulation

### Synthesis Reports
- Location: `output/synthesis_reports/`
- Files:
  - `<module>_report.txt` - Detailed report
  - `<module>_synth.log` - Synthesis log
  - `<module>_stat.txt` - Statistics

---

## 🔍 Viewing Waveforms

To view simulation waveforms:

```bash
gtkwave output/simulation_results/<module>.vcd
```

---

## 📈 Pipeline Flow

```
Input Spec → Parse → Generate RTL → Generate TB
                ↓                      ↓
            Validate              Run Tests
                ↓                      ↓
           [Pass/Fail]          [Pass/Fail]
                ↓                      ↓
         Refine if needed ←──────────┘
                ↓
           Synthesize
                ↓
         Generate Report
```

---

## 🧪 Example Designs

### Simple (Included)
- **Counter**: 8-bit up counter with enable
- **ALU**: 8-bit arithmetic logic unit
- **Register File**: 8-register file with dual read ports

### Medium (Create Your Own)
- UART transmitter/receiver
- Timer with prescaler
- FSM-based controllers

### Complex (Advanced)
- RISC-V core (simple pipeline)
- Memory controller
- Bus arbiter

---

## 🛠️ Troubleshooting

### API Key Issues

```bash
# Check if API key is set
echo $OPENAI_API_KEY

# Set temporarily
export OPENAI_API_KEY=sk-your-key-here
```

### Tool Not Found

```bash
# Check tool installation
which verilator
which yosys
which iverilog

# If missing, reinstall
sudo apt-get install verilator yosys iverilog
```

### Linting Failures

Check the errors in the log:
```bash
cat logs/rtl_pipeline_*.log | grep -i error
```

Common issues:
- Undeclared signals: Add to module ports or declare as wire/reg
- Syntax errors: Check for missing semicolons
- Non-blocking in combinational: Use `=` instead of `<=`

### Simulation Failures

```bash
# Check simulation log
cat output/simulation_results/<module>.log

# Run simulation manually
iverilog -o test.vvp output/generated_rtl/<module>.v output/testbenches/tb_<module>.v
vvp test.vvp
```

---

## 📚 Advanced Features

### Few-Shot Learning

Provide example designs to improve generation:

```python
from src.rtl_generator import RTLGenerator

examples = [
    ("4-bit counter", "module counter...\nendmodule"),
    ("8-bit register", "module register...\nendmodule")
]

generator = RTLGenerator(config)
rtl = generator.generate_with_examples(spec_data, examples)
```

### Custom Prompts

Edit prompt templates in `src/rtl_generator.py`:

```python
def _build_generation_prompt(self, spec_data):
    # Customize your prompt here
    prompt = f"""Custom instructions...
    Specification: {spec_data}
    ...
    """
    return prompt
```

### Batch Processing

Process multiple specs:

```bash
for spec in data/specs/simple/*.json; do
    python src/main.py --spec "$spec"
done
```

---

## 📊 Metrics and Evaluation

The pipeline tracks:
- **Functional Accuracy**: % of tests passed
- **Synthesis Success Rate**: % of designs synthesized
- **Gate Count**: Resource utilization
- **Iteration Count**: Refinement needed
- **Time**: Generation and verification time

View in `output/pipeline_report.json`:

```json
{
  "timestamp": "2025-01-15T10:30:00",
  "stages": {
    "parsing": {"status": "success"},
    "rtl_generation": {"status": "success", "lines_of_code": 45},
    "verification": {"status": "success", "iterations": 1},
    "synthesis": {"status": "success", "gate_count": 127}
  },
  "metrics": {
    "total_cells": 127,
    "logic_gates": 85,
    "flip_flops": 32
  }
}
```

---

## 🔬 Testing

Run the test suite:

```bash
pytest tests/
```

---

## 📄 License

This project is provided for educational and research purposes.

---

## 🤝 Contributing

Contributions welcome! Areas for improvement:
- Support for SystemVerilog
- Advanced formal verification
- Multi-module hierarchy generation
- Fine-tuned domain-specific models
- Web-based interface

---

## 📞 Support

For issues or questions:
1. Check logs in `logs/`
2. Review output files for errors
3. Verify tool installations
4. Check API key and credits

---

## 🎓 Citation

If you use this work in research, please cite:

```bibtex
@software{rtl_gen_2025,
  title={Automatic RTL Generation from Natural Language},
  author={Your Name},
  year={2025},
  url={https://github.com/yourusername/rtl-gen}
}
```

---

## 🔮 Future Work

- [ ] SystemVerilog support
- [ ] UVM testbench generation
- [ ] Formal property generation
- [ ] Multi-module designs
- [ ] Fine-tuned LLM for RTL
- [ ] Web-based interface
- [ ] Integration with EDA tools
- [ ] Support for more target libraries

---

**Happy Generating! 🚀**