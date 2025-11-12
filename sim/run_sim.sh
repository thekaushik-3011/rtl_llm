#!/bin/bash
set -e

echo "========================================"
echo "Running Verilator Simulation"
echo "========================================"

mkdir -p build
verilator --cc --exe --build -Wall --trace rtl/*.sv tb/*.sv -o build/sim.out
./build/sim.out +trace > sim/sim.log

echo "Simulation complete. Waveform: wave.vcd"
echo "========================================"
