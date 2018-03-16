#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, days, parties, aux = 0, counter= 0;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&days,&parties);
		int partiesDays[parties];
		for (int i = 0; i < parties; i++)
			scanf("%d",&partiesDays[i]);

		bool calendar[days];
		for (int i = 0; i < days; i++)
			calendar[i]=false;

		for (int i = 0; i < parties; i++)
			for (int j = 0; j < days; j++){
				if(((j+1)%partiesDays[i])==0){
					calendar[j]=true;
				}
			}
		for (int i = 0; i < days; i++)
		{
			if(i==(5+7*aux) || i==(6+7*aux)){
					calendar[i]=false;
					if(i==(6+7*aux))
						aux++;
				}
			if(calendar[i]==true)
				counter++;
		}
		printf("%d\n", counter);
		counter = 0, aux = 0;
	}
}