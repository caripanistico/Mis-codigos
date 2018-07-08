//https://github.com/shahidul2k9/problem-solution/blob/master/uva%20online%20judge/10670%20Wrok%20Reduction.cc
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int N, M, L;
int memo[MAX];

int A, B;
struct List{
    char name[17];
    int cost;
};
bool callback(List a, List b){                              //un problema de optimizacion, dado una cantidad de papel, y una cantidad de papel objetivo
    if(a.cost != b.cost)                                    //se debe encontrar la cantidad de dinero que se debe pagar a distintas agencias, para solucionar el problema de papeleo
        return a.cost < b.cost;                             //donde el primer precio reduce el papeleo en 1 unidad, y el segundo, el papeleo a la mitad (rondando hacia abajo)
    return strcmp(a.name, b.name) < 0;                      //el problema es encontrar y ordenar las mejores agencias que hacen este trabajo, en el menor precio posible
}
int minCost(int n){

    if(memo[n] != -1) return memo[n];
    int cost = INT_MAX;


    int next = n/2;
    if(next >= M && (n - next)*A > B) cost = min(cost, minCost(next) + B);          //por lo que el problema se reduce a encontrar una combinacion optima, para cada agencia, y luego imprimirlos ordenadamente por costo


    if(cost == INT_MAX) cost = A*(n - M);
    return memo[n] = cost;

}
int main(){
   // freopen("input.txt", "r", stdin);                         //por lo que el programa separa el problema en 2 secciones, el calculo de costo de agencias y la de seleccion de agencias.
    int test;
    int cs = 1;                                                 //minCost busca la combinacion mas optima del reduccion de papeleo y costo
    List lis[100];                                              //mientras que en main, simplemente ordena este ultimo dato sobre todas las agencias

    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &N, &M, &L);
        for(int i = 0; i < L; i++){
            getchar();
            scanf("%[^:]:%d,%d", lis[i].name, &A,&B);

            memset(memo, -1, sizeof(memo));
            memo[M] = 0;
            lis[i].cost = minCost(N);
        }
        sort(lis, lis + L, callback);
        printf("Case %d\n", cs++);
        for(int i = 0; i < L; i++)
            printf("%s %d\n", lis[i].name, lis[i].cost);
    }

    return 0;
}
