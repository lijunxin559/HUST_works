`timescale 1ns / 1ps


module module_mux(a,b,sel,out);
    //����˿ڣ�a,b,sel
    //����˿ڣ�out
    //nλ��ѡһ��·ѡ����
    //��sel==1ʱ��out=b������out=a
    parameter WIDTH = 8;
    //ģ���ڲ������ݶ�Ϊ8������ͨ�����ε���λ��
    output reg [WIDTH-1 : 0] out;
    input [WIDTH-1 : 0] a;
    input [WIDTH-1 : 0] b;
    input sel;
    
    always @ (a or b or sel)
    begin
        if(sel)
            out = a;
        else 
            out = b;
    end
endmodule
