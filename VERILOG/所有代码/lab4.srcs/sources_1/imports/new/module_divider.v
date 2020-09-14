`timescale 1ns / 1ps


module module_divider(clk, clk_N);
input clk;                      // ϵͳʱ��
output clk_N;                   // ��Ƶ���ʱ��
parameter N = 100_000_000;      // 1Hz��ʱ��,N=fclk/fclk_N
reg [31:0] counter;             /* ������������ͨ������ʵ�ַ�Ƶ��
                                   ����������0������(N/2-1)ʱ��
                                   ���ʱ�ӷ�ת������������ */
reg clk_N;						//��always����ж�clk_N��ֵ������Ϊreg
								   
initial begin
	counter = 0;
end

always @(posedge clk)begin    // ʱ��������
    // ����ʵ��
	if(counter == ((N/2)-1))
		begin
		clk_N = ~ clk_N;		//���ʱ�ӷ�ת
		counter = 0;		//����������
		end
	else
		begin
		counter = counter + 1;//��������һ
		end
end                           
endmodule

