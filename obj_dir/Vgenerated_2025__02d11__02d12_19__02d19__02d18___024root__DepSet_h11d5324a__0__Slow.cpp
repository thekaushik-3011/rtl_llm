// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgenerated_2025__02d11__02d12_19__02d19__02d18.h for the primary calling header

#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__pch.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___dump_triggers__stl(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_triggers__stl(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w) 
                                      != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__0)) 
                                     | ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                        != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__0))));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__0)));
    vlSelf->__VstlTriggered.set(3U, ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__0)));
    vlSelf->__VstlTriggered.set(4U, ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__0)));
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__0 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__0 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__0 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__0 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__0 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
        vlSelf->__VstlTriggered.set(3U, 1U);
        vlSelf->__VstlTriggered.set(4U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
