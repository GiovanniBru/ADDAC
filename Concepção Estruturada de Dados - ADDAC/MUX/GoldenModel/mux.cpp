/* Giovanni Bruno Travassos de Carvalho - 11596849
---------------- MULTIPLEXADOR ------------------
Dada duas entradas um sinal de controle determina qual vai ser a saída*/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void mux(int A1, int A2, int key)
{
	ofstream myfile;
	myfile.open("mux.tv", fstream::app);

	myfile << A1 << "_" << A2 << "_" << key << "_";

	if(key){
		myfile << A2;
	}else{
		myfile << A1;
	}

	myfile << "\n";

	myfile.close();
}


int main() 
{
	int A1=0;
	int A2=1;

	mux(A1, A2, 0);
	mux(A1, A2, 1);
	return 0;
}
