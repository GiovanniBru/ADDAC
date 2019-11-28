module SOMADOR (A, B, Cin, Soma, Cout);
 
input  A, B, Cin;
output Soma, Cout;
wire Carry_1, Carry_2, Soma_1; 
 
meio_somador U1 (A, B, Soma_1, Carry_1);
meio_somador U2 (Cin, Soma_1, Soma, Carry_2);
or           U3 (Cout, Carry_1, Carry_2);
endmodule