/* Giovanni Bruno Travassos de Carvalho - 11506849
-----------------INVERSOR-------------------------*/

#include <iostream>
#include <fstream>

using namespace std;

void inv(int *K) 
{
	ofstream myfile;
	myfile.open("inversor.tv", fstream::app);

	int G[4];

	for (int i=0; i<4; ++i) {
    		if(K[i] == 0){
      			G[i]=1;
    		}else{
      			G[i]=0;
		}
 	}


	for (int i=0; i<4; ++i) {
		myfile << K[i];
	}

 	myfile << "_";

	for (int i=0; i<4; ++i) {
		myfile << G[i];
	}

	myfile << "\n";

	myfile.close();
}

int main() 
{

	int A[4]={0,0,0,0};
	int B[4]={1,1,1,1};

	inv(A);
	inv(B);

	return 0;
}
