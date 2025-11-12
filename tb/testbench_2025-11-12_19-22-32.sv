`timescale 1ns/1ps
module tb_riscv_core;
    logic clk;
    logic rst_n;
    logic [31:0] instruction;
    logic [31:0] mem_rd_data;
    logic [31:0] mem_addr;
    logic [31:0] mem_wr_data;
    logic        mem_rd_en;
    logic        mem_wr_en;
    logic [3:0]  byte_en;
    logic [7:0]  irq;
    logic [31:0] tb_pc;
    logic [31:0] data_memory [0:1023];
    logic [31:0] instr_memory [0:10];
    localparam ADDI_X1_X0_10 = 32'h00A00093;
    localparam ADDI_X2_X0_20 = 32'h01400113;
    localparam ADD_X3_X1_X2  = 32'h002081B3;
    localparam SW_X3_4_X0    = 32'h00302223;
    localparam LW_X4_4_X0    = 32'h00402203;
    localparam JAL_X0_0      = 32'h0000006F;
    initial begin
        instr_memory[0] = ADDI_X1_X0_10;
        instr_memory[1] = ADDI_X2_X0_20;
        instr_memory[2] = ADD_X3_X1_X2;
        instr_memory[3] = SW_X3_4_X0;
        instr_memory[4] = LW_X4_4_X0;
        instr_memory[5] = JAL_X0_0;
    end
    riscv_core_top dut (
        .clk             (clk),
        .rst_n           (rst_n),
        .instruction     (instruction),
        .mem_rd_data     (mem_rd_data),
        .mem_addr        (mem_addr),
        .mem_wr_data     (mem_wr_data),
        .mem_rd_en       (mem_rd_en),
        .mem_wr_en       (mem_wr_en),
        .byte_en         (byte_en),
        .irq             (irq)
    );
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    initial begin
        rst_n       = 0;
        instruction = 32'b0;
        mem_rd_data = 32'b0;
        irq         = 8'b0;
        tb_pc       = 32'b0;
        for (int i = 0; i < 1024; i++) begin
            data_memory[i] = 32'hdeadbeef;
        end
        #100;
        rst_n = 1;
        #10;
        repeat (10) @(posedge clk) begin
            if (!rst_n) begin
            end else begin
                instruction = instr_memory[tb_pc / 4];
                if (mem_wr_en) begin
                    if (mem_addr[1:0] != 2'b00) $error("Misaligned memory write to 0x%h!", mem_addr);
                    else if (mem_addr / 4 > 1023) $error("Memory write out of bounds to 0x%h!", mem_addr);
                    else begin
                        data_memory[mem_addr / 4] = mem_wr_data;
                        $display("Time %0t: MEM Write: Addr=0x%h, Data=0x%h", $time, mem_addr, mem_wr_data);
                    end
                end
                if (mem_rd_en) begin
                     if (mem_addr[1:0] != 2'b00) $error("Misaligned memory read from 0x%h!", mem_addr);
                     else if (mem_addr / 4 > 1023) $error("Memory read out of bounds from 0x%h!", mem_addr);
                     else begin
                        mem_rd_data = data_memory[mem_addr / 4];
                        $display("Time %0t: MEM Read: Addr=0x%h, Data=0x%h", $time, mem_addr, mem_rd_data);
                    end
                end else begin
                    mem_rd_data = 32'b0;
                end
                tb_pc = tb_pc + 4;
            end
        end
        #20;
        $display("Time %0t: --- Verification Results ---", $time);
        if (data_memory[1] == 32'd30) begin
            $display("TEST PASSED: Data memory at address 0x00000004 contains expected value 0x%h.", data_memory[1]);
        end else begin
            $display("TEST FAILED: Data memory at address 0x00000004 contains 0x%h, expected 0x%h.", data_memory[1], 32'd30);
        end
        $display("Time %0t: Simulation finished.", $time);
        $finish;
    end
endmodule
