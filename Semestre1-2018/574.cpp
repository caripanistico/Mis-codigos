//https://github.com/morris821028/UVa/blob/master/volume005/574%20-%20Sum%20It%20Up.cpp
#include <stdio.h>
int target, n, A[20], i;
int flag, choose[20], last[20];
void DFS(int now, int sum, int t) {
	if(sum == target) {
		int i;
		for(i = 0; i < n; i++)
			if(choose[i] != last[i])				//dado un numero arbitrario, y una secuencia de numeros, se deben encontrar todas las combinaciones
				break;								//de los numeros de la secuencia, tales que su suma sea el numero arbitrario dado
		if(i == n)	return;							//los numeros no pueden volver a ser utilizados, solo se utilizan n veces, siendo n la cantidad de veces
		for(i = 0; i < t; i++) {					//que aparece en la secuencia de numeros
			if(i)	printf("+");
			printf("%d", choose[i]);
			last[i] = choose[i];
		}
		puts("");
		for(; i < n; i++)	last[i] = -1;			//este problema ve el problema como un camino en un grafo
		flag = 1;									//por lo que recurre a una busqueda de profundidad recursiva
		if(A[now])									//algo que es posible, porque el rango de numeros y soluciones no es muy grande
			return;									//se deben encontrar todas las combinaciones, de forma que 2 soluciones no sean iguales pero igual de validas
	}
	if(now == n || sum > target)	return;
	choose[t] = A[now];
	DFS(now+1, sum+A[now], t+1);
	choose[t] = -1;
	DFS(now+1, sum, t);
}
int main() {
	while(scanf("%d %d", &target, &n) == 2) {				//una vez terminado el dfs, imprime los valores y el programa termina
		if(n == 0)	break;
		for(i = 0; i < n; i++)
			scanf("%d", &A[i]), last[i] = -1, choose[i] = -1;
		printf("Sums of %d:\n", target);
		flag = 0;
		DFS(0, 0, 0);
		if(flag == 0)	puts("NONE");
	}
    return 0;
}
