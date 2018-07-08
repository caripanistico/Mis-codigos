//https://github.com/morris821028/UVa/blob/master/volume110/11085%20-%20Back%20to%20the%208-Queens.cpp
#include <stdio.h>
#include <stdlib.h>
int ans[92][9], at = -1;
int y[9], used[9] = {};
int check(int idx, int k) {
    int i;
    for(i = 1; i < idx; i++) {
        if(abs(i-idx) == abs(y[i]-k))
            return 0;
    }
    return 1;
}                                                       //un problema de ajedrez, donde se debe encontrar una combinacion de movimientos de 8 reinas
void dfs(int idx) {                                     //en las que cada reina esta en una determinada fila, pero cada reina puede atacar a las demas tanto horizontal como diagonalmente, pero no verticalmente
    int i;                                              //por lo tanto, el problema es buscar una combinacion de movimientos tales que cada reina de cada fila
    if(idx == 9) {                                      //no pueda ser atacada por otra reina, tanto horizontal como diagonalmente.
        ++at;                                           //estos movimientos solo pueden ser verticales
        for(i = 1; i <= 8; i++) {
            ans[at][i] = y[i];
        }
        return ;                                        //como se ve en el programa, el usuario usa un arbol de busqueda y le aplica una busqueda en profundidad
    }                                                   //para encontrar UN conjunto de movimientos posible, que no siempre sera el de menos movimientos
    for(i = 1; i <= 8; i++) {
        if(!used[i] && check(idx, i)) {                 //esto lo hace para todas las combinaciones posibles, que son 81, e imprime el numero de movimientos menor
            used[i] = 1;
            y[idx] = i;
            dfs(idx+1);
            used[i] = 0;
        }
    }
}
int main() {
    dfs(1);
    int i, j, cases = 0, a[9];
    while(scanf("%d", &a[1]) == 1) {
        for(i = 2; i <= 8; i++)
            scanf("%d", &a[i]);

        int move = 0xfffff;
        for(i = 0; i <= at; i++) {
            int tmp = 0;
            for(j = 1; j <= 8; j++)
                if(ans[i][j] != a[j])
                    tmp++;
            if(tmp < move)  move = tmp;
        }
        printf("Case %d: %d\n", ++cases, move);
    }
    return 0;
}
