#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int t, n, x, ans, cnt, block;
map<int, int> lastseen;          //se crea un mapa de enteros con enteros, uno representando el numero unico del copo de nieve y el otro, el numero de la posicion ultima vez visto
int main() {
    cin >> t;
    while(t--) {
    cin >> n;
    lastseen.clear();
    ans = 0, cnt = 0, block = 0;
    for(int i=1; i<=n; i++) {
        cin >> x;
        int lx = lastseen[x];
        if(lx != 0) {
        block = max(block, lx);   //ahora mediante muchas funciones, basicamente lo que hace es guardar en el mapa la ultima vez que se ha visto tal numero 
        cnt = i-block-1;
        }
        cnt++;                   //ya que tan pronto se encuentra un numero repetido, se detiene
        lastseen[x] = i;
        ans = max(ans, cnt);
    }
    cout << ans << '\n'; //e imprime el string hasta la posicion anterior del numero repetido
    }
}