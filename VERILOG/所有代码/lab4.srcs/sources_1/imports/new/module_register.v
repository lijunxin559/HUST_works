`timescale 1ns / 1ps


module module_register(D,clk,reset,load,Q);
  parameter WIDTH=8;
  input [WIDTH-1:0] D;
  input clk;
  input reset;
  input load;
  output reg [WIDTH-1:0] Q;
  reg [WIDTH-1:0] reg_0;
  //reg���ͣ�ȫ�㣬�������յ�reset�ź�ʱ�����������
  initial begin
	reg_0=0;
  end
always @(posedge clk) begin
    if (reset)
        begin
            Q <= reg_0;
        end 
    else if (load)
        begin
            Q <= D;
        end
end
endmodule

