//https://github.com/morris821028/UVa/blob/master/volume107/10755%20-%20Garbage%20Heap.cpp
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long V3[21][21][21], V2[21][21][21];
void sol(int A, int B, int C) {
    long long mx = V3[0][0][0];
    int i, j, k, p, q;
    for(i = 0; i < A; i++)
        for(j = 0; j < B; j++)
            for(k = 0; k < C; k++)
                mx = max(mx, V3[i][j][k]);                          //dado un paralelepipedo, de tamaño A x B x C, de basura, donde cada cubo de volumen 1, tiene un valor numerico
    for(p = 0; p < A; p++)                                          //el problema busca reducir tal paralelepipedo a uno de menor tamaño que el original, con el mayor valor combinado posible, siempre y cuando este exista
    for(q = p; q < A; q++) {                                        //ya que si no existe, el palelepipedo queda de igual forma
        for(i = 0; i < B; i++) {                                    //esto es buscar un paralelepipedo de todos los tamaños posibles que sean menores de que original, y encontrar el que posea mayor valor combinado
            long long sum[21] = {}, tmp;                            //esto puede crear un numero muy grande de combinaciones, pero sin embargo el tamaño maximo del paralelepipedo es de 20x20x20 = 8000
            for(j = i; j < B; j++) {                                //por lo que la unica solucion viable es el uso de un algoritmo greedy
                tmp = 0;
                for(k = 0; k < C; k++) {                            //que es lo que hace el algoritmo
                    sum[k] += V2[q][j][k];                          //prueba todos los tamaños de paralelepipedos menores, posibles, y luego guarda el mejor resultado obtenido hasta entonces
                    if(p)   sum[k] -= V2[p-1][j][k];                //esto se puede ver por el gran numero de for's utilizados en la funcion
                    tmp += sum[k];
                    mx = max(mx, tmp);
                    if(tmp < 0) tmp = 0;
                }
            }
        }
    }
    printf("%lld\n", mx);
}
int main() {                                                        //pero una vez encontrado el mejor, simplemente se imprime su valor
    int testcase, A, B, C;
    int i, j, k;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d", &A, &B, &C);
        memset(V2, 0, sizeof(V2));
        for(i = 0; i < A; i++) {
            for(j = 0; j < B; j++) {
                for(k = 0; k < C; k++) {
                    scanf("%lld", &V3[i][j][k]);
                    V2[i][j][k] = V3[i][j][k];
                    if(i)   V2[i][j][k] += V2[i-1][j][k];
                }
            }
        }
        sol(A, B, C);
        if(testcase)
            puts("");
    }
    return 0;
}
/*
1
2 3 3
21 -39 4 -39 4 -44 1 -32 -25 -35 2 17 6 10 2 -12 -22 35
*/
