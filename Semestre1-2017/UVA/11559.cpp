#include <bits/stdc++.h>
using namespace std;

// Event Planning

long N, B, H, W;	//el programa tomara a los valores iniciales como tipo long int, N para el numero de integrantes, B para el budget, H para la cantidad de hoteles, W para el numero de fines de semana disponibles.
long p, a; 			//tambien crea 2 valores long int, que son p, el precio de una habitacion en el hotel, y a, la cantidad de camas del correspondiente dia.
 
int main() {
    while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4) { //El programa utiliza una comparación con scanf, que analiza si la cantidad de caracteres introducidos es correcta, en este caso 4.
        long cost = 0;		//se crea un long int, que almacenará el mejor costo del hotel, es decir, el fin de semana donde existan vacantes y a un precio barato.
        for(int i = 0; i < H; i++) {
            scanf("%d", &p);	//se utiliza el scanf() debido a que ha sido probado que es mas rapido que el conocido cin, de la libreria IOStream
            for(int j = 0; j < W; j++) {
                scanf("%d", &a);	//se "captura" cada valor del numero de camas del presente hotel, y se busca el fin de semana con camas disponibles, y luego calcula entre estos, cual es el mas barato.
                if(a >= N && N * p <= B)
                    if(cost == 0 || N * p < cost)
                        cost = N * p; //si existe un valor mas pequeño, reemplaza el valor actual en cost.
            }
        }
        printf(cost == 0? "stay home\n" : "%d\n", cost); //Luego de salir del loop for(i), el programa imprime, mediante un operador ternario, tambien conocido como inline if.
    }
}