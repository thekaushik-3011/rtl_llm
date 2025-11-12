// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb_riscv_core__Syms.h"


VL_ATTR_COLD void Vtb_riscv_core___024root__trace_init_sub__TOP__0(Vtb_riscv_core___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_riscv_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+73,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"mem_rd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"mem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"mem_wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"byte_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+15,0,"irq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+16,0,"tb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("instr_memory", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 11; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+90,0,"ADDI_X1_X0_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"ADDI_X2_X0_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"ADD_X3_X1_X2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"SW_X3_4_X0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"LW_X4_4_X0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"JAL_X0_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+73,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"mem_rd_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"mem_wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"mem_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"mem_wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"byte_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+15,0,"irq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"pc_current_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"pc_next_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+96,0,"pc_write_enable_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"opcode_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+23,0,"rs1_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"rs2_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"rd_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+76,0,"funct3_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+77,0,"funct7_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+17,0,"imm_i_type_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"imm_s_type_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"imm_b_type_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"imm_u_type_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"imm_j_type_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"immediate_value_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"reg_file_we_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"reg_file_wdata_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"reg_file_rdata1_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"reg_file_rdata2_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"alu_op_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+83,0,"alu_operand1_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"alu_operand2_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"alu_result_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+86,0,"alu_zero_flag_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"pc_sel_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+35,0,"alu_src1_sel_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+36,0,"alu_src2_sel_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+37,0,"mem_to_reg_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+38,0,"imm_gen_sel_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+29,0,"mem_rd_en_ctrl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"mem_wr_en_ctrl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"byte_en_ctrl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"mem_addr_ctrl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"mem_wr_data_ctrl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"irq_taken_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"exception_pc_addr_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"mcause_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"mepc_wdata_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"operand1_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"operand2_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"alu_op_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+85,0,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+86,0,"zero_flag_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"ALU_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+98,0,"ALU_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+99,0,"ALU_SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+100,0,"ALU_SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+101,0,"ALU_SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"ALU_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+103,0,"ALU_SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+104,0,"ALU_SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+105,0,"ALU_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+106,0,"ALU_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+107,0,"ALU_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+85,0,"alu_result_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+13,0,"instruction_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+86,0,"alu_zero_flag_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"irq_taken_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"opcode_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+76,0,"funct3_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+77,0,"funct7_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+23,0,"rs1_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"rs2_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"rd_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+32,0,"reg_file_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"mem_rd_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"mem_wr_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"byte_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"mem_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"mem_wr_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"alu_op_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"alu_src1_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+36,0,"alu_src2_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+37,0,"mem_to_reg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+38,0,"imm_gen_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+34,0,"pc_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+39,0,"current_pc_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"rdata1_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"rdata2_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"immediate_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_irq_ctrl", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+73,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rst_n_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"irq_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"current_pc_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"trap_enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"trap_vector_base_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"irq_taken_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"exception_pc_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"mcause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"mepc_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"pending_irqs_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+21,0,"any_irq_pending_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_pc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+73,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"next_pc_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"pc_write_enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"current_pc_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+73,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"rs1_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"rs2_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"rd_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+80,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"rdata1_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"rdata2_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("registers", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+40+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+72,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+22,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_init_top(Vtb_riscv_core___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_init_top\n"); );
    // Body
    Vtb_riscv_core___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtb_riscv_core___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb_riscv_core___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb_riscv_core___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_register(Vtb_riscv_core___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_riscv_core___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_riscv_core___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_riscv_core___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_riscv_core___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_const_0_sub_0(Vtb_riscv_core___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_const_0\n"); );
    // Init
    Vtb_riscv_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_riscv_core___024root*>(voidSelf);
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_riscv_core___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_const_0_sub_0(Vtb_riscv_core___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+90,(0xa00093U),32);
    bufp->fullIData(oldp+91,(0x1400113U),32);
    bufp->fullIData(oldp+92,(0x2081b3U),32);
    bufp->fullIData(oldp+93,(0x302223U),32);
    bufp->fullIData(oldp+94,(0x402203U),32);
    bufp->fullIData(oldp+95,(0x6fU),32);
    bufp->fullBit(oldp+96,(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_write_enable_w));
    bufp->fullCData(oldp+97,(0U),5);
    bufp->fullCData(oldp+98,(1U),5);
    bufp->fullCData(oldp+99,(2U),5);
    bufp->fullCData(oldp+100,(3U),5);
    bufp->fullCData(oldp+101,(4U),5);
    bufp->fullCData(oldp+102,(5U),5);
    bufp->fullCData(oldp+103,(6U),5);
    bufp->fullCData(oldp+104,(7U),5);
    bufp->fullCData(oldp+105,(8U),5);
    bufp->fullCData(oldp+106,(9U),5);
    bufp->fullCData(oldp+107,(0xaU),5);
    bufp->fullBit(oldp+108,(1U));
    bufp->fullIData(oldp+109,(8U),32);
}

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_full_0_sub_0(Vtb_riscv_core___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_full_0\n"); );
    // Init
    Vtb_riscv_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_riscv_core___024root*>(voidSelf);
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_riscv_core___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_riscv_core___024root__trace_full_0_sub_0(Vtb_riscv_core___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->tb_riscv_core__DOT__instr_memory[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->tb_riscv_core__DOT__instr_memory[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->tb_riscv_core__DOT__instr_memory[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->tb_riscv_core__DOT__instr_memory[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->tb_riscv_core__DOT__instr_memory[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->tb_riscv_core__DOT__instr_memory[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->tb_riscv_core__DOT__instr_memory[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->tb_riscv_core__DOT__instr_memory[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->tb_riscv_core__DOT__instr_memory[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->tb_riscv_core__DOT__instr_memory[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->tb_riscv_core__DOT__instr_memory[10]),32);
    bufp->fullBit(oldp+12,(vlSelf->tb_riscv_core__DOT__rst_n));
    bufp->fullIData(oldp+13,(vlSelf->tb_riscv_core__DOT__instruction),32);
    bufp->fullIData(oldp+14,(vlSelf->tb_riscv_core__DOT__mem_rd_data),32);
    bufp->fullCData(oldp+15,(vlSelf->tb_riscv_core__DOT__irq),8);
    bufp->fullIData(oldp+16,(vlSelf->tb_riscv_core__DOT__tb_pc),32);
    bufp->fullIData(oldp+17,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->tb_riscv_core__DOT__instruction 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+18,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
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
    bufp->fullIData(oldp+19,((0xfffff000U & vlSelf->tb_riscv_core__DOT__instruction)),32);
    bufp->fullIData(oldp+20,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                           >> 0x1fU))) 
                               << 0x14U) | ((0xff000U 
                                             & vlSelf->tb_riscv_core__DOT__instruction) 
                                            | ((0x800U 
                                                & (vlSelf->tb_riscv_core__DOT__instruction 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlSelf->tb_riscv_core__DOT__instruction 
                                                     >> 0x14U)))))),32);
    bufp->fullBit(oldp+21,((0U != (IData)(vlSelf->tb_riscv_core__DOT__irq))));
    bufp->fullIData(oldp+22,(vlSelf->tb_riscv_core__DOT__unnamedblk1__DOT__i),32);
    bufp->fullCData(oldp+23,(vlSelf->tb_riscv_core__DOT__dut__DOT__rs1_addr_w),5);
    bufp->fullCData(oldp+24,(vlSelf->tb_riscv_core__DOT__dut__DOT__rs2_addr_w),5);
    bufp->fullCData(oldp+25,(vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w),5);
    bufp->fullBit(oldp+26,(vlSelf->tb_riscv_core__DOT__dut__DOT__irq_taken_w));
    bufp->fullIData(oldp+27,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_addr_ctrl_w),32);
    bufp->fullIData(oldp+28,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_data_ctrl_w),32);
    bufp->fullBit(oldp+29,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_rd_en_ctrl_w));
    bufp->fullBit(oldp+30,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_wr_en_ctrl_w));
    bufp->fullCData(oldp+31,(vlSelf->tb_riscv_core__DOT__dut__DOT__byte_en_ctrl_w),4);
    bufp->fullBit(oldp+32,(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_we_w));
    bufp->fullCData(oldp+33,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_op_w),5);
    bufp->fullCData(oldp+34,(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w),2);
    bufp->fullCData(oldp+35,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src1_sel_w),2);
    bufp->fullCData(oldp+36,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_src2_sel_w),2);
    bufp->fullCData(oldp+37,(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w),2);
    bufp->fullCData(oldp+38,(vlSelf->tb_riscv_core__DOT__dut__DOT__imm_gen_sel_w),3);
    bufp->fullIData(oldp+39,(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w),32);
    bufp->fullIData(oldp+40,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[0]),32);
    bufp->fullIData(oldp+41,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[1]),32);
    bufp->fullIData(oldp+42,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[2]),32);
    bufp->fullIData(oldp+43,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[3]),32);
    bufp->fullIData(oldp+44,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[4]),32);
    bufp->fullIData(oldp+45,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[5]),32);
    bufp->fullIData(oldp+46,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[6]),32);
    bufp->fullIData(oldp+47,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[7]),32);
    bufp->fullIData(oldp+48,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[8]),32);
    bufp->fullIData(oldp+49,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[9]),32);
    bufp->fullIData(oldp+50,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[10]),32);
    bufp->fullIData(oldp+51,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[11]),32);
    bufp->fullIData(oldp+52,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[12]),32);
    bufp->fullIData(oldp+53,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[13]),32);
    bufp->fullIData(oldp+54,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[14]),32);
    bufp->fullIData(oldp+55,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[15]),32);
    bufp->fullIData(oldp+56,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[16]),32);
    bufp->fullIData(oldp+57,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[17]),32);
    bufp->fullIData(oldp+58,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[18]),32);
    bufp->fullIData(oldp+59,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[19]),32);
    bufp->fullIData(oldp+60,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[20]),32);
    bufp->fullIData(oldp+61,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[21]),32);
    bufp->fullIData(oldp+62,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[22]),32);
    bufp->fullIData(oldp+63,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[23]),32);
    bufp->fullIData(oldp+64,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[24]),32);
    bufp->fullIData(oldp+65,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[25]),32);
    bufp->fullIData(oldp+66,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[26]),32);
    bufp->fullIData(oldp+67,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[27]),32);
    bufp->fullIData(oldp+68,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[28]),32);
    bufp->fullIData(oldp+69,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[29]),32);
    bufp->fullIData(oldp+70,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[30]),32);
    bufp->fullIData(oldp+71,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__registers[31]),32);
    bufp->fullIData(oldp+72,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_regfile__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+73,(vlSelf->tb_riscv_core__DOT__clk));
    bufp->fullIData(oldp+74,(((2U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                               ? ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                                   ? vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w
                                   : vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)
                               : ((1U & (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__pc_sel_w))
                                   ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                                   : ((IData)(4U) + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)))),32);
    bufp->fullCData(oldp+75,(vlSelf->tb_riscv_core__DOT__dut__DOT__opcode_w),7);
    bufp->fullCData(oldp+76,(vlSelf->tb_riscv_core__DOT__dut__DOT__funct3_w),3);
    bufp->fullCData(oldp+77,(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w),7);
    bufp->fullIData(oldp+78,((((- (IData)((vlSelf->tb_riscv_core__DOT__instruction 
                                           >> 0x1fU))) 
                               << 0xcU) | (((IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__funct7_w) 
                                            << 5U) 
                                           | (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__rd_addr_w)))),32);
    bufp->fullIData(oldp+79,(vlSelf->tb_riscv_core__DOT__dut__DOT__immediate_value_w),32);
    bufp->fullIData(oldp+80,(((0U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                               ? vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int
                               : ((1U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                                   ? vlSelf->tb_riscv_core__DOT__mem_rd_data
                                   : ((2U == (IData)(vlSelf->tb_riscv_core__DOT__dut__DOT__mem_to_reg_w))
                                       ? ((IData)(4U) 
                                          + vlSelf->tb_riscv_core__DOT__dut__DOT__pc_current_addr_w)
                                       : 0U)))),32);
    bufp->fullIData(oldp+81,(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata1_w),32);
    bufp->fullIData(oldp+82,(vlSelf->tb_riscv_core__DOT__dut__DOT__reg_file_rdata2_w),32);
    bufp->fullIData(oldp+83,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand1_w),32);
    bufp->fullIData(oldp+84,(vlSelf->tb_riscv_core__DOT__dut__DOT__alu_operand2_w),32);
    bufp->fullIData(oldp+85,(vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int),32);
    bufp->fullBit(oldp+86,((0U == vlSelf->tb_riscv_core__DOT__dut__DOT__u_alu__DOT__alu_result_int)));
    bufp->fullIData(oldp+87,(vlSelf->tb_riscv_core__DOT__dut__DOT__exception_pc_addr_w),32);
    bufp->fullIData(oldp+88,(vlSelf->tb_riscv_core__DOT__dut__DOT__mcause_w),32);
    bufp->fullIData(oldp+89,(vlSelf->tb_riscv_core__DOT__dut__DOT__mepc_wdata_w),32);
}
