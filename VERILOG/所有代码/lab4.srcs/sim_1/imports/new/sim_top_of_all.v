`timescale 1ns / 1ps
module sim_top_of_all();
reg clk,rst,start;
wire done;
wire [7:0] sum_out;
wire [7:0] AN;
wire [7:0] SEG;
top_of_all top(clk,rst,start,done,sum_out,SEG,AN);

initial begin
    clk <= 0;
	rst <=1;
	start <= 0;
	
	#10;
	rst <=0;
	start <=1;
end

always 
	#5 clk <= ~clk;

endmodule
