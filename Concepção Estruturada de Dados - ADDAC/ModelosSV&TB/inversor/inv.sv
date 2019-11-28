module inverter (vout, vdd, vss, vin); 
	output vout; 
	input  vin;
	assign vout = ~vin; 
endmodule