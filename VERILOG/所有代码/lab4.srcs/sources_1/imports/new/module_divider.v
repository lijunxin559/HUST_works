`timescale 1ns / 1ps


module module_divider(clk, clk_N);
input clk;                      // 系统时钟
output clk_N;                   // 分频后的时钟
parameter N = 100_000_000;      // 1Hz的时钟,N=fclk/fclk_N
reg [31:0] counter;             /* 计数器变量，通过计数实现分频。
                                   当计数器从0计数到(N/2-1)时，
                                   输出时钟翻转，计数器清零 */
reg clk_N;						//在always语句中对clk_N赋值，声明为reg
								   
initial begin
	counter = 0;
end

always @(posedge clk)begin    // 时钟上升沿
    // 功能实现
	if(counter == ((N/2)-1))
		begin
		clk_N = ~ clk_N;		//输出时钟翻转
		counter = 0;		//计数器清零
		end
	else
		begin
		counter = counter + 1;//计数器加一
		end
end                           
endmodule

