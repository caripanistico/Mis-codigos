#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, target[1000];
	int i;

	while (true) {
		cin >> n;	//Se crea un arreglo grande, y unos enteros, y luego se escanean
		if (n == 0)
			break;

		while (true) {
			cin >> target[0];
			if (target[0] == 0){	//si el primer valor es 0, se sale del loop
				cout << endl;
				break;
			}
			for (i = 1; i < n; i++) {
				cin >> target[i];		//si no, continua preguntando por los demas valores.
			}

			int currCoach = 1, targetIndex = 0;
			stack<int> station;				//se crea un stack, y se agregan cada uno de los valores.
			while(currCoach<=n){
				station.push(currCoach);

				while(!station.empty() && station.top() == target[targetIndex]){
					station.pop();				//si el valor es encontrado, se saca del stack y se aumentan los iteradores
					targetIndex++;
					if(targetIndex>=n) break;
				}

				currCoach++;
			}

			if(station.empty()) cout << "Yes" << endl; //si todos los valores no estan, se devuelve 'Yes'. de otra forma se devuelve 'No'
			else cout << "No" << endl;
		}
	}

	return 0;
}
