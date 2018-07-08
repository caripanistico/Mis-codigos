#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C;
	int x,y,z;
	int n, temp;
	bool found;
	scanf("%d",&n);
	while(n--){
		found = false;
		scanf("%d %d %d",&A,&B,&C);
		if(B == 0)
			temp = A;
		else temp = B;
		for(x = -temp; x <= temp; x++){
			if(found) break;
			if(x && B%x)
            	continue;
        	for(y = x+1; y <= temp; y++) {
            	if(y && B%y)
                	continue;
            	z = A-x-y;
            	if(y >= z) continue;
            	if(x+y+z == A && x*x+y*y+z*z == C && x*y*z == B) {
					printf("%d %d %d\n", x, y, z);
					found = true;
				}
			}
		}
		if(!found) printf("No solution.\n");
	}
	return 0;
}