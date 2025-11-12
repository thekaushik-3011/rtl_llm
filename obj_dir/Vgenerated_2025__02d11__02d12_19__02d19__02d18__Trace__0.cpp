// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms.h"


void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_chg_0_sub_0(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_chg_0\n"); );
    // Init
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root*>(voidSelf);
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_chg_0_sub_0(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->tb_riscv_core__DOT__instr_memory[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->tb_riscv_core__DOT__instr_memory[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->tb_riscv_core__DOT__instr_memory[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->tb_riscv_core__DOT__instr_memory[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->tb_riscv_core__DOT__instr_memory[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->tb_riscv_core__DOT__instr_memory[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->tb_riscv_core__DOT__instr_memory[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->tb_riscv_core__DOT__instr_memory[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->tb_riscv_core__DOT__instr_memory[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->tb_riscv_core__DOT__instr_memory[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->tb_riscv_core__DOT__instr_memory[10]),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+11,(vlSelf->tb_riscv_core__DOT__rst_n));
        bufp->chgIData(oldp+12,(vlSelf->tb_riscv_core__DOT__instruction),32);
        bufp->chgIData(oldp+13,(vlSelf->tb_riscv_core__DOT__mem_rd_data),32);
        bufp->chgCData(oldp+14,(vlSelf->tb_riscv_core__DOT__irq),8);
        bufp->chgIData(oldp+15,(vlSelf->tb_riscv_core__DOT__tb_pc),32);
        bufp->chgIData(oldp+16,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->tb_riscv_core__DOT__instruction 
                                              >> 0x14U))),32);
        bufp->chgIData(oldp+17,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0x800U 
                                               & (vlSelf->tb_riscv_core__DOT__instruction 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->tb_riscv_core__DOT__instruction 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->tb_riscv_core__DOT__instruction 
                                                       >> 7U)))))),32);
        bufp->chgIData(oldp+18,((0xfffff000U & vlSelf->tb_riscv_core__DOT__instruction)),32);
        bufp->chgIData(oldp+19,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                              >> 0x1fU))) 
                                  << 0x14U) | ((0xff000U 
                                                & vlSelf->tb_riscv_core__DOT__instruction) 
                                               | ((0x800U 
                                                   & (vlSelf->tb_riscv_core__DOT__instruction 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->tb_riscv_core__DOT__instruction 
                                                        >> 0x14U)))))),32);
        bufp->chgBit(oldp+20,((0U != (IData)(vlSelf->tb_riscv_core__DOT__irq))));
        bufp->chgIData(oldp+21,(vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+22,(vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w),5);
        bufp->chgCData(oldp+23,(vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w),5);
        bufp->chgCData(oldp+24,(vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w),5);
        bufp->chgBit(oldp+25,(vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[4U] 
                     | vlSelf->__Vm_traceActivity[6U]))) {
        bufp->chgIData(oldp+26,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w),32);
        bufp->chgIData(oldp+27,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w),32);
        bufp->chgBit(oldp+28,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w));
        bufp->chgBit(oldp+29,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w));
        bufp->chgCData(oldp+30,(vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w),4);
        bufp->chgBit(oldp+31,(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w));
        bufp->chgCData(oldp+32,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w),5);
        bufp->chgCData(oldp+33,(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w),2);
        bufp->chgCData(oldp+34,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w),2);
        bufp->chgCData(oldp+35,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w),2);
        bufp->chgCData(oldp+36,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w),2);
        bufp->chgCData(oldp+37,(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgIData(oldp+38,(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w),32);
        bufp->chgIData(oldp+39,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0]),32);
        bufp->chgIData(oldp+40,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[1]),32);
        bufp->chgIData(oldp+41,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[2]),32);
        bufp->chgIData(oldp+42,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[3]),32);
        bufp->chgIData(oldp+43,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[4]),32);
        bufp->chgIData(oldp+44,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[5]),32);
        bufp->chgIData(oldp+45,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[6]),32);
        bufp->chgIData(oldp+46,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[7]),32);
        bufp->chgIData(oldp+47,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[8]),32);
        bufp->chgIData(oldp+48,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[9]),32);
        bufp->chgIData(oldp+49,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[10]),32);
        bufp->chgIData(oldp+50,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[11]),32);
        bufp->chgIData(oldp+51,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[12]),32);
        bufp->chgIData(oldp+52,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[13]),32);
        bufp->chgIData(oldp+53,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[14]),32);
        bufp->chgIData(oldp+54,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[15]),32);
        bufp->chgIData(oldp+55,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[16]),32);
        bufp->chgIData(oldp+56,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[17]),32);
        bufp->chgIData(oldp+57,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[18]),32);
        bufp->chgIData(oldp+58,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[19]),32);
        bufp->chgIData(oldp+59,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[20]),32);
        bufp->chgIData(oldp+60,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[21]),32);
        bufp->chgIData(oldp+61,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[22]),32);
        bufp->chgIData(oldp+62,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[23]),32);
        bufp->chgIData(oldp+63,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[24]),32);
        bufp->chgIData(oldp+64,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[25]),32);
        bufp->chgIData(oldp+65,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[26]),32);
        bufp->chgIData(oldp+66,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[27]),32);
        bufp->chgIData(oldp+67,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[28]),32);
        bufp->chgIData(oldp+68,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[29]),32);
        bufp->chgIData(oldp+69,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[30]),32);
        bufp->chgIData(oldp+70,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[31]),32);
        bufp->chgIData(oldp+71,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+72,(vlSelf->tb_riscv_core__DOT__clk));
    bufp->chgIData(oldp+73,(((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                              ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                                  ? vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w
                                  : vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)
                              : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                                  ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                                  : ((IData)(4U) + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)))),32);
    bufp->chgCData(oldp+74,(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w),7);
    bufp->chgCData(oldp+75,(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w),3);
    bufp->chgCData(oldp+76,(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w),7);
    bufp->chgIData(oldp+77,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                          >> 0x1fU))) 
                              << 0xcU) | (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                           << 5U) | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w)))),32);
    bufp->chgIData(oldp+78,(vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w),32);
    bufp->chgIData(oldp+79,(((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                              ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                              : ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                                  ? vlSelf->tb_riscv_core__DOT__mem_rd_data
                                  : ((2U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                                      ? ((IData)(4U) 
                                         + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)
                                      : 0U)))),32);
    bufp->chgIData(oldp+80,(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w),32);
    bufp->chgIData(oldp+81,(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w),32);
    bufp->chgIData(oldp+82,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w),32);
    bufp->chgIData(oldp+83,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w),32);
    bufp->chgIData(oldp+84,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int),32);
    bufp->chgBit(oldp+85,((0U == vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)));
    bufp->chgIData(oldp+86,(vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w),32);
    bufp->chgIData(oldp+87,(vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w),32);
    bufp->chgIData(oldp+88,(vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w),32);
}

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_cleanup\n"); );
    // Init
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root*>(voidSelf);
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
