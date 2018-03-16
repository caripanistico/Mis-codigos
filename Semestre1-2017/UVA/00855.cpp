#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int t, r, c, f;
  int streets[50000];               //se crean int muy grandes para tener todos los datos
  int avenues[50000];

  cin >> t;

  while (t--) {
    cin >> r >> c >> f;             //se leen los primeros inputs

    for (int i = 0; i < f; i++) {
      cin >> streets[i] >> avenues[i];  //se leen los arrays
    }

    sort(streets, streets + f);  //se llama la funcion sort, para ordenar los datos
    sort(avenues, avenues + f);  

    pair<int,int> result;

    result.first = streets[(f-1)/2];   //se crea un par, que tiene el valor de al medio, puesto que siempre es el que es mas cercano a todos
    result.second = avenues[(f-1)/2];

    cout << "(Street: " << result.first << ", Avenue: " << result.second << ")" << endl; //se imprime el par
  }

  return 0;
}
