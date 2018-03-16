#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	do{
		cin>>n;
	}while(0>n>20);
	int a,b,c;
	for(int i=0;i<n;i++){

		do{
		cin>>a>>b>>c;
		}while(1000>a,b,c>10000);

		if((a<b && b<c)||(a>b && b>c)||(c>b && b>a)||(c<b&& b<a))
			cout<<"Case "<<i+1<<": "<<b<<endl;
		else {if((a<b && c<a)||(b<a && a<c))
			cout<<"Case "<<i+1<<": "<<a<<endl;
			else cout<<"Case "<<i+1<<": "<<c<<endl;
		}
		a,b,c = 0;
	}
	return 0;
}
