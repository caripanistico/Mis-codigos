#include <cstdio>
using namespace std;

int g[3][3];

void f() {
	int h[3][3];		//Este es otro problema que ocupa funciones, en este caso, una funcion que agrega los valores de cada casilla, con su correspondiente funcion
						//Claro que lo hace mendiantes la creacion de una matriz estatica, y luego una copia directa de los valores a la matriz original
	h[0][0] = (g[0][1] + g[1][0]) % 2;
	h[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
	h[0][2] = (g[0][1] + g[1][2]) % 2;

	h[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	h[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
	h[1][2] = (g[1][1] + g[0][2] + g[2][2]) % 2;

	h[2][0] = (g[2][1] + g[1][0]) % 2;
	h[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	h[2][2] = (g[2][1] + g[1][2]) % 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			g[i][j] = h[i][j];
		}
	}
}

bool isZero() {							//otra funcion simple, que devuelve true si es una matriz nula, y falso de otra forma.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i][j] > 0)
				return false;
		}
	}
	return true;
}

int main() {
	int TC;

	scanf("%d", &TC);					//en main, se escanea el valor de los numeros de test

	while (TC--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {	//y cada de la matriz es escaneada.
				scanf("%1d", &g[i][j]);
			}
		}

		int ans = -1;
		while (!isZero()) { //mientras la funcion sea distinto de cero, la funcion puede ejecutarse muchas veces.
			f();			//sin embargo si no es posible, se devuelve directamente -1.
			ans++;
		}

		printf("%d\n", ans);	//se imprime el valor de ans.
	}

	return 0;
}