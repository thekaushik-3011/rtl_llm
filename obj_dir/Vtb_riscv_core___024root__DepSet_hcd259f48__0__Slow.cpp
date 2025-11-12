// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_riscv_core.h for the primary calling header

#include "Vtb_riscv_core__pch.h"
#include "Vtb_riscv_core___024root.h"

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_static(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_initial__TOP(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__instr_memory[0U] = 0xa00093U;
    vlSelf->tb_riscv_core__DOT__instr_memory[1U] = 0x1400113U;
    vlSelf->tb_riscv_core__DOT__instr_memory[2U] = 0x2081b3U;
    vlSelf->tb_riscv_core__DOT__instr_memory[3U] = 0x302223U;
    vlSelf->tb_riscv_core__DOT__instr_memory[4U] = 0x402203U;
    vlSelf->tb_riscv_core__DOT__instr_memory[5U] = 0x6fU;
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_final(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__stl(Vtb_riscv_core___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_riscv_core___024root___eval_phase__stl(Vtb_riscv_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_settle(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_riscv_core___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/testbench_2025-11-12_19-22-32.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_riscv_core___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__stl(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] tb_riscv_core.dut.imm_gen_sel_w or [hybrid] tb_riscv_core.dut.funct7_w)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] tb_riscv_core.dut.alu_src1_sel_w)\n");
    }
    if ((8ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] tb_riscv_core.dut.alu_src2_sel_w)\n");
    }
    if ((0x10ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] tb_riscv_core.dut.alu_op_w)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_riscv_core___024root___stl_sequent__TOP__0(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w 
        = (0x7fU & vlSelf->tb_riscv_core__DOT__instruction);
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w 
        = (7U & (vlSelf->tb_riscv_core__DOT__instruction 
                 >> 0xcU));
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w 
        = (vlSelf->tb_riscv_core__DOT__instruction 
           >> 0x19U);
    vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w = 0U;
    if ((0U != (IData)(vlSelf->tb_riscv_core__DOT__irq))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w 
            = ((1U & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                ? 0x80000000U : ((2U & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                  ? 0x80000001U : (
                                                   (4U 
                                                    & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                                    ? 0x80000002U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                                     ? 0x80000003U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                                      ? 0x80000004U
                                                      : 
                                                     ((0x20U 
                                                       & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                                       ? 0x80000005U
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                                        ? 0x80000006U
                                                        : 
                                                       ((0x80U 
                                                         & (IData)(vlSelf->tb_riscv_core__DOT__irq))
                                                         ? 0x80000007U
                                                         : 0x80000000U))))))));
        vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w 
            = vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w;
        vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w = 8U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w = 1U;
    }
    vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w 
        = (0x1fU & (vlSelf->tb_riscv_core__DOT__instruction 
                    >> 0xfU));
    vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w 
        = (0x1fU & (vlSelf->tb_riscv_core__DOT__instruction 
                    >> 0x14U));
    vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w 
        = (0x1fU & (vlSelf->tb_riscv_core__DOT__instruction 
                    >> 7U));
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w 
        = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w))
            ? 0U : vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers
           [vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w]);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w 
        = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w))
            ? 0U : vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers
           [vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w]);
}

void Vtb_riscv_core___024root___act_comb__TOP__1(Vtb_riscv_core___024root* vlSelf);
void Vtb_riscv_core___024root___act_comb__TOP__2(Vtb_riscv_core___024root* vlSelf);
void Vtb_riscv_core___024root___act_comb__TOP__3(Vtb_riscv_core___024root* vlSelf);
void Vtb_riscv_core___024root___act_comb__TOP__4(Vtb_riscv_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_stl(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_riscv_core___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__1(vlSelf);
    }
    if ((5ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__2(vlSelf);
    }
    if ((0xbULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__3(vlSelf);
    }
    if ((0x1fULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_triggers__stl(Vtb_riscv_core___024root* vlSelf);

VL_ATTR_COLD bool Vtb_riscv_core___024root___eval_phase__stl(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_riscv_core___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_riscv_core___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__act(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] tb_riscv_core.dut.imm_gen_sel_w or [hybrid] tb_riscv_core.dut.funct7_w)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] tb_riscv_core.dut.alu_src1_sel_w)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] tb_riscv_core.dut.alu_src2_sel_w)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] tb_riscv_core.dut.alu_op_w)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge tb_riscv_core.clk or negedge tb_riscv_core.rst_n)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(posedge tb_riscv_core.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__nba(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] tb_riscv_core.dut.imm_gen_sel_w or [hybrid] tb_riscv_core.dut.funct7_w)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] tb_riscv_core.dut.alu_src1_sel_w)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] tb_riscv_core.dut.alu_src2_sel_w)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] tb_riscv_core.dut.alu_op_w)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge tb_riscv_core.clk or negedge tb_riscv_core.rst_n)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(posedge tb_riscv_core.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_riscv_core___024root___ctor_var_reset(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__instruction = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__mem_rd_data = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__irq = VL_RAND_RESET_I(8);
    vlSelf->tb_riscv_core__DOT__tb_pc = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_riscv_core__DOT__data_memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 11; ++__Vi0) {
        vlSelf->tb_riscv_core__DOT__instr_memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_next_addr_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_write_enable_w = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w = VL_RAND_RESET_I(7);
    vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w = VL_RAND_RESET_I(5);
    vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w = VL_RAND_RESET_I(5);
    vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w = VL_RAND_RESET_I(5);
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w = VL_RAND_RESET_I(3);
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w = VL_RAND_RESET_I(7);
    vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = VL_RAND_RESET_I(5);
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = VL_RAND_RESET_I(2);
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = VL_RAND_RESET_I(2);
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = VL_RAND_RESET_I(2);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = VL_RAND_RESET_I(2);
    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = VL_RAND_RESET_I(3);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = VL_RAND_RESET_I(4);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w = VL_RAND_RESET_I(1);
    vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w = VL_RAND_RESET_I(32);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__0 = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__0 = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__0 = VL_RAND_RESET_I(5);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__1 = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__1 = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
