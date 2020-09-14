module rom8x4(addr, data);
    input  [2:0] addr;       // �����ֵַ��0~7
    output [3:0] data;       // ����õ�ַ�����洢������

    reg [3:0] Rom8x4[0:7];   // 8���ֵ�ֻ���洢����ÿ����4λ

    initial 
	begin
        Rom8x4[0]=0;                     // �洢���ĳ�ʼ��
		Rom8x4[1]=2;
		Rom8x4[2]=4;
		Rom8x4[3]=6;
		Rom8x4[4]=8;
		Rom8x4[5]=10;
		Rom8x4[6]=12;
		Rom8x4[7]=14;
    end

    always @(addr)                         // �������ʵ�ֹ���
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
