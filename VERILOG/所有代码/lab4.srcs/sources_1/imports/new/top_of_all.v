`timescale 1ns / 1ps

module top_of_all(clk,rst,start,done,sum_out,SEG,AN);
input clk,rst,start;
output done;
output [7:0] sum_out;
output [7:0] SEG;
output [7:0] AN;
wire clk_N;
parameter WIDTH = 8;
reg ccount;
reg [31:0] cnt1;
wire [WIDTH-1:0] big_sum_out;

wire next_zero,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL;
module_divider dividerr(clk, clk_N);
module_FSM FSM(clk,rst,start,next_zero,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done);

top_datapath #WIDTH datapath(clk,rst,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,next_zero,big_sum_out);
initial
    begin
	ccount=0;
	cnt1=0;
    end
always @(posedge clk)
    begin
	if(cnt1==500000)
	    begin
		cnt1=0;
		#1 ccount=~ccount;
	    end
	else
	    begin
		cnt1=cnt1+1;
	    end
    end
assign sum_out=big_sum_out[7:0];


assign AN[7:2]=6'b111111;
assign AN[0]=~ccount;
assign AN[1]=ccount;
assign SEG[0]=(~ccount)&(big_sum_out==8'b00001100);
assign SEG[1]=(ccount)&(big_sum_out==8'b00000110);
assign SEG[2]=((~ccount)&(big_sum_out==8'b00010100))|(ccount&((big_sum_out==8'b00000010)|(big_sum_out==8'b00001100)));
assign SEG[3]=(~ccount)&(big_sum_out==8'b00001100);
assign SEG[4]=(~ccount)&(big_sum_out==8'b00001100);
assign SEG[5]=((ccount)&((big_sum_out==8'b00000010)|(big_sum_out==8'b00001100)))|((~ccount)&((big_sum_out==8'b00001100)|(big_sum_out==8'b00010100)));
assign SEG[6]=~((ccount&((big_sum_out==8'b00000010)|(big_sum_out==8'b00000110)|(big_sum_out==8'b00001100)))|((~ccount)&(big_sum_out==8'b00010100)));
assign SEG[7]=1;

endmodule
