`timescale 1ns / 1ps

module sim_datapath();
reg clk,rst,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL;
wire NEXT_ZERO;
wire [7:0] sum_out;
initial begin
	clk <= 0;
	rst <= 1;
	
	#10;
	rst <= 0;
	
	#3;
	LD_SUM <= 0;
	LD_NEXT<=0;
	SUM_SEL<=0;
	NEXT_SEL<=0;
	A_SEL<=0;
	#10;
	LD_SUM <= 1;
	LD_NEXT<=0;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=1;
	#10;
	LD_SUM <= 0;
	LD_NEXT<=1;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=0;
	#10;
	LD_SUM <= 1;
	LD_NEXT<=0;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=1;
	#10;
	LD_SUM <= 0;
	LD_NEXT<=1;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=0;
	#10;
	LD_SUM <= 1;
	LD_NEXT<=0;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=1;
	#10;
	LD_SUM <= 0;
	LD_NEXT<=1;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=0;
	#10;
	LD_SUM <= 1;
	LD_NEXT<=0;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=1;
	#10;
	LD_SUM <= 0;
	LD_NEXT<=1;
	SUM_SEL<=1;
	NEXT_SEL<=1;
	A_SEL<=0;
	
	#10;
	LD_SUM <= 0;
	LD_NEXT<=0;
	SUM_SEL<=0;
	NEXT_SEL<=0;
	A_SEL<=0;
end



always begin
	#5 clk <= ~clk;
end

top_datapath datapath(clk,rst,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,NEXT_ZERO,sum_out);


endmodule