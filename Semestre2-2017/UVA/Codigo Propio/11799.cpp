#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,N,aux,testCase = 0;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d",&N);
		vector<int> v;
		while(N--){
			scanf("%d",&aux);
			v.push_back(aux);
		}
		sort(v.begin(),v.end());
		testCase++;
		printf("Case %d: %d\n",testCase,v.back());
	}
}