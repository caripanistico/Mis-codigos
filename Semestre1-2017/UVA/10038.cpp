#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	bool jolly;
	while(scanf("%d",&n) == 1){
		jolly=true;
		int numbers[n];
		for(int i = 0; i<n ; i++){
			scanf("%d",&numbers[i]);
		}
		if(n != 1){
			vector<int> results;
			vector<int> nTerms;
			for(int i = 0; i<n-1;i++){
				nTerms.push_back(i+1);
				results.push_back((int)abs(numbers[i]-numbers[i+1]));
			}
			for(int i = 0; i<n-1;i++){
				for (int j = 0; j < n-1; j++)
				{if(results.at(i) == nTerms.at(j)){
					nTerms.at(j)=0;
					break;
				}	
			}
		}
			for(int i = 0; i<n-1;i++)
				if(nTerms[i]!=0){
					jolly=false;
					break;
				}

			if(jolly)
				printf("Jolly\n");
			else
				printf("Not jolly\n");
				
		
	}
	else{printf("Jolly\n");}
}
return 0;
}