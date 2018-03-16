#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int main() {
    scanf("%*d");
    int n, m, x;
    while(scanf("%d %d", &n, &m) == 2) {
        map<int, int> r;
        while(n--)
            scanf("%d", &x), r[x]++;                        //el programa busca cuando elementos se tienen que eliminar en total, para que 2 arreglos contengan los mismos elementos
        while(m--)                                          //este programa aprovecha la funcionalidad de map, haciendo que cada vez que se encuentre un numero, se aumente su valor
            scanf("%d", &x), r[x]--;                        //luego, cuando se lee el segundo arreglo, se hace lo mismo, pero en vez que agregar la cantidad de veces, las quita
        x = 0;                                              //el mapa esta definido como <numero encontrado, veces encontradas>
        for(map<int,int>::iterator it = r.begin();
            it != r.end(); it++)                            //luego, ve cuales numeros no se han encontrado en el segundo arreglo, y se agrega a un contador.
            x += abs(it->second);                           //imprime la cantidad de numeros que se deben quitar, y listo!
        printf("%d\n", x);
    }
    return 0;
}
