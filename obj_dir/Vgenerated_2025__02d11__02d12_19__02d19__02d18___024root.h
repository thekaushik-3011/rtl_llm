// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vgenerated_2025__02d11__02d12_19__02d19__02d18.h for the primary calling header

#ifndef VERILATED_VGENERATED_2025__02D11__02D12_19__02D19__02D18___024ROOT_H_
#define VERILATED_VGENERATED_2025__02D11__02D12_19__02D19__02D18___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_riscv_core__DOT__clk;
    CData/*0:0*/ tb_riscv_core__DOT__rst_n;
    CData/*7:0*/ tb_riscv_core__DOT__irq;
    CData/*0:0*/ tb_riscv_core__DOT__dut__DOT__pc_write_enable_w;
    CData/*6:0*/ tb_riscv_core__DOT__dut__DOT__opcode_w;
    CData/*4:0*/ tb_riscv_core__DOT__dut__DOT__rs1_addr_w;
    CData/*4:0*/ tb_riscv_core__DOT__dut__DOT__rs2_addr_w;
    CData/*4:0*/ tb_riscv_core__DOT__dut__DOT__rd_addr_w;
    CData/*2:0*/ tb_riscv_core__DOT__dut__DOT__funct3_w;
    CData/*6:0*/ tb_riscv_core__DOT__dut__DOT__funct7_w;
    CData/*0:0*/ tb_riscv_core__DOT__dut__DOT__reg_file_we_w;
    CData/*4:0*/ tb_riscv_core__DOT__dut__DOT__alu_op_w;
    CData/*1:0*/ tb_riscv_core__DOT__dut__DOT__pc_sel_w;
    CData/*1:0*/ tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w;
    CData/*1:0*/ tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w;
    CData/*1:0*/ tb_riscv_core__DOT__dut__DOT__mem_to_reg_w;
    CData/*2:0*/ tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w;
    CData/*0:0*/ tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w;
    CData/*0:0*/ tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w;
    CData/*3:0*/ tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w;
    CData/*0:0*/ tb_riscv_core__DOT__dut__DOT__irq_taken_w;
    CData/*2:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__0;
    CData/*6:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__0;
    CData/*1:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__0;
    CData/*1:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__0;
    CData/*4:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__0;
    CData/*0:0*/ __VstlDidInit;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*2:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w__1;
    CData/*6:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__funct7_w__1;
    CData/*1:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w__1;
    CData/*1:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w__1;
    CData/*4:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__dut__DOT__alu_op_w__1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst_n__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_riscv_core__DOT__instruction;
    IData/*31:0*/ tb_riscv_core__DOT__mem_rd_data;
    IData/*31:0*/ tb_riscv_core__DOT__tb_pc;
    IData/*31:0*/ tb_riscv_core__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__pc_current_addr_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__pc_next_addr_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__immediate_value_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__alu_operand1_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__alu_operand2_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__mcause_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__mepc_wdata_w;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1024> tb_riscv_core__DOT__data_memory;
    VlUnpacked<IData/*31:0*/, 11> tb_riscv_core__DOT__instr_memory;
    VlUnpacked<IData/*31:0*/, 32> tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers;
    VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hdc26a6fe__0;
    VlTriggerVec<5> __VstlTriggered;
    VlTriggerVec<7> __VactTriggered;
    VlTriggerVec<7> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root(Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* symsp, const char* v__name);
    ~Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root();
    VL_UNCOPYABLE(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
