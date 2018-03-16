#include <iostream>
using namespace std;

int main(){
	int size1, size2, size3, aux; 
	int iguales = 0;

	cin >> size1;
	int values1[size1];							

	for(int i = 0; i < size1;i++)
		cin >> values1[i];

	cin >> size2;
	int values2[size2];

	for(int j = 0; j < size2;j++)
		cin >> values2[j];

	cin >> size3;
	int values3[size3];

	for(int k = 0; k < size3;k++)
		cin >> values3[k];
	
	for(int i = 0; i < size1;i++){		
		aux = values1[i];// values1[4]= 146 => aux = 146
		for(int j = 0; j < size2; j++){
			if (aux == values2[j]){		// 146 == values2[3] = 146 ?? si 
				for(int k = 0; k < size3; k++){	
					if(aux == values3[k]){	//146 == values3[4] = 146?? si
						iguales++;			//iguales = 3
						break;				//for k
					}
					else{
						if(aux < values3[k]) //43 < 13? no
							break; // for k
					}
				}
			break;	// for j
			}
			else{
				if(aux < values2[j]) // 146 < 13? no
					break; //for j
			}
		}
	}
	cout << iguales << endl;
	return 0;
}

