#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int N;
	int W;
}ArrayData;

int main(){
	int n;
	do{cin>>n;}while(0>n>1000);
	while(n > 0){
	ArrayData A[n];
	int Equator,Greenwich;

	do{
	cin>>Equator>>Greenwich;
	}while(Equator,Greenwich <= -10000 || Equator,Greenwich >= 10000);

	for(int aux= 0; aux < n; aux++)
		cin>>A[aux].N>>A[aux].W;

	for(int aux= 0; aux < n; aux++){
		if((A[aux].W == Greenwich) || (A[aux].N) == Equator)
			cout<<"divisa"<<endl;
		else{
			if(A[aux].W > Greenwich)
				cout<<"N";
			else{cout<<"S";
		}
			if(A[aux].N > Equator)
				cout<<"E"<<endl;
			else{cout<<"O"<<endl;
		}
			};
	}
	do{
	cin>>n;
}while(0>n>1000);

}
	return 0;
}

