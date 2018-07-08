//https://github.com/ajahuang/UVa/blob/master/UVa%2010020%20-%20Minimal%20coverage.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment
{
    int L, R;
};

bool comp(const Segment &s1, const Segment &s2)
{
    return s1.L < s2.L;
}

int main()                                                                      //dado un numero M, se debe ver si existe una combinacion de rectas Li, Ri, que son introducidas en el input,
{                                                                               //tales que puedan crear una linea de 0 a M en un eje X
    int T;                                                                      //aqui tambien se debe recurrir a una busqueda de combinaciones
    cin >> T;                                                                   //de rectas, e imprimir la que utiliza las menos posibles
    while ( T-- )
    {
        int M;
        cin >> M;
        vector<Segment> S(1);
        while (cin >> S[0].L >> S[0].R, !(S[0].L == 0 && S[0].R == 0))
            S.push_back(S[0]);
        // Sort S by increasing left endpoint.
        sort(S.begin() + 1, S.end(), comp);
        int curL = 0, rReach = 0;
        size_t i = 1;
        vector<Segment> segments;                                               //el problema se puede resolver rapidamente, solo se necesitan los datos, y despues una suma de largos de las rectas
        while (rReach < M)                                                      //tales que el largo de ella sea exactamente M, almacenando las combinaciones validas
        {                                                                       //y seleccionando la que utiliza menos
            // Choose the segment which L <= curL and extends the farthest 
            // to right.
            int newL = curL;
            size_t farthest = 0;    
            for ( ; i < S.size(); ++i)
            {
                if (S[i].L > curL)
                    break;
                else if (S[i].R >= newL)
                {
                    newL = S[i].R;
                    farthest = i;
                }
            }
            if (farthest == 0)
                break;
            segments.push_back(S[farthest]);
            curL = rReach = newL;
        }
        if (rReach >= M)
        {
            cout << segments.size() << endl;
            for (size_t i = 0; i < segments.size(); ++i)
                cout << segments[i].L << " " << segments[i].R << endl;                      //si existe una combinacion, lo imprime y si no, imprime '0'
        }
        else
            cout << "0" << endl;
        if (T)
            cout << endl;
    }
    return 0;
}