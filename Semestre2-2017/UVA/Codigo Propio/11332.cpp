#include <bits/stdc++.h>
using namespace std;

int foo(int x){
	if(x<10) return x;
	int suma = 0;
	while(x!=0){
		suma += x%10;
		x/=10;
	}
	return foo(suma);
}

int main(){
	int n;
	while(scanf("%d",&n)==1 && n!=0){
		printf("%d\n", foo(n));
	}
}