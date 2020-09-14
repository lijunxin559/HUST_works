module rom8x4(addr, data);
    input  [2:0] addr;       // 输入地址值：0~7
    output [3:0] data;       // 输出该地址上所存储的数据

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
	end
endmodule
