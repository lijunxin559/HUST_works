`timescale 1ns / 1ps


module module_add (a,b,out);
    //����˿ڣ�a,b
    //����˿ڣ�out
    //nλ�ӷ���
    //out = a + b ��������λ
    parameter WIDTH = 8;
    //ģ���ڲ������ݶ�Ϊ8������ͨ�����ε���λ��
    output reg [WIDTH-1 : 0] out;
    input [WIDTH-1 : 0] a;
    input [WIDTH-1 : 0] b;
    reg [WIDTH : 0] temp;
    //temp ��������ӷ�����������ʱ������λ
    
    always @ (a or b)
    begin
        temp = a + b ;
        out = temp [WIDTH - 1 : 0];
    end
endmodule