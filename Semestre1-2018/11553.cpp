#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int grid[n][n], choice[n];
		for (int i = 0; i < n; i++){
			choice[i] = i;
			for (int j = 0; j < n; j++)
				scanf("%d",&grid[i][j]);
		}
		int minimo = INT_MAX;
		do{
			int suma = 0;
			for (int i = 0; i < n; i++){
				suma += grid[i][choice[i]];
			}
			minimo = min(suma,minimo);
		} while (next_permutation(choice, choice+n));
		printf("%d\n", minimo);
	}
	return 0;
}