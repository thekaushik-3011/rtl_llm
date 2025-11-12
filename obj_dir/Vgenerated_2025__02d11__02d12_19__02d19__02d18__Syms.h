// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VGENERATED_2025__02D11__02D12_19__02D19__02D18__SYMS_H_
#define VERILATED_VGENERATED_2025__02D11__02D12_19__02D19__02D18__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18.h"

// INCLUDE MODULE CLASSES
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vgenerated_2025__02d11__02d12_19__02d19__02d18* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_riscv_core;

    // CONSTRUCTORS
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms(VerilatedContext* contextp, const char* namep, Vgenerated_2025__02d11__02d12_19__02d19__02d18* modelp);
    ~Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
