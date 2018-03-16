#include <bits/stdc++.h>
using namespace std;

int main(){
	int tests, stores;
	scanf("%d",&tests);

	for (int i = 0; i < tests; i++)
	{
		scanf("%d",&stores);
		vector<int> distances;
		for (int j = 0; j < stores; j++){
			int aux;
			scanf("%d",&aux);
			distances.push_back(aux);
		}
		sort(distances.begin(),distances.end());
		int aux2 = (distances.back()-distances.front())*2;
		printf("%d\n", aux2);
	}
}