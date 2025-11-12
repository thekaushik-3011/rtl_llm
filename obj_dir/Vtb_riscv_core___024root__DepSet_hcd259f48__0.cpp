// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_riscv_core.h for the primary calling header

#include "Vtb_riscv_core__pch.h"
#include "Vtb_riscv_core___024root.h"

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_initial__TOP(Vtb_riscv_core___024root* vlSelf);
VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_riscv_core___024root* vlSelf);
VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1(Vtb_riscv_core___024root* vlSelf);

void Vtb_riscv_core___024root___eval_initial(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial\n"); );
    // Body
    Vtb_riscv_core___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1(vlSelf);
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
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__1 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__1 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__1 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__1 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__1 
        = vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0 
        = vlSelf->tb_riscv_core__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst_n__0 
        = vlSelf->tb_riscv_core__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/testbench_2025-11-12_19-22-32.sv", 
                                           44);
        vlSelf->tb_riscv_core__DOT__clk = (1U & (~ (IData)(vlSelf->tb_riscv_core__DOT__clk)));
    }
}

VL_INLINE_OPT void Vtb_riscv_core___024root___act_comb__TOP__0(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w 
        = (0x7fU & vlSelf->tb_riscv_core__DOT__instruction);
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w 
        = (7U & (vlSelf->tb_riscv_core__DOT__instruction 
                 >> 0xcU));
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w 
        = (vlSelf->tb_riscv_core__DOT__instruction 
           >> 0x19U);
    vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w = 0U;
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

VL_INLINE_OPT void Vtb_riscv_core___024root___act_comb__TOP__1(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___act_comb__TOP__1\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w 
        = ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w))
            ? ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w))
                ? 0U : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w))
                         ? 0U : (((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                              >> 0x1fU))) 
                                  << 0x14U) | ((0xff000U 
                                                & vlSelf->tb_riscv_core__DOT__instruction) 
                                               | ((0x800U 
                                                   & (vlSelf->tb_riscv_core__DOT__instruction 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->tb_riscv_core__DOT__instruction 
                                                        >> 0x14U)))))))
            : ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w))
                ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w))
                    ? (0xfffff000U & vlSelf->tb_riscv_core__DOT__instruction)
                    : (((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->tb_riscv_core__DOT__instruction 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->tb_riscv_core__DOT__instruction 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->tb_riscv_core__DOT__instruction 
                                                      >> 7U))))))
                : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w))
                    ? (((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                    >> 0x1fU))) << 0xcU) 
                       | (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                           << 5U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w)))
                    : (((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->tb_riscv_core__DOT__instruction 
                          >> 0x14U)))));
}

VL_INLINE_OPT void Vtb_riscv_core___024root___act_comb__TOP__2(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___act_comb__TOP__2\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
        = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w))
            ? vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w
            : ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w))
                ? vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w
                : 0U));
}

VL_INLINE_OPT void Vtb_riscv_core___024root___act_comb__TOP__3(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___act_comb__TOP__3\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w 
        = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w))
            ? vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w
            : ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w))
                ? vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w
                : ((2U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w))
                    ? 4U : 0U)));
}

