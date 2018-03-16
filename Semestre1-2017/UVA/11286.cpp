#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, A[5];
	char buf[20];
	while(scanf("%d", &n) == 1 && n) {
		string str;
		map<string, int> record;        //se leen los datos.. se crea un mapa, y se almacenan los datos en el, utilizando el string de los numeros, y el int como en numero de veces que se ha encontrado la misma combinacion
		while(n--) {
			scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]);
			sort(A, A+5);												//pero primero los ordena
			sprintf(buf, "%d%d%d%d%d", A[0], A[1], A[2], A[3], A[4]);
			str = buf;
			record[str]++;
		}
		int max = 0, maxNum = 0;
		for(map<string, int>::iterator i = record.begin(); i != record.end(); i++) {
			if(i->second > max)
				max = i->second, maxNum = 0;     //una vez que los datos se han ordenado y agregados al mapa, se utiliza el iterador para buscar el mas frecuente
			if(i->second == max)
				maxNum += max;
		}
		printf("%d\n", maxNum); //y se imprime la combinacion mas frecuente
	}
    return 0;
}
