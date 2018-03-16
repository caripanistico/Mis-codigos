#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);						//se utiliza un mapa de strings con enteros, cada vez que se encuentra el string, el valor del entero aumenta
	getchar();
	getchar();
	while(t--) {
		map<string, int> record;
		string tree;
		int n = 0;
		while(getline(cin, tree)) {			
			if(tree.compare("") == 0)	//lee cada linea, si es distinto de 'vacio', se agrega al mapa
				break;
			record[tree]++;
			n++;
		}							//ahora utilizando el metodo iterador, se imprimen los arboles, calculando su porcentaje
		for(map<string, int>::iterator i = record.begin(); i != record.end(); i++)
			cout << i->first << " " << fixed << setprecision(4) << i->second*100.0/n << endl;
		if(t)
			puts("");
	}
    return 0;
}
