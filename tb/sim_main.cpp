#include "Vtb_riscv_core.h"
#include "verilated.h"
#include "verilated_fst_c.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtb_riscv_core *tb = new Vtb_riscv_core;
    VerilatedFstC *tfp = new VerilatedFstC;
    tb->trace(tfp, 99);
    tfp->open("waveform.fst");

    // Just evaluate repeatedly; clock toggling is done inside SV testbench
    for (int i = 0; i < 1000 && !Verilated::gotFinish(); i++) {
        tb->eval();
        tfp->dump(i * 10);
    }

    tfp->close();
    delete tb;
    return 0;
}
