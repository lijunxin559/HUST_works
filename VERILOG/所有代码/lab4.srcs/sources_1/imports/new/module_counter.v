`timescale 1ns / 1ps

module module_counter(clk, out);
input clk;                    // ����ʱ��
output [2:0] out;             // ����ֵ
reg [2:0] out;				  // ��always����ж�out���и�ֵ������Ϊreg

initial begin
	out = 0;
end

always @(posedge clk)  begin  // ��ʱ�������ؼ�������1
                              // ����ʵ��
	out = out + 1;
end                           
endmodule
