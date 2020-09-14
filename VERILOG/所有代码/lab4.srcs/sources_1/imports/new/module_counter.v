`timescale 1ns / 1ps

module module_counter(clk, out);
input clk;                    // 计数时钟
output [2:0] out;             // 计数值
reg [2:0] out;				  // 在always语句中对out进行赋值，声明为reg

initial begin
	out = 0;
end

always @(posedge clk)  begin  // 在时钟上升沿计数器加1
                              // 功能实现
	out = out + 1;
end                           
endmodule
