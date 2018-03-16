#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

struct Argus {
    int ID, p, v;
};
struct cmp {
    bool operator() (Argus a, Argus b) {
        if(a.v != b.v)
            return a.v > b.v;
        return a.ID > b.ID;
    }
};

int main() {
    priority_queue<Argus, vector<Argus>, cmp> Q; //se crea un priority_queue de structs 'Argus', vector de 'Argus' y de struct 'cmp'
    char str[50];
    int ID, p, k;
    Argus tmp;
    while(scanf("%s", str) == 1) {
        if(str[0] == '#')               //se preguntan por los strings, mientras estos sean distintos de #, crea un struct 'Argus' temporal, agrega los datos a el, y los entrega al priority_queue
            break;
        scanf("%d %d", &ID, &p);
        tmp.ID = ID, tmp.p = tmp.v = p;
        Q.push(tmp);
    }
    scanf("%d", &k);    //luego se pregunta por el numero de registros a entregar
    while(k--) {
        printf("%d\n", Q.top().ID);
        tmp = Q.top();
        Q.pop();
        tmp.v += tmp.p;    //luego imprime los datos dentro del queue, por prioridad, es decir, el que tiene mas prioridad primero y luego los siguientes
        Q.push(tmp);
    }
    return 0;
}
