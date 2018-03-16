#include <stdio.h>

int main() {
    int t, cases = 0;
    char s[1005];
    scanf("%d", &t);                //este programa lo que hace es indicar que jugador gana el juego
    while(t--) {                    //como lo hace? va calculando la suma de los numeros constantemente
        scanf("%s", s);
        int cnt[10] = {}, i, sum = 0;
        for(i = 0; s[i]; i++) {
            cnt[s[i]-'0']++;
            sum += s[i]-'0';        //separa cada digito en un arreglo
        }
        int flag = 0;
        while(1) {
            for(i = sum%3; i < 10; i += 3) {
                if(cnt[i] != 0) {
                    cnt[i]--;
                    sum -= i;           //a cada digito lo vuelve 0, y si la suma no es multiplo de 3, entonces gana el otro
                    break;              //y sigue haciendo esto hasta que se detecte que no se puede sacar una suma que sea multiplo de 3
                }
            }
            if(i >= 10) break;
            flag = 1-flag;
        }
        printf("Case %d: %c\n", ++cases, flag ? 'S' : 'T');
    }
    return 0;
}
