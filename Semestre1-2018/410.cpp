#include <bits/stdc++.h>
using namespace std;

bool callback(int a, int b){
    return a > b;
}
int main(){
    int C, S, cs;
    double avg, imbalance;
    cs = 0;
    int mass[10];
    while(scanf("%d %d", &C, &S) == 2){

        for(int i = 0; i < S; i++)
            scanf("%d", &mass[i]);
        avg = (double)accumulate(mass,mass+S,0)/C;                      //dado un numero C y un numero S, se debe calcular el "imbalance" de masas de unos especimenes que deben estar guardados en C camaras
        for(int i = S; i< 2*C; i++)                                     //las camaras pueden tener como maximo 2 especimenes, y cada especimen tiene su valor de masa
            mass[i] = 0;                                                //el imbalance es calculado como la suma de los valores absolutos de CM - AM, donde CM es la cantidad de masa en la camara, y AM es el promedio de todas masas en relacion a la cantidad de camaras
        sort(mass, mass+2*C,callback);                                  //por lo que, no solo se debe calcular el imbalance, sino tambien el imbalance menor posible, dada la combinacion eficiente entre masas en las camaras

        imbalance = 0;

        printf("Set #%d\n", ++cs);                                      //un problema dificil de entender, pero en la practica, muy facil de resolver
        for(int i = 0; i< C; i++){                                      //como la cantidad de datos no es muy grande, se puede calcular todas las combinaciones posibles, calcular sus imbalances, e imprimir el menor de ellos
            printf(" %d:",i);                                           //que es efectivamente lo que hace este programa, guardando las combinaciones juntos con sus imbalances en un arreglo, y ordenandolos

            if(mass[2*C-i-1]){
                printf(" %d", mass[2*C-i-1]);

            }
            if(mass[i])
                printf(" %d", mass[i]);                                 //una vez encontrada la mas eficiente, saca los datos de los arreglos correspondientes, y los imprime
                                                                        //siguiendo el orden que se pide del output
            imbalance += fabs(mass[i] + mass[2*C-i-1] - avg);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}
