#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, aux1, aux2;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		{
			scanf("%d %d",&aux1,&aux2);
			aux1>=aux2 ? ((aux1!=aux2)? printf(">\n"):printf("=\n")) : printf("<\n");
		}
	return 0;	
}