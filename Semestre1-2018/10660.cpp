#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	scanf("%d",&t);
	while(t--){
		int city[5][5][2] = {{{0}}}; //0: city numeration, 1: area citizens
		int areaDistance[5][5][25] = {{{0}}}; //5x5 grid for each area number, each grid representing distance to each other area
		int ans[25];
		scanf("%d",&n);
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				city[i][j][0]=(5*i)+j;
			}
		}
		int row, column, mult;
		for (int i = 0; i < n; i++){
			scanf("%d %d",&row,&column);
			scanf("%d",&city[row][column][1]);
		}
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				for (int k = 0; k < 5; k++){
					for (int l = 0; l < 5; l++){
						mult = city[k][j][1];
						if(mult==0 || (i==k && j==l)) continue;
						areaDistance[k][l][i*5+j] = (abs(i-k)+abs(j-l))*mult;
					}
				}
			}
		}
		int sum;
		for (int k = 0; k < 25; k++){
			for (int i = 0; i < 5; i++){
				for (int j = 0; j < 5; j++){
					if(city[i][j][1]!=0)
						sum+= areaDistance[i][j][k];
				}
			}												//organizar mejores 5 resultados
			ans[k]=sum;
			sum = 0;
		}
		int indexAns[25], ans2[5];
		bool flag1 = false, flag2= false;
		memcpy(ans,indexAns,sizeof(ans));
		sort(ans,ans+25);
		for (int h = 0; h < 5; h++){
			for (int i = 0; i < 25; i++){
				if(flag1){
					flag1 = false;
					break;
				}
				if(h!=0){
					for (int q = 0; q < h; q++){
						if(ans[i]==ans2[q]){
							flag2 = true;
							break;
						}
					}
				}
				if(flag2){ 
					flag2 = false;
					continue;
				}
				for (int j = 0; j < 25; j++){
					if(ans[i] == indexAns[j]){
						ans2[h] = j;
						if(h!= 4) printf("%d ", j);
						else printf("%d\n", j);
						flag1 = true;
						break;
					}
				}
			}
		}
	}
}