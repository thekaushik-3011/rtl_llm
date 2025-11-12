`timescale 1ns/1ps
// Top-level module for the RISC-V core
module riscv_core_top (
    input logic         clk,
    input logic         rst_n,
    input logic [31:0]  instruction,
    input logic [31:0]  mem_rd_data,
    output logic [31:0] mem_addr,
    output logic [31:0] mem_wr_data,
    output logic        mem_rd_en,
    output logic        mem_wr_en,
    output logic [3:0]  byte_en,
    input logic [7:0]   irq
);
    // Internal Wires and Signals
    // Program Counter
    logic [31:0] pc_current_addr_w;
    logic [31:0] pc_next_addr_w;
    logic        pc_write_enable_w; // Always true for single cycle, but useful for future
    // Instruction Decode & Control Unit
    logic [6:0]  opcode_w;
    logic [4:0]  rs1_addr_w;
    logic [4:0]  rs2_addr_w;
    logic [4:0]  rd_addr_w;
    logic [2:0]  funct3_w;
    logic [6:0]  funct7_w;
    logic [31:0] imm_i_type_w;
    logic [31:0] imm_s_type_w;
    logic [31:0] imm_b_type_w;
    logic [31:0] imm_u_type_w;
    logic [31:0] imm_j_type_w;
    logic [31:0] immediate_value_w;
    logic        reg_file_we_w;
    logic [31:0] reg_file_wdata_w;
    logic [31:0] reg_file_rdata1_w;
    logic [31:0] reg_file_rdata2_w;
    logic [4:0]  alu_op_w;
    logic [31:0] alu_operand1_w;
    logic [31:0] alu_operand2_w;
    logic [31:0] alu_result_w;
    logic        alu_zero_flag_w;
    logic [1:0]  pc_sel_w;        // 0: PC+4, 1: Branch Target, 2: Jump Target, 3: Exception PC
    logic [1:0]  alu_src1_sel_w;  // 0: PC, 1: RegFile Rdata1
    logic [1:0]  alu_src2_sel_w;  // 0: RegFile Rdata2, 1: Immediate, 2: 4 (for PC+4)
    logic [1:0]  mem_to_reg_w;    // 0: ALU Result, 1: Mem Read Data, 2: PC+4 (for JAL/JALR)
    logic [2:0]  imm_gen_sel_w;   // 0: I-type, 1: S-type, 2: B-type, 3: U-type, 4: J-type
    // Memory Interface (from Control Unit)
    logic        mem_rd_en_ctrl_w;
    logic        mem_wr_en_ctrl_w;
    logic [3:0]  byte_en_ctrl_w;
    logic [31:0] mem_addr_ctrl_w;
    logic [31:0] mem_wr_data_ctrl_w;
    // Interrupt Controller
    logic        irq_taken_w;
    logic [31:0] exception_pc_addr_w;
    logic [31:0] mcause_w;
    logic [31:0] mepc_wdata_w;
    // Derived signals for instruction fields
    assign opcode_w = instruction[6:0];
    assign rs1_addr_w = instruction[19:15];
    assign rs2_addr_w = instruction[24:20];
    assign rd_addr_w = instruction[11:7];
    assign funct3_w = instruction[14:12];
    assign funct7_w = instruction[31:25];
    // Immediate Generation (common to Control Unit)
    // I-type
    assign imm_i_type_w = {{20{instruction[31]}}, instruction[31:20]};
    // S-type
    assign imm_s_type_w = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
    // B-type
    assign imm_b_type_w = {{20{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
    // U-type
    assign imm_u_type_w = {instruction[31:12], 12'b0};
    // J-type
    assign imm_j_type_w = {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0};
    always_comb begin
        case (imm_gen_sel_w)
            3'b000: immediate_value_w = imm_i_type_w; // I-type
            3'b001: immediate_value_w = imm_s_type_w; // S-type
            3'b010: immediate_value_w = imm_b_type_w; // B-type
            3'b011: immediate_value_w = imm_u_type_w; // U-type
            3'b100: immediate_value_w = imm_j_type_w; // J-type
            default: immediate_value_w = 32'b0;
        endcase
    end
    // MUX for ALU Operand 1
    always_comb begin
        case (alu_src1_sel_w)
            2'b00: alu_operand1_w = pc_current_addr_w;
            2'b01: alu_operand1_w = reg_file_rdata1_w;
            default: alu_operand1_w = 32'b0;
        endcase
    end
    // MUX for ALU Operand 2
    always_comb begin
        case (alu_src2_sel_w)
            2'b00: alu_operand2_w = reg_file_rdata2_w;
            2'b01: alu_operand2_w = immediate_value_w;
            2'b10: alu_operand2_w = 32'd4; // For PC+4 calculations
            default: alu_operand2_w = 32'b0;
        endcase
    end
    // MUX for Register File Write Data
    always_comb begin
        case (mem_to_reg_w)
            2'b00: reg_file_wdata_w = alu_result_w;     // ALU Result
            2'b01: reg_file_wdata_w = mem_rd_data;      // Memory Read Data
            2'b10: reg_file_wdata_w = pc_current_addr_w + 32'd4; // For JAL/JALR
            default: reg_file_wdata_w = 32'b0;
        endcase
    end
    // MUX for next PC address
    always_comb begin
        case (pc_sel_w)
            2'b00: pc_next_addr_w = pc_current_addr_w + 32'd4; // PC + 4
            2'b01: pc_next_addr_w = alu_result_w;             // Branch Target
            2'b10: pc_next_addr_w = alu_result_w;             // Jump Target (ALU calculates PC + J-type Imm or Rdata1 + I-type Imm)
            2'b11: pc_next_addr_w = exception_pc_addr_w;      // Exception/Interrupt Target
            default: pc_next_addr_w = pc_current_addr_w + 32'd4;
        endcase
    end
    // Connect memory interface outputs
    assign mem_addr = mem_addr_ctrl_w;
    assign mem_wr_data = mem_wr_data_ctrl_w;
    assign mem_rd_en = mem_rd_en_ctrl_w;
    assign mem_wr_en = mem_wr_en_ctrl_w;
    assign byte_en = byte_en_ctrl_w;
    // Submodule Instantiations
    program_counter u_pc (
        .clk             (clk),
        .rst_n           (rst_n),
        .next_pc_addr_i  (pc_next_addr_w),
        .pc_write_enable_i (1'b1), // Always enabled for single-cycle
        .current_pc_addr_o (pc_current_addr_w)
    );
    control_unit u_ctrl (
        .instruction_i     (instruction),
        .alu_zero_flag_i   (alu_zero_flag_w),
        .irq_taken_i       (irq_taken_w),
        .opcode_o          (opcode_w),
        .funct3_o          (funct3_w),
        .funct7_o          (funct7_w),
        .rs1_addr_o        (rs1_addr_w),
        .rs2_addr_o        (rs2_addr_w),
        .rd_addr_o         (rd_addr_w),
        .reg_file_we_o     (reg_file_we_w),
        .mem_rd_en_o       (mem_rd_en_ctrl_w),
        .mem_wr_en_o       (mem_wr_en_ctrl_w),
        .byte_en_o         (byte_en_ctrl_w),
        .mem_addr_o        (mem_addr_ctrl_w),
        .mem_wr_data_o     (mem_wr_data_ctrl_w),
        .alu_op_o          (alu_op_w),
        .alu_src1_sel_o    (alu_src1_sel_w),
        .alu_src2_sel_o    (alu_src2_sel_w),
        .mem_to_reg_o      (mem_to_reg_w),
        .imm_gen_sel_o     (imm_gen_sel_w),
        .pc_sel_o          (pc_sel_w),
        .current_pc_addr_i (pc_current_addr_w),
        .rdata1_i          (reg_file_rdata1_w),
        .rdata2_i          (reg_file_rdata2_w),
        .immediate_i       (immediate_value_w) // Pass immediate to ctrl for mem_addr_o/mem_wr_data_o
    );
    register_file u_regfile (
        .clk             (clk),
        .rst_n           (rst_n),
        .we_i            (reg_file_we_w),
        .rs1_addr_i      (rs1_addr_w),
        .rs2_addr_i      (rs2_addr_w),
        .rd_addr_i       (rd_addr_w),
        .wdata_i         (reg_file_wdata_w),
        .rdata1_o        (reg_file_rdata1_w),
        .rdata2_o        (reg_file_rdata2_w)
    );
    alu u_alu (
        .operand1_i (alu_operand1_w),
        .operand2_i (alu_operand2_w),
        .alu_op_i   (alu_op_w),
        .result_o   (alu_result_w),
        .zero_flag_o (alu_zero_flag_w)
    );
    interrupt_controller u_irq_ctrl (
        .clk_i             (clk),
        .rst_n_i           (rst_n),
        .irq_i             (irq),
        .current_pc_addr_i (pc_current_addr_w),
        .trap_enable_i     (1'b1), // Placeholder: always enable traps for simplicity
        .trap_vector_base_i(32'h00000008), // Placeholder: simple trap vector base
        .irq_taken_o       (irq_taken_w),
        .exception_pc_addr_o (exception_pc_addr_w),
        .mcause_o          (mcause_w),
        .mepc_wdata_o      (mepc_wdata_w)
    );
endmodule
// Program Counter Module
module program_counter (
    input logic        clk,
    input logic        rst_n,
    input logic [31:0] next_pc_addr_i,
    input logic        pc_write_enable_i,
    output logic [31:0] current_pc_addr_o
);
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            current_pc_addr_o <= 32'h00000000; // Reset to start address
        end else if (pc_write_enable_i) begin
            current_pc_addr_o <= next_pc_addr_i;
        end
    end
endmodule
// Control Unit Module
module control_unit (
    input logic [31:0] instruction_i,
    input logic        alu_zero_flag_i,
    input logic        irq_taken_i,
    output logic [6:0] opcode_o,
    output logic [2:0] funct3_o,
    output logic [6:0] funct7_o,
    output logic [4:0] rs1_addr_o,
    output logic [4:0] rs2_addr_o,
    output logic [4:0] rd_addr_o,
    output logic       reg_file_we_o,
    output logic       mem_rd_en_o,
    output logic       mem_wr_en_o,
    output logic [3:0] byte_en_o,
    output logic [31:0] mem_addr_o,
    output logic [31:0] mem_wr_data_o,
    output logic [4:0] alu_op_o,
    output logic [1:0] alu_src1_sel_o,
    output logic [1:0] alu_src2_sel_o,
    output logic [1:0] mem_to_reg_o,
    output logic [2:0] imm_gen_sel_o,
    output logic [1:0] pc_sel_o,
    input logic [31:0] current_pc_addr_i,
    input logic [31:0] rdata1_i,
    input logic [31:0] rdata2_i,
    input logic [31:0] immediate_i // Immediate from top level
);
    // Default values
    always_comb begin
        opcode_o        = instruction_i[6:0];
        funct3_o        = instruction_i[14:12];
        funct7_o        = instruction_i[31:25];
        rs1_addr_o      = instruction_i[19:15];
        rs2_addr_o      = instruction_i[24:20];
        rd_addr_o       = instruction_i[11:7];
        reg_file_we_o   = 1'b0;
        mem_rd_en_o     = 1'b0;
        mem_wr_en_o     = 1'b0;
        byte_en_o       = 4'b0000;
        mem_addr_o      = 32'b0;
        mem_wr_data_o   = 32'b0;
        alu_op_o        = 5'b00000; // Default to ADD
        alu_src1_sel_o  = 2'b01;    // Default: RegFile Rdata1
        alu_src2_sel_o  = 2'b00;    // Default: RegFile Rdata2
        mem_to_reg_o    = 2'b00;    // Default: ALU Result
        imm_gen_sel_o   = 3'b000;   // Default: I-type
        pc_sel_o        = 2'b00;    // Default: PC + 4
        // Handle interrupt overriding normal instruction flow
        if (irq_taken_i) begin
            pc_sel_o        = 2'b11; // Exception PC
            reg_file_we_o   = 1'b0;
            mem_rd_en_o     = 1'b0;
            mem_wr_en_o     = 1'b0;
            alu_op_o        = 5'b00000;
            alu_src1_sel_o  = 2'b00;
            alu_src2_sel_o  = 2'b10; // PC + 4
        end else begin
            // Simplified decoding for common instruction types
            case (opcode_o)
                // R-type (ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU)
                7'b0110011: begin // R-type
                    reg_file_we_o   = 1'b1;
                    alu_src1_sel_o  = 2'b01; // Rdata1
                    alu_src2_sel_o  = 2'b00; // Rdata2
                    mem_to_reg_o    = 2'b00; // ALU Result
                    case ({funct7_o, funct3_o})
                        10'b0000000000: alu_op_o = 5'b00000; // ADD
                        10'b0100000000: alu_op_o = 5'b00001; // SUB
                        10'b0000000001: alu_op_o = 5'b00010; // SLL
                        10'b0000000010: alu_op_o = 5'b00011; // SLT
                        10'b0000000011: alu_op_o = 5'b00100; // SLTU
                        10'b0000000100: alu_op_o = 5'b00101; // XOR
                        10'b0000000101: alu_op_o = 5'b00110; // SRL
                        10'b0100000101: alu_op_o = 5'b00111; // SRA
                        10'b0000000110: alu_op_o = 5'b01000; // OR
                        10'b0000000111: alu_op_o = 5'b01001; // AND
                        default: alu_op_o = 5'b00000; // Default to ADD
                    endcase
                end
                // I-type (ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI, LW)
                7'b0010011: begin // I-type ALU ops
                    reg_file_we_o   = 1'b1;
                    alu_src1_sel_o  = 2'b01; // Rdata1
                    alu_src2_sel_o  = 2'b01; // Immediate
                    mem_to_reg_o    = 2'b00; // ALU Result
                    imm_gen_sel_o   = 3'b000; // I-type
                    case ({funct7_o, funct3_o}) // funct7 for SLLI/SRLI/SRAI, otherwise 0
                        10'b0000000000: alu_op_o = 5'b00000; // ADDI
                        10'b0000000001: alu_op_o = 5'b00010; // SLLI
                        10'b0000000010: alu_op_o = 5'b00011; // SLTI
                        10'b0000000011: alu_op_o = 5'b00100; // SLTIU
                        10'b0000000100: alu_op_o = 5'b00101; // XORI
                        10'b0000000101: alu_op_o = 5'b00110; // SRLI
                        10'b0100000101: alu_op_o = 5'b00111; // SRAI
                        10'b0000000110: alu_op_o = 5'b01000; // ORI
                        10'b0000000111: alu_op_o = 5'b01001; // ANDI
                        default: alu_op_o = 5'b00000; // ADDI
                    endcase
                end
                7'b0000011: begin // LW (I-type Load)
                    reg_file_we_o   = 1'b1;
                    mem_rd_en_o     = 1'b1;
                    byte_en_o       = 4'b1111; // Word access
                    alu_src1_sel_o  = 2'b01; // Rdata1
                    alu_src2_sel_o  = 2'b01; // Immediate
                    alu_op_o        = 5'b00000; // ADD for address calculation
                    mem_to_reg_o    = 2'b01; // Mem Read Data
                    imm_gen_sel_o   = 3'b000; // I-type
                    mem_addr_o      = rdata1_i + immediate_i;
                    // For other load types (LB, LH, LBU, LHU), funct3 would differentiate
                end
                // S-type (SW)
                7'b0100011: begin // SW
                    mem_wr_en_o     = 1'b1;
                    byte_en_o       = 4'b1111; // Word access
                    alu_src1_sel_o  = 2'b01; // Rdata1
                    alu_src2_sel_o  = 2'b01; // Immediate
                    alu_op_o        = 5'b00000; // ADD for address calculation
                    imm_gen_sel_o   = 3'b001; // S-type
                    mem_addr_o      = rdata1_i + immediate_i;
                    mem_wr_data_o   = rdata2_i;
                    // For other store types (SB, SH), funct3 would differentiate
                end
                // B-type (BEQ, BNE, BLT, BGE, BLTU, BGEU)
                7'b1100011: begin // Branch
                    alu_src1_sel_o  = 2'b01; // Rdata1
                    alu_src2_sel_o  = 2'b00; // Rdata2 (for comparison)
                    alu_op_o        = 5'b00001; // SUB for comparison
                    imm_gen_sel_o   = 3'b010; // B-type
                    pc_sel_o        = 2'b00; // Default: PC+4
                    case (funct3_o)
                        3'b000: if (alu_zero_flag_i) pc_sel_o = 2'b01; // BEQ
                        3'b001: if (!alu_zero_flag_i) pc_sel_o = 2'b01; // BNE
                        // Add other branch types later
                        default: pc_sel_o = 2'b00;
                    endcase
                    if (pc_sel_o == 2'b01) begin // If branch taken, calculate target
                        // ALU result will be `current_pc_addr_i + immediate_i` if alu_src1_sel_o is PC and alu_src2_sel_o is immediate
                        // For simplicity, let's assume ALU will compute branch target if taken
                        // This would need PC + Immediate to be fed into ALU, not Rdata1 - Rdata2.
                        // For a single-cycle implementation, this is often handled by a dedicated branch target adder.
                        // To simplify: if branch taken, pc_next_addr_w = current_pc_addr_i + immediate_i
                        mem_addr_o = current_pc_addr_i + immediate_i; // Re-use mem_addr_o for branch target pass-through
                    end
                end
                // U-type (LUI, AUIPC)
                7'b0110111: begin // LUI
                    reg_file_we_o   = 1'b1;
                    alu_src1_sel_o  = 2'b01; // Placeholder, not used for LUI direct load
                    alu_src2_sel_o  = 2'b01; // Immediate
                    alu_op_o        = 5'b01010; // LUI specific operation or just pass immediate
                    mem_to_reg_o    = 2'b00; // ALU Result
                    imm_gen_sel_o   = 3'b011; // U-type
                end
                7'b0010111: begin // AUIPC
                    reg_file_we_o   = 1'b1;
                    alu_src1_sel_o  = 2'b00; // PC
                    alu_src2_sel_o  = 2'b01; // Immediate
                    alu_op_o        = 5'b00000; // ADD
                    mem_to_reg_o    = 2'b00; // ALU Result
                    imm_gen_sel_o   = 3'b011; // U-type
                end
                // J-type (JAL)
                7'b1101111: begin // JAL
                    reg_file_we_o   = 1'b1;
                    alu_src1_sel_o  = 2'b00; // PC
                    alu_src2_sel_o  = 2'b01; // Immediate
                    alu_op_o        = 5'b00000; // ADD (for target calculation)
                    mem_to_reg_o    = 2'b10; // PC+4 for RegFile write
                    imm_gen_sel_o   = 3'b100; // J-type
                    pc_sel_o        = 2'b10; // Jump Target
                end
                // I-type (JALR)
                7'b1100111: begin // JALR
                    reg_file_we_o   = 1'b1;
                    alu_src1_sel_o  = 2'b01; // Rdata1
                    alu_src2_sel_o  = 2'b01; // Immediate
                    alu_op_o        = 5'b00000; // ADD (for target calculation)
                    mem_to_reg_o    = 2'b10; // PC+4 for RegFile write
                    imm_gen_sel_o   = 3'b000; // I-type
                    pc_sel_o        = 2'b10; // Jump Target
                end
                default: begin
                    // Default values already set at the beginning of always_comb
                end
            endcase
        end
        // For branches, when pc_sel_o indicates a branch,
        // the ALU needs to compute pc_current_addr_i + immediate_i to determine the target.
        // This is a simplification for Step 0, in a real design, there would be a dedicated
        // adder for branch target calculation or the ALU would be configured for it.
        // For the branch condition (BEQ/BNE), the ALU already computes rdata1_i - rdata2_i.
        // If a branch is taken, the pc_next_addr_w MUX should select pc_current_addr_i + immediate_i.
        // For simplicity, `mem_addr_o` is overloaded here to pass the branch target temporarily.
        if (pc_sel_o == 2'b01 && alu_zero_flag_i == 1'b1) begin // BEQ simplified check
             mem_addr_o = current_pc_addr_i + immediate_i;
        end else if (pc_sel_o == 2'b01 && alu_zero_flag_i == 1'b0) begin // BNE simplified check
             mem_addr_o = current_pc_addr_i + immediate_i;
        end
    end
endmodule
// Register File Module
module register_file (
    input logic        clk,
    input logic        rst_n,
    input logic        we_i, // Write Enable
    input logic [4:0]  rs1_addr_i,
    input logic [4:0]  rs2_addr_i,
    input logic [4:0]  rd_addr_i,
    input logic [31:0] wdata_i,
    output logic [31:0] rdata1_o,
    output logic [31:0] rdata2_o
);
    logic [31:0] registers[31:0];
    // Read ports (combinational)
    assign rdata1_o = (rs1_addr_i == 5'b0) ? 32'b0 : registers[rs1_addr_i];
    assign rdata2_o = (rs2_addr_i == 5'b0) ? 32'b0 : registers[rs2_addr_i];
    // Write port (sequential)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < 32; i++) begin
                registers[i] <= 32'b0;
            end
        end else if (we_i && (rd_addr_i != 5'b0)) begin // x0 is hardwired to 0, cannot be written
            registers[rd_addr_i] <= wdata_i;
        end
    end
endmodule
// ALU Module (Arithmetic Logic Unit)
module alu (
    input logic [31:0] operand1_i,
    input logic [31:0] operand2_i,
    input logic [4:0]  alu_op_i,
    output logic [31:0] result_o,
    output logic       zero_flag_o
);
    parameter ALU_ADD  = 5'b00000;
    parameter ALU_SUB  = 5'b00001;
    parameter ALU_SLL  = 5'b00010;
    parameter ALU_SLT  = 5'b00011;
    parameter ALU_SLTU = 5'b00100;
    parameter ALU_XOR  = 5'b00101;
    parameter ALU_SRL  = 5'b00110;
    parameter ALU_SRA  = 5'b00111;
    parameter ALU_OR   = 5'b01000;
    parameter ALU_AND  = 5'b01001;
    parameter ALU_LUI  = 5'b01010; // For LUI, just pass operand2_i (immediate)
    logic [31:0] alu_result_int;
    always_comb begin
        alu_result_int = 32'b0; // Default
        case (alu_op_i)
            ALU_ADD:  alu_result_int = operand1_i + operand2_i;
            ALU_SUB:  alu_result_int = operand1_i - operand2_i;
            ALU_SLL:  alu_result_int = operand1_i << operand2_i[4:0]; // Shift amount is 5 bits
            ALU_SLT:  alu_result_int = ($signed(operand1_i) < $signed(operand2_i)) ? 32'b1 : 32'b0;
            ALU_SLTU: alu_result_int = (operand1_i < operand2_i) ? 32'b1 : 32'b0;
            ALU_XOR:  alu_result_int = operand1_i ^ operand2_i;
            ALU_SRL:  alu_result_int = operand1_i >> operand2_i[4:0];
            ALU_SRA:  alu_result_int = $signed(operand1_i) >>> operand2_i[4:0];
            ALU_OR:   alu_result_int = operand1_i | operand2_i;
            ALU_AND:  alu_result_int = operand1_i & operand2_i;
            ALU_LUI:  alu_result_int = operand2_i; // For LUI, the immediate value is the result
            default:  alu_result_int = 32'b0;
        endcase
    end
    assign result_o = alu_result_int;
    assign zero_flag_o = (alu_result_int == 32'b0);
endmodule
// Interrupt Controller Module
module interrupt_controller (
    input logic        clk_i,
    input logic        rst_n_i,
    input logic [7:0]  irq_i,
    input logic [31:0] current_pc_addr_i,
    input logic        trap_enable_i, // Simplified: Master Interrupt Enable
    input logic [31:0] trap_vector_base_i, // MTVEC equivalent
    output logic       irq_taken_o,
    output logic [31:0] exception_pc_addr_o,
    output logic [31:0] mcause_o, // Machine Cause register
    output logic [31:0] mepc_wdata_o // Machine Exception Program Counter
);
    logic [7:0] pending_irqs_w;
    logic       any_irq_pending_w;
    // Detect pending IRQs (level-sensitive for simplicity)
    assign pending_irqs_w = irq_i;
    assign any_irq_pending_w = |pending_irqs_w;
    // Determine if an IRQ should be taken
    always_comb begin
        irq_taken_o = 1'b0;
        exception_pc_addr_o = 32'b0;
        mcause_o = 32'b0;
        mepc_wdata_o = 32'b0;
        if (trap_enable_i && any_irq_pending_w) begin
            irq_taken_o = 1'b1;
            // For simplicity, take the highest priority (lowest index) IRQ
            // In a real system, there'd be priority encoder and MIE/MPP/MSTATUS logic
            if (pending_irqs_w[0]) mcause_o = 32'h80000000; // IRQ 0
            else if (pending_irqs_w[1]) mcause_o = 32'h80000001; // IRQ 1
            else if (pending_irqs_w[2]) mcause_o = 32'h80000002; // IRQ 2
            else if (pending_irqs_w[3]) mcause_o = 32'h80000003; // IRQ 3
            else if (pending_irqs_w[4]) mcause_o = 32'h80000004; // IRQ 4
            else if (pending_irqs_w[5]) mcause_o = 32'h80000005; // IRQ 5
            else if (pending_irqs_w[6]) mcause_o = 32'h80000006; // IRQ 6
            else if (pending_irqs_w[7]) mcause_o = 32'h80000007; // IRQ 7
            else mcause_o = 32'h80000000; // Default for any pending
            exception_pc_addr_o = trap_vector_base_i;
            mepc_wdata_o = current_pc_addr_i; // Save current PC for MRET
        end
    end
endmodule
