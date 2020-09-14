`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: lab2-4
//////////////////////////////////////////////////////////////////////////////////
module _7Seg_BCD(SW, SEG, AN, LED);
	input [15:0] SW; 
	output reg [7:0] SEG;      // 7段数码管驱动（个位），低电平有效
	output reg [7:0] AN;       // 7段数码管片选信号，低电平有效8
	output reg [15:0] LED;     // 16位LED显示
	always	@(SW)
	begin
	if(SW[15])
	begin
		case(SW[3:0])
			4 'b0000,
			4 'b0001,	
			4 'b0010,	
			4 'b0011,	
			4 'b0100,	
			4 'b0101,	
			4 'b0110,	
			4 'b0111,	
			4 'b1000,	
			4 'b1001	:	SEG=8 'b11000000;
			4 'b1010,	
			4 'b1011,	
			4 'b1100,	
			4 'b1101,	
			4 'b1110,	
			4 'b1111	:	SEG=8 'b11111001;
			default		:	SEG=8 'b11111111;
		endcase
	end
	else
	begin
		case(SW[3:0])
			4 'b0000	:	SEG=8 'b11000000;
			4 'b0001	:	SEG=8 'b11111001;
			4 'b0010	:	SEG=8 'b10100100;
			4 'b0011	:	SEG=8 'b10110000;
			4 'b0100	:	SEG=8 'b10011001;
			4 'b0101	:	SEG=8 'b10010010;
			4 'b0110	:	SEG=8 'b10000010;
			4 'b0111	:	SEG=8 'b11111000;
			4 'b1000	:	SEG=8 'b10000000;
			4 'b1001	:	SEG=8 'b10011000;
			4 'b1010	:	SEG=8 'b11000000;
			4 'b1011	:	SEG=8 'b11111001;
			4 'b1100	:	SEG=8 'b10100100;
			4 'b1101	:	SEG=8 'b10110000;
			4 'b1110	:	SEG=8 'b10011001;
			4 'b1111	:	SEG=8 'b10010010;
			default		:	SEG=8 'b11111111;
		endcase
	end
	case(SW[14:12])
		3 'b000		:	AN[0]=0;
		3 'b001		:	AN[1]=0;
		3 'b010		:	AN[2]=0;
		3 'b011		:	AN[3]=0;
		3 'b100		:	AN[4]=0;
		3 'b101		:	AN[5]=0;
		3 'b110		:	AN[6]=0;
		3 'b111		:	AN[7]=0;
	endcase
	LED[15]<=SW[15];
	LED[14]<=SW[14];
	LED[13]<=SW[13];
	LED[12]<=SW[12];
	LED[11]<=SW[11];
	LED[10]<=SW[10];
	LED[9]<=SW[9];
	LED[8]<=SW[8];
	LED[7]<=SW[7];
	LED[6]<=SW[6];
	LED[5]<=SW[5];
	LED[4]<=SW[4];
	LED[3]<=SW[3];
	LED[2]<=SW[2];
	LED[1]<=SW[1];
	LED[0]<=SW[0];
	end
endmodule