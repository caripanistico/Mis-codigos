//https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2012346%20-%20Water%20Gate%20Management/src/UVa%2012346%20-%20Water%20Gate%20Management.cpp
#include <cstdio>
using namespace std;

int f[20], c[20];

int main() {
	int n, tc, v, t, count = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &f[i], &c[i]);				//el problema habla sobre una represa, en el cual se pueden presentar inundaciones por aumento del agua
	}												//dado distintas puertas de flujo de agua, con su costo en daños correspondiente, se debe encontrar la mejor
													//solucion para la liberacion de una cantidad determinada de agua, usando las puertas de flujo correspondientes para
	scanf("%d", &tc);								//obtener el costo por daños menor
	while (tc--) {
		count++;
		scanf("%d %d", &v, &t);

		int minc = 10000000, tf, tcost;
		for (int s = 0; s < (1 << n); s++) {		//despues de recolectar los datos, el programa hace una permutaciones de todas las posibles formas en las que se
			tf = tcost = 0;							//pueden abrir las puertas de flujo de agua, y siempre guardando la permutacion que resuelva el problema en el
			for (int i = 0; i < n; i++) {			//menor costo posible
				if (1 & (s >> i)) {
					tf += f[i];
					tcost += c[i];					//cada puerta de flujo posee un grado de salida de agua por hora, y su correspondiente costo
				}									//la idea es encontrar la solucion en la que se pueda sacar una cantidad de agua en un tiempo arbitrario
			}										//con el menor costo de daños posibles
			if (tf * t >= v) {
				if (tcost < minc) {
					minc = tcost;
				}
			}
		}

		if (minc < 10000000)
			printf("Case %d: %d\n", count, minc);		//si existe una forma de sacar una cantidad de agua, dentro de un tiempo en horas, en el que el costo es el menor
		else											//se imprime aqui, de otra forma se imprime "imposible"
			printf("Case %d: IMPOSSIBLE\n", count);
	}

	return 0;
}
