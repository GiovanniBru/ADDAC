/* Giovanni Bruno Travassos de Carvalho - 11506849
------------------SOMADOR & SUBTRATOR---------------*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int A, B, carryOut, carryIn, type;

void somaEsub(int type,int A, int B, int carryIn)
{
	int carryOut = 0;
	int sum = 0;

	ofstream myfile;
	myfile.open("somaesub.tv", fstream::app);


	myfile << type << "_"<< A << "_" << B << "_" << carryIn << "_";



	if (type==0){ 	//SOMADOR

		sum = A + B + carryIn;

		if(sum >= 2){
			if(bool(A) && bool(B) && bool(carryIn)){
		     		sum = 1;
		      		myfile << sum << "_";
		    	}else{
		        	sum = 0;
		        	myfile << sum << "_";
		    	}
		    	carryOut = 1;
		   	myfile << carryOut;

		}else{
			if(sum == 1){
				sum = 1;
				myfile << sum << "_";
				carryOut = 0;
				myfile << carryOut;
			}else{
				sum = 0;
				myfile << sum << "_";
		 		carryOut = 0;
				myfile << carryOut;
			}
		}
		myfile << "\n";

	}


	if (type==1){ 	// SUBTRATOR

		if      ( bool(A) && bool(B) && bool(carryIn)){
			sum = 1;
			carryOut = 1;
			myfile << sum << "_" << carryOut << "\n";
		}else if( !(bool(A)) && !(bool(B)) && bool(carryIn)){
			sum = 1;
			carryOut = 1;
			myfile << sum << "_" << carryOut << "\n";
	   	}else if( !(bool(A)) && (bool(B)) && !(bool(carryIn))) {
			sum = 1;
			carryOut = 1;
			myfile << sum << "_" << carryOut << "\n";
	  	} else if( !(bool(A)) && (bool(B)) && (bool(carryIn))) {
			sum = 0;
			carryOut = 1;
			myfile << sum << "_" << carryOut << "\n";
	  	}else if( (bool(A)) && !(bool(B)) && !(bool(carryIn))) {
			sum = 1;
			carryOut = 0;
			myfile << sum << "_" << carryOut << "\n";
	  	}else if( !(bool(A)) && (bool(B)) && !(bool(carryIn))) {
			sum = 1;
			carryOut = 1;
			myfile << sum << "_" << carryOut << "\n";
	   	}else{
			sum = 0;
			carryOut = 0;
			myfile << sum << "_" << carryOut << "\n";
	  	}
	}
	myfile.close();

}

int main() 
{

	somaEsub(0, 0, 0, 0); //SOMA 0 0 
	somaEsub(0, 0, 1, 0); //SOMA 0 1 
	somaEsub(0, 1, 0, 1); //SOMA 1 0 
	somaEsub(0, 1, 1, 1); //SOMA 1 1
	somaEsub(1, 0, 0, 0); //SUB  0 0
	somaEsub(1, 0, 1, 0); //SUB  0 1
	somaEsub(1, 1, 0, 1); //SUB  1 0 
	somaEsub(1, 1, 1, 1); //SUB  1 1

	return 0;
}
