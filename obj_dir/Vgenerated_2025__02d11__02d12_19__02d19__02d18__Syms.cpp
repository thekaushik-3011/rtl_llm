// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__pch.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root.h"

// FUNCTIONS
Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms::~Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms()
{
}

Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms::Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms(VerilatedContext* contextp, const char* namep, Vgenerated_2025__02d11__02d12_19__02d19__02d18* modelp)
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
