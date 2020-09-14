`timescale 1ns / 1ps


module top_datapath(clk,rst,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,NEXT_ZERO,sum_out);
/*输入端口有：时钟clk，复位rst，加载信号LD_SUM,  LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL
输出端口有: 链尾标志NEXT_ZERO*/
input clk;
input rst;
input LD_SUM;
input LD_NEXT;
input SUM_SEL;
input NEXT_SEL;
input A_SEL;
output NEXT_ZERO;
output [7:0] sum_out;
/*输入、输出端口，均为1位*/

parameter WIDTH = 8;

wire [WIDTH-1:0] wire_1,wire_2,wire_3,wire_4,wire_5,wire_6,wire_7,wire_8,wire_9,wire_10,wire_11;

module_add #WIDTH add1(wire_1,wire_2,wire_3);
//wire_1,wire_2是add1的输入，wire_3是add1的输出

module_mux #WIDTH mux1(wire_3,wire_4,SUM_SEL,wire_5);
//wire_3,wire_4,SUM_SEL是mux1的输入，wire_5是mux1的输出

module_register #WIDTH register1(wire_5,clk,rst,LD_SUM,wire_1);
//wire_5,clk,rst,LD_SUM是register1的输入，wire_1是输出

module_mux #WIDTH mux2(wire_2,wire_6,NEXT_SEL,wire_7);
//wire_2,wire_6,NEXT_SEL是输入，wire_7是输出

module_register #WIDTH register2(wire_7,clk,rst,LD_NEXT,wire_8);

module_add #WIDTH add2(wire_9,wire_8,wire_10);

module_mux #WIDTH mux3(wire_10,wire_8,A_SEL,wire_11);

module_rom #(WIDTH,WIDTH) rom(wire_11,wire_2);

module_com #WIDTH com(wire_7,NEXT_ZERO);

assign wire_4 = 0;
assign wire_6 = 0;
assign wire_9 = 1;

assign sum_out[7:0] = wire_1[7:0];

endmodule
