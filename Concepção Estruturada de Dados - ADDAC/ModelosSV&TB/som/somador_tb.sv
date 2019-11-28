module SOMADOR_tb;

	reg 	A_tb, B_tb, Cin_tb;
	wire  Soma_tb, Cout_tb;

SOMADOR dut( A_tb, B_tb, Cin_tb, Soma_tb, Cout_tb);

initial
begin
	A_tb = 1'b0;	B_tb = 1'b0;	Cin_tb = 1'b0; #1
	A_tb = 1'b0;	B_tb = 1'b1;	Cin_tb = 1'b0; #1
	A_tb = 1'b1;	B_tb = 1'b0;	Cin_tb = 1'b0; #1
	A_tb = 1'b1;	B_tb = 1'b1;	Cin_tb = 1'b0; #1
	A_tb = 1'b0;	B_tb = 1'b0;	Cin_tb = 1'b1; #1
	A_tb = 1'b0;	B_tb = 1'b1;	Cin_tb = 1'b1; #1
	A_tb = 1'b1;	B_tb = 1'b0;	Cin_tb = 1'b1; #1
	A_tb = 1'b1;	B_tb = 1'b1;	Cin_tb = 1'b1; #1;
end
endmodule
