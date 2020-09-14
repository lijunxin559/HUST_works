`timescale 1ns / 1ps


module module_FSM(clk,rst,start,next_zero,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done);

input clk,rst,start,next_zero;
output LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done;
reg [1:0] State,StateNext;

parameter S_start = 0,S_computer_sum=1,S_get_next=2,S_done = 3;
//4¸ö×´Ì¬


reg LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done;

initial begin
	State <= S_start;
end

always @(posedge clk)
begin
	if(rst == 1)
		State <= S_start;
	else
		State <= StateNext;
end	

always @(State,start,next_zero)
begin

	case(State)
	S_start:begin
		LD_SUM<=0;
		LD_NEXT<=0;
		SUM_SEL<=0;
		NEXT_SEL<=0;
		A_SEL<=0;
		done<=0;
		if(start==0)
			StateNext<=S_start;
		else if (start == 1)
			StateNext<=S_computer_sum;
		end
	S_computer_sum:begin
		LD_SUM<=1;
		LD_NEXT<=0;
		SUM_SEL<=1;
		NEXT_SEL<=1;
		A_SEL<=1;
		done<=0;
		StateNext<=S_get_next;
		end
		
		S_get_next:begin
		LD_SUM<=0;
		LD_NEXT<=1;
		SUM_SEL<=1;
		NEXT_SEL<=1;
		A_SEL<=0;
		done<=0;
		if(next_zero==0)
			StateNext<=S_computer_sum;
		else if (next_zero == 1)
			StateNext<=S_done;
		end
		
		S_done:begin
		LD_SUM<=0;
		LD_NEXT<=0;
		SUM_SEL<=0;
		NEXT_SEL<=0;
		A_SEL<=0;
		done<=1;
		if(start==0)
			StateNext<=S_start;
		else if (start == 1)
			StateNext<=S_done;
		end
	endcase
end
endmodule
