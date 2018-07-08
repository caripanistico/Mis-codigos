#include <bits/stdc++.h>
using namespace std;

int main(){

	int tests, tLength, nBars, sum;
	scanf("%d",&tests);
	for (int i = 0; i < tests; i++){
		bool numberCheck[1010]={};
		scanf("%d %d",&tLength, &nBars);
		int nLength[nBars];
		for (int j = 0; j < nBars; j++){
			scanf("%d",&nLength[j]);
		}
		sort(nLength,nLength+nBars);
		numberCheck[0]=true;

		for (int i = 0; i < nBars; i++){
			for (int j = tLength - nLength[i]; j>=0; j--){
				if(numberCheck[j] && !numberCheck[j+nLength[i]])
					numberCheck[j+nLength[i]] = true;
			}
		}

		if(numberCheck[tLength]){
			printf("YES\n");
		}else{printf("NO\n");}
	}
}