#include <cstdio>
#include <algorithm>
int main() {
  int x[1000005], n;                                 //se crea un array grande
  while (scanf("%d", &n) != EOF) {                   //mientras el archivo que se lee no llegue al caracter final 'EOF'
    for (int i = 1; i <= n; ++i) scanf("%d", &x[i]); //se lee cada numero
    std::sort(x, x + n + 1);                         //se ordenan
    int a2 = 0, a3, tmp = ((double)n / 2 > n / 2 ? n / 2 + 1 : n / 2); //se crea un entero temporal, que determinara si el numero de numeros vistos es par o impar
    for (int i = 1; i <= n; ++i) {
      if (x[i] == x[tmp]) ++a2;     //busca cuantos numeros satisfacen la propiedad
      else if (n % 2 == 0 && x[i] == x[tmp + 1]) ++a2;
    }
    if (n % 2 == 0) a3 = x[tmp + 1] - x[tmp] + 1; //se buscan cuantas combinaciones existen
    else a3 = 1;
    printf("%d %d %d\n", (n / 2 == 0 ? x[1] : x[tmp]), a2, a3);
  }
  return 0;
}