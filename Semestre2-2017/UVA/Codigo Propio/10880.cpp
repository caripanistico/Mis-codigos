#include <bits/stdc++.h>
using namespace std;

int main(){
	int cases;
	scanf("%d",&cases);
	int caseNumber = 1;
	while(cases--){
		set<long long> posibleNumbers;
		long long C, R;
		scanf("%lld %lld",&C,&R);
		long long diff = C - R;
		printf("Case #%d:", caseNumber);
		caseNumber++;
		if (diff == 0){
			printf(" 0\n");
			continue;
		}
		else for (int i = 1; i*i <= diff; i++){
				if(diff%i==0){
					posibleNumbers.insert(i);
					posibleNumbers.insert(diff/i);
				}
			}
		for (set<long long>::iterator i = posibleNumbers.begin(); i != posibleNumbers.end(); i++){
			if (*i > R) printf(" %lld", *i);
		}
		printf("\n");
	}
}