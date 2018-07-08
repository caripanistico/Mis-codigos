//https://github.com/morris821028/UVa/blob/master/volume110/11054%20-%20Wine%20trading%20in%20Gergovia.cpp
#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {                  //dentro de una ciudad, habitantes buscan tanto vender como comprar cierta cantidad de vino
        long long sum = 0, ans = 0, x;                  //sin embargo, el problema esta en que transportar una cantidad de vino cuesta trabajo, donde cada unidad de vino equivale a 1 unidad de trabajo
        while(n--) {                                    //dependiendo de cuantos habitantes quieren vender y comprar, se debe encontrar una ruta optima
            scanf("%lld", &x);                          //de la cual se utilice la menor cantidad de trabajo posible, satisfaciendo la compra-venta de cada uno de los habitantes
            sum += x;                                   //el truco esta en no llevar todas las botellas posibles de las casas adyacentes, sino una cantidad de la cual, cuando vuelva a la casa, tenga en total 0 vino cargado
            if(sum < 0)
                ans -= sum;                             //el problema utiliza 2 enteros, uno esta al tanto de la compra-venta
            else                                        //y el otro, del trabajo acumulado
                ans += sum;                             //sin embargo, la unica forma de encontrar una solucion es usando una solucion greedy
        }                                               //y este programa es la reduccion maxima de la solucion greedy
        printf("%lld\n", ans);
    }                                                   //esta solucion viene de la idea "¿porque voy a llevar mas que lo que me esta pidiendo?"
    return 0;                                           //es decir, dependiendo de la casa que quiere comprar vino, los va priorizando, dependiendo de que tan lejos estan
}                                                       //de la casa o casas que SATISFAGA/N lo que pide un cliente en particular
