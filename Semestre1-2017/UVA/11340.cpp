#include <bits/stdc++.h>
using namespace std;
//11340 - Newspaper
//Este problema es interesante, puesto que el codigo que he buscado utiliza mapas
int main()
{
	int T, K, M, l;
	map <char, double> mymap;		//Se crean enteros y un mapa, donde se guardaran todos los datos de los caracteres
	map <char, double>::iterator it; // y un mapa que es utlizado como iterador, es decir, cuando se busca el caracter, devuelve el double
	char c;
	string line;
	double v, total;

	scanf("%d", &T);
	while(T--)
	{
		total = 0;
		scanf("%d", &K);
		for(int i = 0; i < K; i++){					//asignando el map
			cin >> c >> v;
			mymap[c] = v;
		}
		scanf("%d", &M);
		cin.ignore();							//se llama a esta funcion para ignorar cualquier caracter que sea introducido mientras se ejecuta el programa.
		for(int i = 0; i < M; i++){
			line = "";
			getline(cin, line);					//"Limpia" el string line, y luego utiliza la funcion de Iostream, getLine, donde obtiene la linea entera.
			l = line.size();					//y asigna un valor entero, que es el tamaño del string, a un int
			for(int j = 0; j < l; j++){
				it = mymap.find(line[j]);		//utiliza el iterador, para encontrar al caracter dentro del mapa
				if(it != mymap.end())			//mientras no este al final, si lo encuentra, este agrega su valor asignado en el mapa, al total
					total += it->second;
			}			
		}
		total /= 100;							//divide el total en 100 para devolver el valor en dolares.
		printf("%0.2lf$\n", total);				//y trunca el double a 2 decimales, junto con el valor del parrafo
		mymap.clear();							//y limpia el mapa, para hacer un loop nuevamente, hasta que T sea 0;
	}
	return 0;
}