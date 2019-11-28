module acc(clk, reset, a, reg_sum);

	input clk, reset;
	input a;
	output reg_sum;
	reg reg_sum;
	
always @ (negedge clk)
	if(reset)
		reg_sum <= 1'd0;
	else
		reg_sum <= a + reg_sum;
endmodule
 