VL_INLINE_OPT void Vtb_riscv_core___024root___act_comb__TOP__4(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___act_comb__TOP__4\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int 
        = ((0x10U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
            ? 0U : ((8U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                     ? ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                         ? 0U : ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                  ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                      ? 0U : vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                  : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                      ? (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                         & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                      : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                         | vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w))))
                     : ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                         ? ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                             ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                 ? VL_SHIFTRS_III(32,32,5, vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w, 
                                                  (0x1fU 
                                                   & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w))
                                 : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                    >> (0x1fU & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)))
                             : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                 ? (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                    ^ vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                 : ((vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                     < vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                     ? 1U : 0U))) : 
                        ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                          ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                              ? (VL_LTS_III(32, vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w, vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                  ? 1U : 0U) : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                                << 
                                                (0x1fU 
                                                 & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)))
                          : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                              ? (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                 - vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                              : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                 + vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w))))));
    vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w 
        = (0x7fU & vlSelf->tb_riscv_core__DOT__instruction);
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w 
        = (7U & (vlSelf->tb_riscv_core__DOT__instruction 
                 >> 0xcU));
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w 
        = (vlSelf->tb_riscv_core__DOT__instruction 
           >> 0x19U);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 0U;
    if (vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 3U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 2U;
    } else if ((0x40U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
        if ((0x20U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
            if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                            if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                                vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 0U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 2U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 4U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 2U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 2U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 2U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 0U;
                        if ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) {
                            if ((0U == vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)) {
                                vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 1U;
                            }
                        } else if ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) {
                            if ((0U != vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)) {
                                vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 1U;
                            }
                        } else {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 0U;
                        }
                        if ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))) {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                = (vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
                                   + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
                        }
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
        if ((0x10U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
            if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0xaU;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w 
                            = (((((((((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) 
                                      | (0x100U == 
                                         (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                     | (1U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                << 3U) 
                                               | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                    | (2U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                   | (3U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                              << 3U) 
                                             | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                  | (4U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                             << 3U) 
                                            | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                 | (5U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                | (0x105U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))))
                                ? ((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                    ? 0U : ((0x100U 
                                             == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                             ? 1U : 
                                            ((1U == 
                                              (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                << 3U) 
                                               | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                              ? 2U : 
                                             ((2U == 
                                               (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                 << 3U) 
                                                | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                               ? 3U
                                               : ((3U 
                                                   == 
                                                   (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                     << 3U) 
                                                    | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                       << 3U) 
                                                      | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                     ? 6U
                                                     : 7U)))))))
                                : ((6U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                    ? 8U : ((7U == 
                                             (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                             ? 9U : 0U)));
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = 0xfU;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                            = (vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w 
                               + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w 
                            = vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w;
                    }
                }
            }
        }
    } else if ((0x10U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
        if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 3U;
                    }
                }
            } else if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w 
                        = (((((((((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) 
                                  | (1U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                             << 3U) 
                                            | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                 | (2U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                | (3U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                               | (4U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                          << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                              | (5U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                         << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                             | (0x105U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                            | (6U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                       << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))))
                            ? ((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                        << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                ? 0U : ((1U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                 << 3U) 
                                                | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                         ? 2U : ((2U 
                                                  == 
                                                  (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                    << 3U) 
                                                   | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                  ? 3U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                     << 3U) 
                                                    | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                       << 3U) 
                                                      | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                     ? 6U
                                                     : 
                                                    ((0x105U 
                                                      == 
                                                      (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                        << 3U) 
                                                       | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                      ? 7U
                                                      : 8U)))))))
                            : ((7U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                        << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                ? 9U : 0U));
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = 0xfU;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                        = (vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w 
                           + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
                }
            }
        }
    }
    if (((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w)) 
         & (0U == vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
            = (vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
               + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
    } else if (((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w)) 
                & (0U != vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
            = (vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
               + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
    }
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_next_addr_w 
        = ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
            ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                ? vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w
                : vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)
            : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                : ((IData)(4U) + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)));
}

void Vtb_riscv_core___024root___eval_act(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_act\n"); );
    // Body
    if ((0x60ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((0x61ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0x62ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__2(vlSelf);
    }
    if ((0x65ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__3(vlSelf);
    }
    if ((0x6fULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_riscv_core___024root___nba_sequent__TOP__0(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0;
    __Vdlyvdim0__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0;
    __Vdlyvval__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0;
    __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v1;
    __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v1 = 0;
    // Body
    __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 = 0U;
    __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v1 = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_riscv_core__DOT__rst_n)))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        if (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w) 
             & (0U != (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w)))) {
            __Vdlyvval__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 
                = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                    ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                    : ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                        ? vlSelf->tb_riscv_core__DOT__mem_rd_data
                        : ((2U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                            ? ((IData)(4U) + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)
                            : 0U)));
            __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 = 1U;
            __Vdlyvdim0__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0 
                = vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w;
        }
        vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
            = vlSelf->tb_riscv_core__DOT__dut__DOT__pc_next_addr_w;
    } else {
        __Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v1 = 1U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w = 0U;
    }
    if (__Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[__Vdlyvdim0__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0] 
            = __Vdlyvval__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v0;
    }
    if (__Vdlyvset__tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers__v1) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[1U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[2U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[3U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[4U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[5U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[6U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[7U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[8U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[9U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0xaU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0xbU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0xcU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0xdU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0xeU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0xfU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x10U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x11U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x12U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x13U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x14U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x15U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x16U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x17U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x18U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x19U] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x1aU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x1bU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x1cU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x1dU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x1eU] = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0x1fU] = 0U;
    }
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w 
        = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w))
            ? 0U : vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers
           [vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w]);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w 
        = ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w))
            ? 0U : vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers
           [vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w]);
}

VL_INLINE_OPT void Vtb_riscv_core___024root___nba_comb__TOP__0(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w = 0U;
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
        vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w = 8U;
    }
}

VL_INLINE_OPT void Vtb_riscv_core___024root___nba_comb__TOP__2(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___nba_comb__TOP__2\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w = 0U;
    if ((0U != (IData)(vlSelf->tb_riscv_core__DOT__irq))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w 
            = vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w;
    }
}

VL_INLINE_OPT void Vtb_riscv_core___024root___nba_comb__TOP__4(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___nba_comb__TOP__4\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int 
        = ((0x10U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
            ? 0U : ((8U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                     ? ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                         ? 0U : ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                  ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                      ? 0U : vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                  : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                      ? (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                         & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                      : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                         | vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w))))
                     : ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                         ? ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                             ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                 ? VL_SHIFTRS_III(32,32,5, vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w, 
                                                  (0x1fU 
                                                   & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w))
                                 : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                    >> (0x1fU & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)))
                             : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                                 ? (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                    ^ vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                 : ((vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                     < vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                     ? 1U : 0U))) : 
                        ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                          ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                              ? (VL_LTS_III(32, vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w, vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                                  ? 1U : 0U) : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                                << 
                                                (0x1fU 
                                                 & vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)))
                          : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w))
                              ? (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                 - vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w)
                              : (vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w 
                                 + vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w))))));
}

VL_INLINE_OPT void Vtb_riscv_core___024root___nba_comb__TOP__5(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___nba_comb__TOP__5\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w 
        = (0x7fU & vlSelf->tb_riscv_core__DOT__instruction);
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w 
        = (7U & (vlSelf->tb_riscv_core__DOT__instruction 
                 >> 0xcU));
    vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w 
        = (vlSelf->tb_riscv_core__DOT__instruction 
           >> 0x19U);
    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 0U;
    if (vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 3U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 0U;
        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 2U;
    } else if ((0x40U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
        if ((0x20U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
            if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                            if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                                vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 0U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 2U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 4U;
                                vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 2U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 2U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 2U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 0U;
                        if ((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) {
                            if ((0U == vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)) {
                                vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 1U;
                            }
                        } else if ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) {
                            if ((0U != vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)) {
                                vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 1U;
                            }
                        } else {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w = 0U;
                        }
                        if ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))) {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                = (vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
                                   + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
                        }
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
        if ((0x10U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
            if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                            vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0xaU;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                            vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w 
                            = (((((((((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) 
                                      | (0x100U == 
                                         (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                     | (1U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                << 3U) 
                                               | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                    | (2U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                   | (3U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                              << 3U) 
                                             | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                  | (4U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                             << 3U) 
                                            | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                 | (5U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                | (0x105U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))))
                                ? ((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                    ? 0U : ((0x100U 
                                             == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                             ? 1U : 
                                            ((1U == 
                                              (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                << 3U) 
                                               | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                              ? 2U : 
                                             ((2U == 
                                               (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                 << 3U) 
                                                | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                               ? 3U
                                               : ((3U 
                                                   == 
                                                   (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                     << 3U) 
                                                    | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                       << 3U) 
                                                      | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                     ? 6U
                                                     : 7U)))))))
                                : ((6U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                    ? 8U : ((7U == 
                                             (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                               << 3U) 
                                              | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                             ? 9U : 0U)));
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = 0xfU;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                            = (vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w 
                               + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w 
                            = vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w;
                    }
                }
            }
        }
    } else if ((0x10U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
        if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                        vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                        vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 3U;
                    }
                }
            } else if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w 
                        = (((((((((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))) 
                                  | (1U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                             << 3U) 
                                            | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                 | (2U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                                | (3U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                               | (4U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                          << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                              | (5U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                         << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                             | (0x105U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))) 
                            | (6U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                       << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w))))
                            ? ((0U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                        << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                ? 0U : ((1U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                 << 3U) 
                                                | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                         ? 2U : ((2U 
                                                  == 
                                                  (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                    << 3U) 
                                                   | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                  ? 3U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                     << 3U) 
                                                    | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                       << 3U) 
                                                      | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                     ? 6U
                                                     : 
                                                    ((0x105U 
                                                      == 
                                                      (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                                        << 3U) 
                                                       | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                                      ? 7U
                                                      : 8U)))))))
                            : ((7U == (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                        << 3U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w)))
                                ? 9U : 0U));
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                if ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w))) {
                    vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w = 0xfU;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w = 1U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w = 0U;
                    vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                        = (vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w 
                           + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
                }
            }
        }
    }
    if (((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w)) 
         & (0U == vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
            = (vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
               + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
    } else if (((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w)) 
                & (0U != vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int))) {
        vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
            = (vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w 
               + vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w);
    }
    vlSelf->tb_riscv_core__DOT__dut__DOT__pc_next_addr_w 
        = ((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
            ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                ? vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w
                : vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)
            : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                : ((IData)(4U) + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)));
}

void Vtb_riscv_core___024root___eval_nba(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_nba\n"); );
    // Body
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((0x60ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x14ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__3(vlSelf);
    }
    if ((0x70ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x12ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___act_comb__TOP__2(vlSelf);
    }
    if ((0x1eULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x7eULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_riscv_core___024root___nba_comb__TOP__5(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
}

void Vtb_riscv_core___024root___timing_resume(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___timing_resume\n"); );
    // Body
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hdc26a6fe__0.resume("@(posedge tb_riscv_core.clk)");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_riscv_core___024root___timing_commit(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___timing_commit\n"); );
    // Body
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hdc26a6fe__0.commit("@(posedge tb_riscv_core.clk)");
    }
}

void Vtb_riscv_core___024root___eval_triggers__act(Vtb_riscv_core___024root* vlSelf);

bool Vtb_riscv_core___024root___eval_phase__act(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<7> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_riscv_core___024root___eval_triggers__act(vlSelf);
    Vtb_riscv_core___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_riscv_core___024root___timing_resume(vlSelf);
        Vtb_riscv_core___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_riscv_core___024root___eval_phase__nba(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_riscv_core___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__nba(Vtb_riscv_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__act(Vtb_riscv_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_riscv_core___024root___eval(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_riscv_core___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/testbench_2025-11-12_19-22-32.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_riscv_core___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/testbench_2025-11-12_19-22-32.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_riscv_core___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_riscv_core___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_riscv_core___024root___eval_debug_assertions(Vtb_riscv_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
