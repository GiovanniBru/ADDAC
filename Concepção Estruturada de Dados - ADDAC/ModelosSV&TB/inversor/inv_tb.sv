module inverter_TB(vin, vout); 
	input vout; 
	output vin; 
	reg vin; 
	inverter name(.vin(vin), .vout(vout)); 
	initial 
	begin 
		vin = 1’b0;
	end 
	always 
		#20 vin = ~ vin; 
endmodule;