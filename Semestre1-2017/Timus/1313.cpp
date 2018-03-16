#include <bits/stdc++.h>
using namespace std;

int main(){
	int size;
	cin >> size;
	int array[size][size];
	for(int i = 0; i<size;i++)
		for(int j = 0; j<size;j++)
			cin >> array[i][j];

for(int diag = 0; diag < size; diag++)
	for(int aux = 0; aux <= diag;aux++)
		cout << array[diag-aux][aux] << " ";

int aux2 = 0, aux3 = 1;
for(int diag = size-1; diag > 0; diag--){
	for(int aux = 1; aux <= diag;aux++){
		cout << array[diag-(aux-aux3)][aux+aux2] << " "; //
	}
	aux2++;
	aux3++;
}

cout << endl;
	return 0;
}