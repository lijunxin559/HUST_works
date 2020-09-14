module divider(clk, ck);
    input clk;                                   // 系统时钟
    output ck;                                   // 分频后的时钟
    
    parameter dely500us = 50_000_000;            // 0.5s的时钟计数值
    reg [31:0] cnt=0;
	
    always @(posedge clk)  begin                                           // 补充代码实现功能
		cnt<=cnt+1;
		if(cnt==dely500us)
			ck<=~clk;
		else
			ck<=clk;
	end

endmodule
