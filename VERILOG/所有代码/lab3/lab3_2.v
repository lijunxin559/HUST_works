module lab3_2(clk, SEG, AN);
    input clk;                                // ϵͳʱ��
    output [7:0] SEG;                         // 7��������������͵�ƽ��Ч
    output [7:0] AN;                          // 7�������Ƭѡ�źţ��͵�ƽ��Ч

    parameter dely500ms = 50_000_000;         // 0.5s��ʱ�Ӽ���ֵ

    wire ck;                                  // ��Ƶ���ʱ��
    reg [3:0] dig;
    reg [2:0] pos;

    initial begin
        dig=8;
		pos=0;								// ����ģ���ڱ����ĳ�ʼ������
    end

    defparam  mydvdr.dely500us = dely500ms;
    divider mydvdr(clk, ck);

    always @(posedge ck) begin
        pos=(pos+1)%8;                                // ����pos��ʱ�������°�����仯�Ĵ���
    end

    display mydisp (dig,pos,SEG,AN);                 // ����ʵ����displayģ��Ĵ���
endmodule

module divider(clk, ck);
    input clk;                                   // ϵͳʱ��
    output reg ck;                                   // ��Ƶ���ʱ��
    
    parameter dely500us = 50_000_000;            // 0.5s��ʱ�Ӽ���ֵ
    reg [31:0] cnt=0;
	
    always @(posedge clk)  begin                                           // �������ʵ�ֹ���
		cnt=cnt+1;
		if(cnt==dely500us)
			begin
			ck=~ck;
			cnt=0;
			end
		else
			ck=ck;
	end

endmodule

module display(dig, pos, seg, an);
    input [3: 0] dig;       // ����ʾ16�������ֵ�4λ�����Ʊ��룺0~9��A~F
    input [2: 0] pos;       // ����ʾ����ܵı�ţ�AN0~AN7�������Ϊ0~7
    output [7:0] seg;       // 7��������������͵�ƽ��Ч
    output [7:0] an;        // 7�������Ƭѡ�źţ��͵�ƽ��Ч

    decoder3_8 mydcdr(pos, an);
    pattern    mypttn(.code(dig), .patt(seg));
endmodule

module decoder3_8(num, sel);
    input [2: 0] num;       // ����ܱ�ţ�0~7
    output reg [7:0] sel;       // 7�������Ƭѡ�źţ��͵�ƽ��Ч
	always @(num)
	begin
	case(num)
		3 'b000		:	sel=8 'b11111110;
		3 'b001		:	sel=8 'b11111101;
		3 'b010		:	sel=8 'b11111011;
		3 'b011		:	sel=8 'b11110111;
		3 'b100		:	sel=8 'b11101111;
		3 'b101		:	sel=8 'b11011111;
		3 'b110		:	sel=8 'b10111111;
		3 'b111		:	sel=8 'b01111111;
	endcase
	end
endmodule

module pattern(code, patt);
    input [3: 0] code;       // 16�������ֵ�4λ�����Ʊ���
    output reg [7:0] patt;       // 7��������������͵�ƽ��Ч
	always @(code)
	begin
	case(code)
		4 'b0000	:	patt=8 'b11000000;
		4 'b0001	:	patt=8 'b11111001;
		4 'b0010	:	patt=8 'b10100100;
		4 'b0011	:	patt=8 'b10110000;
		4 'b0100	:	patt=8 'b10011001;
		4 'b0101	:	patt=8 'b10010010;
		4 'b0110	:	patt=8 'b10000010;
		4 'b0111	:	patt=8 'b11111000;
		4 'b1000	:	patt=8 'b10000000;
		4 'b1001	:	patt=8 'b10011000;
		4 'b1010	:	patt=8 'b10001000;
		4 'b1011	:	patt=8 'b10000011;
		4 'b1100	:	patt=8 'b11000110;
		4 'b1101	:	patt=8 'b10100001;
		4 'b1110	:	patt=8 'b10000110;
		4 'b1111	:	patt=8 'b10001110;
		default		:	patt=8 'b11111111;
	endcase
	end
endmodule

