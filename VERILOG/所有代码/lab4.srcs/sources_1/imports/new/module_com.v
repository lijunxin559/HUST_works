`timescale 1ns / 1ps

module module_com(in,out);
//���ļ�Ϊ�Ƚ���ģ�飬����0���1
parameter WIDTH = 8;
input [WIDTH-1:0] in;
output reg out;
always @(in)
begin
    if(in)
    begin
        out = 0;
    end
    else
    begin
        out = 1;
    end
end
endmodule
