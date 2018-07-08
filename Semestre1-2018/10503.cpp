//https://github.com/morris821028/UVa/blob/master/volume105/10503%20-%20The%20dominoes%20solitaire.cpp
#include <stdio.h>
int x[50], y[50];
int used[50];
int n, m, flag;
void dfs(int idx, int l) {
    if(idx == n) {
        if(l == x[1])
            flag = 1;
        return;
    }
    int i;
    for(i = 2; i < m+2; i++) {
        if(used[i] == 0) {
            if(l == x[i]) {
                used[i] = 1;
                dfs(idx+1, y[i]);                       //nuevamente, un problema de combinaciones posibles, dado 2 dominos iniciales, separados por n espacios
                used[i] = 0;                            //se debe probar si se puede encontrar n de m piezas, tales que una los 2 dominos iniciales
            }                                           //aqui tambien se recurre al uso de grafos para encontrar todas las combinaciones posibles
            if(l == y[i]) {                             //por lo que se utiliza una funcion de busqueda de profundidad recursiva
                used[i] = 1;
                dfs(idx+1, x[i]);
                used[i] = 0;
            }
        }
    }
}
int main() {
    int i;
    while(scanf("%d", &n) == 1 && n) {                  //si el dfs encuentra al menos 1 combinacion valida, entonces el programa devuelve "yes",
        scanf("%d", &m);                                //de otra forma devuelve "no"
        for(i = 0; i < m+2; i++) {
            scanf("%d %d", &x[i], &y[i]);
            used[i] = 0;
        }
        flag = 0;
        dfs(0, y[0]);
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
