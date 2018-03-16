/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 */
 
#include <stdio.h>
 
static char s[64];
 
int main(){
    register unsigned int i;        //se creaa un entero sin signo, que por alguna razon esta guardado en un registro
    unsigned sum, found;
 
    while(gets(s)){
        unsigned int bit = 128;     // se puede ver facilmente que el patron que sigue son numeros binarios, es decir, dependiendo de la posicion, es 2 elevado el numero de la posicion, empezando desde 0 
        i = sum = found = 0;        //cada caracter del mensaje, es una suma de numeros binarios, que en total dan el codigo en ASCII del caracter
        if(s[i] != '|') continue;   //no se quiere nada que empieze sin |
 
        for(; s[i]; ++i){
            if(s[i] == ' ')
                bit >>= 1;          // si no encuentra un 'o', mueve el bit hacia la derecha
            else if(s[i] == 'o'){
                sum += bit;         // si encuentra un 'o', agrega el bit a la suma y luego mueve a la derecha
                bit >>= 1;
            }
        }
 
        printf("%c", sum);          //se imprime la suma como un caracter, haciendo el cast de los bits
    }
    return 0;
}