#include <cstdio>

using namespace std;

/*
 * Sai Cheemalapati
 * UVA 12356: Army buddies
 *
 */
int S, B, L, R;
int LS[1000100];
int RS[1000100];				//se crean propiedades y arreglo de un tamaño gigantesco

int main() {
	for(;;) {
		scanf("%d %d", &S, &B);		//se analizan los valores S y B del problema
		if(S == 0 & B == 0) break;	//si ambos son 0, el programa sale del loop
		for(int i = 0; i < S + 1; i++) {
			LS[i] = i - 1;					//se agregan los valores a los arreglos, uno siendo con valores del buddy de la izquierda, y el otro, de la derecha.
			RS[i] = i + 1;
		}
		for(int i = 0; i < B; i++) {
			scanf("%d %d", &L, &R);
			if(LS[L] < 1) printf("* "); //lee los valores de cada linea siguiente, y los revisa, si es que siguen existiendo,de otra forma, se imprime el asterisco
			else printf("%d ", LS[L]);
			if(RS[R] > S) printf("*\n");	//se imprimen los valores correspondientes
			else printf("%d\n", RS[R]);

			LS[RS[R]] = LS[L];	//la posicion donde estaba el de la derecha, se actualiza, quitando los 'buddies' muertos y moviendo a los que siguen vivos.
			RS[LS[L]] = RS[R];	//lo mismo ocurren con el de la izquierda
		}
		printf("-\n");	//al finalizar el loop, el programa imprime este caracter, para separar de los demas tests
	}
}