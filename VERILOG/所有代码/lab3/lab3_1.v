module lab3_1(clk, led0);
    input clk;                                   // ϵͳʱ��
    output reg led0;                                 // ��Ƶ���ʱ��
    wire ck;
    defparam liu.dely500us=50_000_000;
	divider liu(clk,ck);
	always @(ck) begin
		led0=ck;
	end
endmodule

module divider(clk, ck);
    input clk;                                   // ϵͳʱ��
    output reg ck;                                   // ��Ƶ���ʱ��
    
    parameter dely500us = 50_000_000;            // 0.5s��ʱ�Ӽ���ֵ
    reg [31:0] cnt=0;
	
    always @(posedge clk)  begin   // �������ʵ�ֹ���
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
