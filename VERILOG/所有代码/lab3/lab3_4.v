module lab3_4(clk, BTNC, SEG, AN);
    input clk;                                // 系统时钟
    input BTNC;                               // 中按钮
    output [7:0] SEG;                         // 7段数码管驱动，低电平有效
    output [7:0] AN;                          // 7段数码管片选信号，低电平有效

    parameter dely500ms = 50_000_000;         // 0.5s的时钟计数值
    parameter dely1ms = 50_000;               // 0.5s的时钟计数值

    wire ck1;                                 // 分频后的时钟：1Hz
    wire ck2;                                 // 分频后的时钟：1000Hz
    reg ck;
    wire [3:0] dig;
    reg  [2:0] pos;
    reg  [2:0] next;                          // 后面可根据需要增舔变量定义

    initial begin
        next=0;
		pos=0;// 补充模块内变量的初始化代码
    end

    rom8x4 myrom(next, dig);                  // 只读存储器的实例化

    defparam  mydvdr1.dely500us = dely500ms;
    defparam  mydvdr2.dely500us = dely1ms;
    divider mydvdr1(clk, ck1);                // 分频器的实例化
    divider mydvdr2(clk, ck2);                // 分频器的实例化
	 always @(ck1 or ck2) begin
               if(BTNC)
                begin
                 ck = ck2;
                 end
                else
                 begin
                  ck = ck1;
                 end                       // 补充pos和next在时钟作用下按规则变化的代码
       end
       always @(posedge ck) begin
          pos=pos+1;
          next=next+1;
       end
		display mydisp (dig,pos,SEG,AN);           // 补充实例化display模块的代码
		
endmodule


module rom8x4(addr, data);
    input  [2:0] addr;       // 输入地址值：0~7
    output reg [3:0] data;       // 输出该地址上所存储的数据

    reg [3:0] Rom8x4[0:7];   // 8个字的只读存储器，每个字4位

    initial 
	begin
        Rom8x4[0]=0;                     // 存储器的初始化
		Rom8x4[1]=2;
		Rom8x4[2]=4;
		Rom8x4[3]=6;
		Rom8x4[4]=8;
		Rom8x4[5]=10;
		Rom8x4[6]=12;
		Rom8x4[7]=14;
    end

    always @(addr)                         // 补充代码实现功能
	begin
		case(addr)
			3 'b000		:	data=Rom8x4[0];
			3 'b001		:	data=Rom8x4[1];
			3 'b010		:	data=Rom8x4[2];
			3 'b011		:	data=Rom8x4[3];
			3 'b100		:	data=Rom8x4[4];
			3 'b101		:	data=Rom8x4[5];
			3 'b110		:	data=Rom8x4[6];
			3 'b111		:	data=Rom8x4[7];
		endcase
	end
endmodule

module divider(clk, ck);
    input clk;                                   // 系统时钟
    output reg ck;                                   // 分频后的时钟
    
    parameter dely500us = 50_000_000;            // 0.5s的时钟计数值
    reg [31:0] cnt=0;
	
    always @(posedge clk)  begin                                           // 补充代码实现功能
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
    input [3: 0] dig;       // 待显示16进制数字的4位二进制编码：0~9、A~F
    input [2: 0] pos;       // 待显示数码管的编号，AN0~AN7编号依次为0~7
    output [7:0] seg;       // 7段数码管驱动，低电平有效
    output [7:0] an;        // 7段数码管片选信号，低电平有效

    decoder3_8 mydcdr(pos, an);
    pattern    mypttn(.code(dig), .patt(seg));
endmodule

module decoder3_8(num, sel);
    input [2: 0] num;       // 数码管编号：0~7
    output reg [7:0] sel;       // 7段数码管片选信号，低电平有效
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
    input [3: 0] code;       // 16进制数字的4位二进制编码
    output reg [7:0] patt;       // 7段数码管驱动，低电平有效
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
