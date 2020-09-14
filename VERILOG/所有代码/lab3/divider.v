module divider(clk, ck);
    input clk;                                   // ϵͳʱ��
    output ck;                                   // ��Ƶ���ʱ��
    
    parameter dely500us = 50_000_000;            // 0.5s��ʱ�Ӽ���ֵ
    reg [31:0] cnt=0;
	
    always @(posedge clk)  begin                                           // �������ʵ�ֹ���
		cnt<=cnt+1;
		if(cnt==dely500us)
			ck<=~clk;
		else
			ck<=clk;
	end

endmodule
