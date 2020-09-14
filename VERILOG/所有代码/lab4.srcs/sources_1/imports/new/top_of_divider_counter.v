`timescale 1ns / 1ps


module top_of_divider_counter(clk, clk_N);
input clk;                    // 计数时钟
output  clk_N;             // 计数值

module_divider instantiation_of_divider(clk,clk_N);//实例化divider

endmodule
