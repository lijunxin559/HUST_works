`timescale 1ns / 1ps


module top_of_divider_counter(clk, clk_N);
input clk;                    // ����ʱ��
output  clk_N;             // ����ֵ

module_divider instantiation_of_divider(clk,clk_N);//ʵ����divider

endmodule
