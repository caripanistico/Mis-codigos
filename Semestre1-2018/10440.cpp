//https://github.com/morris821028/UVa/blob/master/volume104/10440%20-%20Ferry%20Loading%20II.cpp
#include <stdio.h>

int main() {
    int s[1440];
    int n, t, m, c;                                     //dado un numero de casos, seguido por 3 enteros, que representan el numero de autos que un ferry puede cargar
    int i, j;                                           //el tiempo que se demora en cruzas un rio para dejar los autos, y el numero de autos que llega tal dia, respectivamente
    scanf("%d", &c);                                    //se debe saber cuando tiempo ha pasado desde que empezo el dia, hasta que se entrego el ULTIMO auto al otro lado del rio
    while(c--) {                                        //y cuantos viajes tiene que hacer MINIMO para pasar todos los autos del dia
        scanf("%d %d %d", &n, &t, &m);                  //hay que tomar en cuentra que tanto para ir y venir, el ferry, se demora el mismo tiempo en minutos
        t *= 2;                                         //y que el ferry debe llevar la cantidad maxima de vehiculos que puede llevar
        int tot = 0, act = 0;                           //por lo que se debe calcular el tiempo que debe esperar para llenar el ferry, y el tiempo que se demora tanto en ir y venir del otro lado del rio
        for(i = 0; i < m; i++)                          //el loop calcula rapidamente cuantos viajes tiene que hacer como minimo y lo utiliza como contador, utilizando el operador de modulo
            scanf("%d", &s[i]);                         //por lo que el loop solo se ocupa para calcular la cantidad de tiempo en el que el ultimo auto ha sido entregado al otro lado del rio
        for(i = (m + n - 1)%n; i < m; i += n)
            act = tot > s[i] ? tot : s[i], tot = act + t;
        printf("%d %d\n", tot - t/2, (m + n - 1)/n);
    }
    return 0;
}
