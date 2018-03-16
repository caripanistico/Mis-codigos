#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	string length;
	for (int i = 0; i < n; i++)
	{
		cin>>length;
		int size = length.size() - 1;
		if( ((length.size()==1) && (length[0]=='1' || length[0]=='4')) || ((length.size()==2) && (length[0]=='7' && length[1]=='8'))){printf("+\n");}
		else {
			if(length[size-1]=='3' && length[size]=='5'){printf("-\n");}
			else if(length[0]=='9' && length[size]=='4'){printf("*\n");}
			else if(length[0]=='1' && length[1]=='9' && length[2]=='0'){printf("?\n");}
			else printf("?\n");
	}
}
	return 0;
}