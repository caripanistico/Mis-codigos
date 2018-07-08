//https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20624%20-%20CD/src/UVa%20624%20-%20CD.cpp
#include <cstdio>
#include <iostream>
using namespace std;

int tapeLen, n, trackLen[20];
int ans, nearestTotal;												//el problema busca encontrar una combinacion de pesos, tales que sean menor que un total
void choose(int total, int mask, int p) {							//esto es, un casette tiene un tamaño N, y las pistas de musica a agregar tienen un tamaño menor a N
	if (total > tapeLen)											//se debe encontrar una combinacion de tamaños de pistas, tal que complete N lo mas posible
		return;
	if (total > nearestTotal) {
		nearestTotal = total;
		ans = mask;													//como el problema no es tan grande, se pueden hacer todas las permutaciones posibles de pistas
	}																//y elegir la que contenga mas pistas, sin pasarse del tamaño N del casette
	if (p >= n)
		return;

	choose(total + trackLen[p], mask | (1 << p), p + 1);
	choose(total, mask, p + 1);
}

int main() {
	while (scanf("%d %d", &tapeLen, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &trackLen[i]);
		}

		ans = -1;
		nearestTotal = -1;										//una vez encontrado, mediante el uso de una funcion recursiva (porque, como ya se dijo, el input no es muy grande, y por lo tanto, una funcion recursiva no utiliza tanta memoria)
		choose(0, 0, 0);										//se elige la mejor permutacion y se imprime

		for (int i = 0; i < n; i++) {
			if ((ans >> i) % 2)
				printf("%d ", trackLen[i]);
		}
		printf("sum:%d\n", nearestTotal);
	}

	return 0;
}
