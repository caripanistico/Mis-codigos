#include <bits/stdc++.h>
using namespace std;

int main(){

	char text;
	bool quotestart = false;

	while(scanf("%c",&text)!=EOF){

		if(text == 34 && quotestart){
			quotestart = false;
			printf("%c%c",39,39);
			continue;
		}
		if(text == 34 && !quotestart){
			quotestart = true;
			text = 96;
			printf("%c%c",96,96);
			continue;
		}
		printf("%c", text);

	}
}
