module lab3_1(clk, led0);
    input clk;                                   // 系统时钟
    output reg led0;                                 // 分频后的时钟
    wire ck;
    defparam liu.dely500us=50_000_000;
	divider liu(clk,ck);
	always @(ck) begin
		led0=ck;
	end
endmodule

module divider(clk, ck);
    input clk;                                   // 系统时钟
    output reg ck;                                   // 分频后的时钟
    
    parameter dely500us = 50_000_000;            // 0.5s的时钟计数值
    reg [31:0] cnt=0;
	
    always @(posedge clk)  begin   // 补充代码实现功能
		cnt=cnt+1;
		if(cnt==dely500us)
		    begin
			ck=~ck;
			cnt=0;
			end
		else
			ck=ck;
	end

endmodule
