/*Giovanni Bruno Travassos de Carvalho - 11506849
----------------ACUMULADOR ---------------------*/

#include<fstream>
#include<iostream>

using namespace std;

void acc(int *input,int clk)
{ 
	int before[4];
	int after[4];
	ofstream myfile;
	myfile.open ("acc.tv", fstream::app); //Cria e abre o acc.tv
	
	int i; 

	for(i=0; i<4; i++){
        	before[i] = input[i];
  	}

	myfile << clk << "_"; 

	for(i=0; i<4; i++){
       		myfile << input[i];
   	}

    	myfile << "_";

    	if(clk){
		for(i=0; i<4; i++){
			myfile << input[i];
		}
   	}else{
		for(i=0; i<4; i++){
			myfile << 'x';
        	}
  	}

    	myfile << "\n";

    	clk = !clk;

	myfile << clk<< "_";

	for(i=0; i<4; i++){
       		myfile << input[i];
    	}

	myfile << "_";

	if(clk){
		for(i=0; i<4; i++){
			after[i] = input[i];
			myfile << after[i];
      		}
    	}else{
		for(int i=0; i<4; i++){
			myfile << before[i];
        	}
   	}

	myfile << "\n";

	myfile.close();
}

int main() 
{
    int G[4]{0,0,0,0};
    acc(G,0);

    return 0;
}

