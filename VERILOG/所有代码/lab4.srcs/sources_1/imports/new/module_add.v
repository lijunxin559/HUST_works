`timescale 1ns / 1ps


module module_add (a,b,out);
    //输入端口：a,b
    //输出端口：out
    //n位加法器
    //out = a + b ；丢弃高位
    parameter WIDTH = 8;
    //模块内部参数暂定为8，可以通过传参调整位宽
    output reg [WIDTH-1 : 0] out;
    input [WIDTH-1 : 0] a;
    input [WIDTH-1 : 0] b;
    reg [WIDTH : 0] temp;
    //temp 用来保存加法结果，输出的时候丢弃高位
    
    always @ (a or b)
    begin
        temp = a + b ;
        out = temp [WIDTH - 1 : 0];
    end
endmodule