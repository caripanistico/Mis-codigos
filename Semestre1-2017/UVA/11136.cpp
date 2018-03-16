#include <stdio.h>
#include <set>
using namespace std;

int main() {
    int n, m, x, i, tmp;
    while(scanf("%d", &n) == 1 && n) {          //se crea un multiset, con multiples iteradores
        multiset<int> S;
        multiset<int>::iterator it, jt, kt;

        long long sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &m);       
            while(m--) {
                scanf("%d", &x);    //se escanea el numero de casos y luego, en un while, los numeros positivos, y los inserta en el multiset
                S.insert(x);
            }
            it = S.begin(), jt = S.end(); //busca los primeros y los ultimos, y luego resta sus valores y los agrega a una suma total
            jt--, sum += *jt - *it;
            S.erase(it);
            S.erase(jt);    //luego elimina el primero y el ultimo
            m = 2*(n-i+1);
            if(S.size() > m) { //si el tamaño del multiset es mayor que m, esto implica que la promocion lleva mas tiempo que lo planeado, por lo que termina
                tmp = n-i+1;
                while(tmp)  it++, tmp--;
                tmp = n-i+1, kt = S.end();  //y se borran los iteradores
                while(tmp)  kt--, tmp--;
                S.erase(it, kt);
            }
        }
        printf("%lld\n", sum);  //al final, imprime el valor total pagado
    }
    return 0;
}
