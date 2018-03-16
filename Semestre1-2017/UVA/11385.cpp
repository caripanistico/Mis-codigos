#include <stdio.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string.h>
using namespace std;

int main() {
    map<long long, int> R;
    int i, j;
    int t, n, A[105];               //se empieza creando un mapa de numeros muy grandes, junto con un entero. el numero grande indica el numero de fibonacci, y el entero, la posicion dentro del string de salida
    string s;
    long long f1 = 1, f2 = 2, f3;
    R[f1] = 0, R[f2] = 1;
    for(i = 2; i <= 50; i++) {      //utilizando recursividad, llena los valores dentro del mapa, junto con su correspondiente numero de recursividad
        f3 = f1+f2;
        f1 = f2, f2 = f3;
        R[f3] = i;
    }
    cin >> t;
    while(t--) {
        cin >> n;
        for(i = 0; i < n; i++)                  //ahora pregunta por el numero de tests, y el numero de letras a leer en el test correspondiente
            cin >> A[i];
        cin.ignore(100, '\n');
        getline(cin, s);
        char buf[105];
        memset(buf, ' ', sizeof(buf));      //selecciona memoria para llenar el string
        int len = s.length();
        for(i = 0, j = 0; i < n; i++) {
            while(j < len && (s[j] < 'A' || s[j] > 'Z')) j++;   //utiliza el iterador del mapa para encontrar los valores correspondientes
            buf[R[A[i]]] = s[j];
            j++;
        }
        for(i = 100; buf[i] == ' '; i--);          //los pone en la posicion en la que pertenece, e imprime el output.
        buf[i+1] = '\0';
        for(i = 0; buf[i]; i++)
            putchar(buf[i]);
        puts("");
    }
    return 0;
}
/*
2
11
13 2 89 377 8 3 233 34 144 21 1
OH, LAME SAINT!
15
34 21 13 144 1597 3 987 610 8 5 89 2 377 2584 1
O, DRACONIAN DEVIL!
*/
