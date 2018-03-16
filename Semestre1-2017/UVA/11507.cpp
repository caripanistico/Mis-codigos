#include <stdio.h>
#include <string.h>			//Bender's Rodriguez problem
int main() {
    int n;						
    char cmd[100000][3];				//Se crea un arreglo de char, para crear strings, de un tamaño muy grande
    while(scanf("%d", &n) == 1 && n) {	//Se pregunta por el numero de movimientos, y si existe un valor distinto de NULL
        for(int i = 0; i < n; i++)
            scanf("%s", cmd[i]);		//Se pregunta por el string, separandolos en caracteres singulares
        int dir = 0;					//Se crea un int que indica el tipo de input obtenido:
        for(int i = 0; i < n; i++) {	//+x(0), -x(1), +y(2), -y(3), +z(4), -z(5)
            if(!strcmp(cmd[i], "No"))	//Utiliza la funcion de comparacion de strings
                continue;
            if(!strcmp(cmd[i], "+z")) {
                if(dir == 0)        dir = 4;//+x->+z 	//Crea un numero especifico para cada combinacion posible de posiciones 
                else if(dir == 1)   dir = 5;//-x->-z
                else if(dir == 4)   dir = 1;//+z->-x
                else if(dir == 5)   dir = 0;//-z->+x
            }
            if(!strcmp(cmd[i], "-z")) {
                if(dir == 0)        dir = 5;//+x->-z
                else if(dir == 1)   dir = 4;//-x->+z
                else if(dir == 4)   dir = 0;//+z->+x
                else if(dir == 5)   dir = 1;//-z->-x
            }
            if(!strcmp(cmd[i], "+y")) {
                if(dir == 0)        dir = 2;//+x->+y
                else if(dir == 1)   dir = 3;//-x->-y
                else if(dir == 2)   dir = 1;//+y->-x
                else if(dir == 3)   dir = 0;//-y->+x
            }
            if(!strcmp(cmd[i], "-y")) {
                if(dir == 0)        dir = 3;//+x->-y
                else if(dir == 1)   dir = 2;//-x->+y
                else if(dir == 2)   dir = 0;//+y->+x
                else if(dir == 3)   dir = 1;//-y->-x
            }
        }
        if(dir == 0)    puts("+x");			//y, al finalizar el for, dependiendo del valor de dir, se imprime tal direccion, en forma de string.
        if(dir == 1)    puts("-x");
        if(dir == 2)    puts("+y");				
        if(dir == 3)    puts("-y");
        if(dir == 4)    puts("+z");
        if(dir == 5)    puts("-z");
    }
    return 0;
}
