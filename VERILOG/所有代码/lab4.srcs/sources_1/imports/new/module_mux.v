`timescale 1ns / 1ps


module module_mux(a,b,sel,out);
    //输入端口：a,b,sel
    //输出端口：out
    //n位二选一多路选择器
    //当sel==1时，out=b，否则out=a
    parameter WIDTH = 8;
    //模块内部参数暂定为8，可以通过传参调整位宽
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
