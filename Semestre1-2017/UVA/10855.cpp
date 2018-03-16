#include <stdio.h>
#include <string.h>

char big[500][500], small[500][500];            //Se crean 2 matrices de gran tamaño de caracteres, uno para el cuadrado grande, y otro para el pequeño
int find(int n, int m) {                        //Este problema utiliza funciones, como esta, que busca el cuadrado pequeño, en la rotacion correspondiente, en el cuadrado grande
    int ans = 0, i, j, k, l;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i+m <= n && j+m <= n) {          //mientras el tamaño del pequeño, no sobrepase al del grande..
                int cnt = 0;                    
                for(k = 0; k < m; k++) {
                    for(l = 0; l < m; l++) {
                        if(big[i+k][j+l] == small[k][l])    //Si encuentra un cuadrado igual al pequeño, se aumenta el contador
                            cnt++;
                    }
                }
                if(cnt == m*m)      //Si el contador es igual a la dimension del cuadrado pequeño, se aumenta el valor de ans, que es el numero de veces que se ha encontrado el cuadrado pequeño, en el grande
                    ans++;
            }
        }
    }
    return ans;
}
void rotate(int n) {                //Esta funcion crea una matriz auxiliar, para rotar los valores del cuadrado pequeño, en 90° grados, en sentido de las agujas del reloj
    char tmp[n][n];
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            tmp[i][j] = small[n-j-1][i];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
           small[i][j] = tmp[i][j];
    }
}
int main() {
    int n, m, i;
    while(scanf("%d %d", &n, &m) == 2) {    //se analizan los valores de N y m
        if(n == 0 && m == 0)                
            break;
        for(i = 0; i < n; i++)              //agrega los valores a cada matriz..
            scanf("%s", big[i]);


        for(i = 0; i < m; i++)
            scanf("%s", small[i]);
        for(i = 0; i < 4; i++) {
            if(i)
                putchar(' ');
            printf("%d", find(n, m));   //ejecuta la funcion find, y luego rotate, que hacen lo ya dicho a las correspondientes matrices
            rotate(m);
        }
        puts("");               //y el programa termina.
    }
    return 0;
}