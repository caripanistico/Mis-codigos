//https://github.com/ajahuang/UVa/blob/master/UVa%2010763%20-%20Foreign%20Exchange.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
    int n;
    while (cin >> n, n != 0)
    {
        vector<int> original(n), target(n);                     //un problema simple, sobre resolucion de intercambios
        for (int i = 0; i < n; ++i)                             //dado un numero de candidatos, se debe ver si existen candidatos a intercambio
            cin >> original[i] >> target[i];                    //de tal forma que, si existe un candidato que quiere ir de A a B, y otro de B a A
                                                                //entonces el programa de intercambio si se puede hacer, solo si todos los candidatos tienen un candidato compatible
        sort(original.begin(), original.end());
        sort(target.begin(), target.end());                     //por lo tanto, el problema se reduce a encontrar al menos 1 par de candidatos incompatible para imprimir 'no'
 
        if (original == target)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}