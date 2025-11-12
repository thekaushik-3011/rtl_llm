// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_riscv_core__pch.h"
#include "Vtb_riscv_core.h"
#include "Vtb_riscv_core___024root.h"

// FUNCTIONS
Vtb_riscv_core__Syms::~Vtb_riscv_core__Syms()
{
}

Vtb_riscv_core__Syms::Vtb_riscv_core__Syms(VerilatedContext* contextp, const char* namep, Vtb_riscv_core* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_riscv_core.configure(this, name(), "tb_riscv_core", "tb_riscv_core", -9, VerilatedScope::SCOPE_OTHER);
}
