//https://github.com/morris821028/UVa/blob/master/volume105/10576%20-%20Y2K%20Accounting%20Bug.cpp
#include <stdio.h>

int main() {
    int s, d;
    while(scanf("%d %d", &s, &d) == 2) {
        int y_surplus = -1, year, i, j;
        for(year = (1<<12)-1; year >= 0; year--) {              //este problema me costo entender ya que no se precisa de mucha informacion
            int tot = 0, flag = 1;                              //pero por lo que entendi, dado 2 enteros, que representan ganancias o deficit en una compañia
            for(i = 0; i < 12; i++) {                           //se debe encontrar lo que se gana en un año entero
                if((year>>i)&1)                                 //sin embargo, no sabemos que meses hay ganancias o perdidas, pero el problema nos da una pista
                    tot += s;                                   //la empresa solo hace 1 reporte de ganancias de 5 meses consecutivos, y que en el año a calcular
                else                                            //existian solo 8 reportes, es decir 1 de ellos de ser ganancia y los demas, de perdida
                    tot -= d;                                   //dependiendo de las combinaciones resultantes, debemos decir si existe una combinacion en donde
                if(i < 8) {                                     //la empresa termina el año en ganancias, o si en todas las combinaciones posibles, siempre existe un deficit
                    int tmp = 0;
                    for(j = i; j < i+5; j++)
                        if((year>>j)&1)
                            tmp += s;
                        else
                            tmp -= d;
                    if(tmp >= 0)    flag = 0;
                }
            }
            if(flag && y_surplus < tot)
                y_surplus = tot;                            //entonces, despues de hacer todas las combinaciones posibles, se debe imprimir el que mas generaba ingresos, si existian multiples ganancias
        }                                                   //o imprimir deficit si en todas las combinaciones daba un deficit
        if(y_surplus < 0)   puts("Deficit");
        else
            printf("%d\n", y_surplus);
    }
    return 0;
}
