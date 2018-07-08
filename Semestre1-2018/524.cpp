//https://gist.github.com/KT-Yeh/9434589
#include <cstdio>
using namespace std;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int N, Case = 0, ans[20] = {1};
bool isPrime(int a)
{
    for (int n : prime)
        if (n == a) return true;
    return false;
}
void backtracking(int L, bool visit[])                      //el problema es encontrar los numeros tales que un grafo ciclico, en forma de anillo, de tamaño dado en el input,  cada nodo con su anterior o siguiente nodo,
{                                                           //su valor debe ser un valor primo. este codigo se hace creando un set auxiliar de numeros primos, y una funcion auxiliar recursiva
    if (L == N) {                                           //que busca un valor para utilizar en un nodo, y luego lo marca, evitando usarlo nuevamente hasta crear otro nuevo grafo
        if (!isPrime(ans[N-1] + 1))                 
            return;
        printf("1");
        for (int i = 1; i < N; ++i)
            printf(" %d", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 2; i <= N; ++i) {                          //va generando con cada numero posible, entre el rango de 1 y N, incluido ambos
        if (visit[i]) continue;                             //y los suma con su anterior, y luego prueba si ocurre lo mismo con el sucesor, utilizando la recursion
        if (isPrime(i + ans[L - 1])) {                      //si encuentra distintas combinaciones posibles, las guarda
            visit[i] = 1;
            ans[L] = i;

            backtracking(L + 1, visit);

            visit[i] = 0;
        }
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {                        //y luego las imprime desde la posicion 0 a N y luego de N a 0
        if (Case++) putchar('\n');
        printf("Case %d:\n", Case);
        bool visit[20] = {0};
        backtracking(1, visit);
    }
}