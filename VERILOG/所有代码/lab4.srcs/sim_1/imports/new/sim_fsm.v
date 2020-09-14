`timescale 1ns / 1ps

module sim_fsm();

reg rst,start,clk_N,next_zero;
wire LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done;

module_FSM FSM(clk_N,rst,start,next_zero,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done);

initial begin
	rst <= 1;
	start <= 0;
	next_zero <= 0;
	clk_N <= 0;
	#3 rst <= 0;
	#10 start <= 1;
	
	#40 next_zero <= 1;
	
	#20 start <= 0;
end

always begin
	#5 clk_N = ~clk_N;
end

endmodule