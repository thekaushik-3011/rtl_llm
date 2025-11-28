#!/bin/bash

# RTL Generation Project - Complete Setup Script
# This script sets up all dependencies and tools needed

set -e  # Exit on error

echo "=== RTL Generation Project Setup ==="
echo "This will install all required dependencies..."

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${GREEN}[✓]${NC} $1"
}

print_error() {
    echo -e "${RED}[✗]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[!]${NC} $1"
}

# Check if running on Linux (Ubuntu/Debian)
if [[ "$OSTYPE" != "linux-gnu"* ]]; then
    print_warning "This script is optimized for Ubuntu/Debian Linux"
    print_warning "Some commands may need adjustment for your OS"
fi

# Update system packages
echo ""
echo "Step 1: Updating system packages..."
sudo apt-get update -y
print_status "System packages updated"

# Install essential build tools
echo ""
echo "Step 2: Installing essential build tools..."
sudo apt-get install -y \
    build-essential \
    git \
    wget \
    curl \
    autoconf \
    flex \
    bison \
    help2man \
    perl \
    python3 \
    python3-pip \
    python3-venv \
    gtkwave
print_status "Build tools installed"

# Install Verilator
echo ""
echo "Step 3: Installing Verilator (Verilog simulator)..."
if ! command -v verilator &> /dev/null; then
    sudo apt-get install -y verilator
    print_status "Verilator installed"
else
    print_status "Verilator already installed ($(verilator --version | head -n1))"
fi

# Install Yosys (synthesis tool)
echo ""
echo "Step 4: Installing Yosys (synthesis tool)..."
if ! command -v yosys &> /dev/null; then
    sudo apt-get install -y yosys
    print_status "Yosys installed"
else
    print_status "Yosys already installed ($(yosys -V))"
fi

# Install Icarus Verilog (alternative simulator)
echo ""
echo "Step 5: Installing Icarus Verilog..."
if ! command -v iverilog &> /dev/null; then
    sudo apt-get install -y iverilog
    print_status "Icarus Verilog installed"
else
    print_status "Icarus Verilog already installed"
fi

# Create Python virtual environment
echo ""
echo "Step 6: Creating Python virtual environment..."
python3 -m venv venv
source venv/bin/activate
print_status "Virtual environment created and activated"

# Upgrade pip
pip install --upgrade pip
print_status "pip upgraded"

# Install Python dependencies
echo ""
echo "Step 7: Installing Python dependencies..."
pip install \
    openai \
    anthropic \
    langchain \
    langchain-openai \
    pyyaml \
    jinja2 \
    pyverilog \
    pytest \
    rich \
    click \
    python-dotenv
print_status "Python packages installed"

# Create project directories
echo ""
echo "Step 8: Creating project directories..."
mkdir -p data/{specs/{simple,medium,complex},reference_rtl,testbenches}
mkdir -p output/{generated_rtl,testbenches,simulation_results,synthesis_reports}
mkdir -p config
mkdir -p src
mkdir -p scripts
mkdir -p tests
print_status "Project directories created"

# Create .env file template
echo ""
echo "Step 9: Creating configuration templates..."
cat > .env << 'EOF'
# API Keys
OPENAI_API_KEY=your_openai_api_key_here
ANTHROPIC_API_KEY=your_anthropic_api_key_here

# Model Configuration
DEFAULT_MODEL=gpt-4
TEMPERATURE=0.2
MAX_TOKENS=2000

# Tool Paths
VERILATOR_PATH=/usr/bin/verilator
YOSYS_PATH=/usr/bin/yosys
IVERILOG_PATH=/usr/bin/iverilog

# Project Settings
OUTPUT_DIR=./output
DATA_DIR=./data
LOG_LEVEL=INFO
EOF
print_status ".env template created"

# Create requirements.txt
cat > requirements.txt << 'EOF'
openai>=1.0.0
anthropic>=0.7.0
langchain>=0.1.0
langchain-openai>=0.0.2
pyyaml>=6.0
jinja2>=3.1.2
pyverilog>=1.3.0
pytest>=7.4.0
rich>=13.0.0
click>=8.1.0
python-dotenv>=1.0.0
EOF
print_status "requirements.txt created"

# Verify installations
echo ""
echo "Step 10: Verifying installations..."
echo "Checking tool versions:"
echo "  - Python: $(python3 --version)"
echo "  - Verilator: $(verilator --version | head -n1)"
echo "  - Yosys: $(yosys -V)"
echo "  - Icarus Verilog: $(iverilog -v 2>&1 | head -n1)"

# Final instructions
echo ""
echo "================================================================"
print_status "Setup completed successfully!"
echo "================================================================"
echo ""
echo "Next steps:"
echo "  1. Edit .env file and add your API keys:"
echo "     nano .env"
echo ""
echo "  2. Activate virtual environment:"
echo "     source venv/bin/activate"
echo ""
echo "  3. Run the example:"
echo "     python src/main.py --spec data/specs/simple/counter.json"
echo ""
echo "================================================================"