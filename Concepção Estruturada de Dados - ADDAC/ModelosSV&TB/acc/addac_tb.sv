`timescale 1ns/100ps

module addac_tb;
    
int counter, error, aux_error;
logic clk,rst;
logic clk2;
logic [3:0] a;
logic sel0, sel1;
logic cout, cout_esperado;
logic [3:0] s, s_esperado;
logic [11:0]vectors[11];
 
addac dut(a, sel0, sel1, clk2, cout, s);

initial begin
	$display("Iniciando Testbench");
	$display("| CLK | SEL0 | SEL1 | A | COUT | S |"); 
	$display("---------------");
	$readmemb("addac.tv",vectors);
	counter=0; errors=0;
	rst = 1; #33; rst = 0;		
end
		
always
    begin
    clk=1; #10;
	clk=0; #5;
    end

always @(posedge clk)
	if(~rst)
	begin
		{clk2,sel0,sel1,a,cout_esperado,s_esperado} = vectors[counter];	
	end

always @(negedge clk)	
		if(~rst)
		begin
			aux_error = errors;
			for(int i = 0; i < 4; i++) begin
				assert (s[i] === s_esperado[i])
		else	
		begin

			$display("Error S: input in position %d = %b", i, s[i]);
			$display("linha %d ª , saída: %b, (%b esperado)",counter+1, s[i], s_esperado[i]);
						
			errors = errors + 1;
			end
		end
			assert(cout === cout_esperado)
		else
		begin

			$display("Error COUT:");
			$display("linha %d ª , saída: %b, (%b esperado)",counter+1, cout, cout_esperado);
						
			errors = errors + 1; 
			end
		if(aux_error === errors)
			$display("| %b | %b | %b | %b | %b | %b | OK", clk2, sel0, sel1, a, cout, s);
		else
			$display("| %b | %b | %b | %b | %b | %b | ERROR", clk2, sel0, sel1, a, cout, s);

			counter++;	
			
			if(counter == $size(vectors)) 
			begin
				$display("Testes Efetuados: %0d", counter);
				$display("Erros Encontrados: %0d", errors);
				#10
				$stop;
			end
			
		end
		
 endmodule
