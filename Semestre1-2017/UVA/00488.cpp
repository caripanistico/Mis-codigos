#include <iostream>

using namespace std;

int main(){
    int n;
    bool line = false;
    
    cin >> n;
    while(n-- != 0){      //se leen los valores
        int A, F;
        cin >> A >> F;

        for(int times = 0 ; times < F ; ++times){
            if(line)
                cout << endl;
            else
                line = true;    //se analiza la linea de los numeros

            for(int i = 1 ; i <= A ; ++i){
                for(int j = 1 ; j <= i ; ++j) //se imprimen la onda superior, es decir del menor al mayor
                    cout << i;
                cout << endl;
            }
            for(int i = A - 1; i >= 1 ; --i){
                for(int j = i ; j >= 1 ; --j) //se imprime la onda inferior, es decir del mayor al menor
                    cout << i;
                cout << endl;    //se reinicia el loop hasta completar todas las veces
            }
        }
    }
}
