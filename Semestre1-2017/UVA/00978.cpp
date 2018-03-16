#include <cstdio>
#include <set>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int cases;

    scanf("%d", &cases);
    while (cases--) {
        int b, sg, sb, temp;
        multiset< int, greater<int> > green, blue;
        vector<int> survivors;                                  //se crean multisets, uno para el equipo verde y uno para el equipo azul, junto con un vector de 'sobrevivientes'

        scanf("%d %d %d", &b, &sg, &sb);
        for (int i = 0; i < sg; i++)
            scanf("%d", &temp), green.insert(temp);             //se leen los datos, y se agregan a su respectivo multiset
        for (int i = 0; i < sb; i++)
            scanf("%d", &temp), blue.insert(temp);

        while (!green.empty() && !blue.empty()) {
            for (int i = 0; i < b && !green.empty() && !blue.empty(); i++) {
                survivors.push_back(*green.begin() - *blue.begin());    //mientras ninguno de los multisets este vacio, se van agregando al sobreviviente de la batalla en el vector 
                green.erase(green.begin()); blue.erase(blue.begin());   //ya que este sobreviviente pertenece al equipo vencedor, y esto se va repitiendo hasta que uno o ambos sets esten vacios
            }
            for (int i = 0; i < survivors.size(); i++) {
                if (survivors[i] < 0)
                    blue.insert(-survivors[i]);
                else if (survivors[i] > 0)              //si el superviviente tiene un valor negativo, implica que es del equipo azul, de otra forma, es del equipo verde y son reagregados para seguir la batalla
                    green.insert(survivors[i]);
            }
            survivors.clear();
        }

        if (green.empty() && blue.empty())
            printf("green and blue died\n");       //si ambos sets estan vacios, entonces ambos equipos murieron
        else {
            multiset<int, greater<int> > *winner;

            if (green.empty()) {
                printf("blue wins\n");              //de otra forma, si uno de los sets esta vacio, implica que el otro set es del equipo vencedor
                winner = &blue;
            } else if (blue.empty()) {
                printf("green wins\n");
                winner = &green;
            }

            for (multiset<int, greater<int> >::iterator it = winner->begin();
                    it != winner->end(); it++) {
                printf("%d\n", *it);                 //se crea un puntero que apunta al set vencedor y se imprime los sobrevivientes
            }
        }

        if (cases)
            printf("\n");  
    }

    return 0;
}
