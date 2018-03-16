#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;                  //este problema es simple
    while(scanf("%d", &n) == 1) {
        int old = 0, young = 2147483647; //se crean los valores maximos que puede ser cada entero, porque luego los enteros son utilizados para comparar
        string oa, ya, name;
        int dd, mm, yy;
        while(n--) {
            cin >> name >> dd >> mm >> yy; //basicamente lo que hace es guardar el mayor y el menor de todos, y al final del input, imprime los que estan actualmente guardados
            dd = dd+mm*100+yy*10000; //si se encuentra uno mas joven o viejo, se sobreescribe con la nueva informacion
            if(dd > old)    old = dd, oa = name;
            if(dd < young)  young = dd, ya = name;
        }
        cout << oa << endl;
        cout << ya << endl;
    }
    return 0;
}
