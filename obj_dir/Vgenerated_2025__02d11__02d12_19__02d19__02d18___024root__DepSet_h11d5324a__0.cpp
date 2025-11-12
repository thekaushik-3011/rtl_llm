// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgenerated_2025__02d11__02d12_19__02d19__02d18.h for the primary calling header

#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__pch.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms.h"
#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root.h"

VL_INLINE_OPT VlCoroutine Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_initial__TOP__Vtiming__1(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSelf->tb_riscv_core__DOT__rst_n = 0U;
    vlSelf->tb_riscv_core__DOT__instruction = 0U;
    vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
    vlSelf->tb_riscv_core__DOT__irq = 0U;
    vlSelf->tb_riscv_core__DOT__tb_pc = 0U;
    vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i)) {
        vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                 & vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i)] = 0xdeadbeefU;
        vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i);
    }
    co_await vlSelf->__VdlySched.delay(0x186a0ULL, 
                                       nullptr, "tb/testbench_2025-11-12_19-22-32.sv", 
                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_riscv_core__DOT__rst_n = 1U;
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                       57);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VtrigSched_hdc26a6fe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_riscv_core.clk)", 
                                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                                       58);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_riscv_core__DOT__rst_n) {
        vlSelf->tb_riscv_core__DOT__instruction = (
                                                   (0xaU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->tb_riscv_core__DOT__instr_memory
                                                   [
                                                   (0xfU 
                                                    & (vlSelf->tb_riscv_core__DOT__tb_pc 
                                                       >> 2U))]
                                                    : 0U);
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:63: Assertion failed in %Ntb_riscv_core: Misaligned memory write to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 63, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:64: Assertion failed in %Ntb_riscv_core: Memory write out of bounds to 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 64, "");
            } else {
                vlSelf->tb_riscv_core__DOT__data_memory[(0x3ffU 
                                                         & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                                            >> 2U))] 
                    = vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
                VL_WRITEF("Time %0t: MEM Write: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w);
            }
        }
        if (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:71: Assertion failed in %Ntb_riscv_core: Misaligned memory read from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 71, "");
            } else if (VL_UNLIKELY((0x3ffU < VL_SHIFTR_III(32,32,32, vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w, 2U)))) {
                VL_WRITEF("[%0t] %%Error: testbench_2025-11-12_19-22-32.sv:72: Assertion failed in %Ntb_riscv_core: Memory read out of bounds from 0x%x!\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w);
                VL_STOP_MT("tb/testbench_2025-11-12_19-22-32.sv", 72, "");
            } else {
                vlSelf->tb_riscv_core__DOT__mem_rd_data 
                    = vlSelf->tb_riscv_core__DOT__data_memory
                    [(0x3ffU & (vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w 
                                >> 2U))];
                VL_WRITEF("Time %0t: MEM Read: Addr=0x%x, Data=0x%x\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w,
                          32,vlSelf->tb_riscv_core__DOT__mem_rd_data);
            }
        } else {
            vlSelf->tb_riscv_core__DOT__mem_rd_data = 0U;
        }
        vlSelf->tb_riscv_core__DOT__tb_pc = ((IData)(4U) 
                                             + vlSelf->tb_riscv_core__DOT__tb_pc);
    }
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "tb/testbench_2025-11-12_19-22-32.sv", 
                                       83);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Time %0t: --- Verification Results ---\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    if ((0x1eU == vlSelf->tb_riscv_core__DOT__data_memory
         [1U])) {
        VL_WRITEF("TEST PASSED: Data memory at address 0x00000004 contains expected value 0x%x.\n",
                  32,vlSelf->tb_riscv_core__DOT__data_memory
                  [1U]);
    } else {
        VL_WRITEF("TEST FAILED: Data memory at address 0x00000004 contains 0x%x, expected 0x0000001e.\n",
                  32,vlSelf->tb_riscv_core__DOT__data_memory
                  [1U]);
    }
    VL_WRITEF("Time %0t: Simulation finished.\n",64,
              VL_TIME_UNITED_Q(1000),-9);
    VL_FINISH_MT("tb/testbench_2025-11-12_19-22-32.sv", 91, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___dump_triggers__act(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);
#endif  // VL_DEBUG

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_triggers__act(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w) 
                                      != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__1)) 
                                     | ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                        != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__1))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__1)));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__1)));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__1)));
    vlSelf->__VactTriggered.set(4U, (((IData)(vlSelf->tb_riscv_core__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_riscv_core__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(5U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(6U, ((IData)(vlSelf->tb_riscv_core__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0))));
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
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
        vlSelf->__VactTriggered.set(2U, 1U);
        vlSelf->__VactTriggered.set(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___dump_triggers__act(vlSelf);
    }
#endif
}
