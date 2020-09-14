`timescale 1ns / 1ps


module module_rom(rom_addr,rom_data);
parameter ADDR_WIDTH = 8;
parameter DATA_WIDTH = 8;
input [ADDR_WIDTH-1:0] rom_addr;
output reg [DATA_WIDTH-1:0] rom_data;

reg [DATA_WIDTH-1:0] rom [2**ADDR_WIDTH-1:0];
//数组，由2的ADDR_WIDTH次幂个元素，每个元素是一个DATA_WIDTH位的向量
always @(rom_addr)
begin
	rom_data=rom[rom_addr];
end

initial begin
	rom[0]<=4'h0003;
	rom[1]<=4'h0002;
	rom[2]<=4'h0000;
	rom[3]<=4'h0007;
	rom[4]<=4'h0004;
	rom[5]<=4'h0000;
	rom[6]<=4'h0000;
	rom[7]<=4'h000b;
	rom[8]<=4'h0006;
	rom[9]<=4'h0000;
	rom[10]<=4'h0000;
	rom[11]<=4'h0000;
	rom[12]<=4'h0008;
	rom[13]<=4'h0000;
	rom[14]<=4'h0000;
	rom[15]<=4'h0000;
end

endmodule