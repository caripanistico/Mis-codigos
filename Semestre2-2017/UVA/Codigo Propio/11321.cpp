#include <bits/stdc++.h>
using namespace std;

bool isEven(int n){
	return (n & 1) == 0;
}
int M;
struct comparisonFoo{
	bool operator()(const int &t1, const int &t2)const{
	int modulo1, modulo2;
	modulo1 = (t1%M);
	modulo2 = (t2%M);
	if(modulo1 == modulo2){
		if((isEven(t1) && !isEven(t2)) || (!isEven(t1) && isEven(t2))){
			if(isEven(t1)) return false;
			else return true;
		}
		else if(!isEven(t1)&&!isEven(t2)){
			return (t2<t1);
		}
		else return (t2>t1);
	}

	return (modulo1 < modulo2);
	}
};


int main(){
	int N, aux = 0;
	while(scanf("%d %d",&N,&M) == 2 and (N != 0 && M != 0)){
		vector<int> sortingVector;
		for(int aux2 = 0; aux2 < N; aux2++){
			scanf("%d",&aux);
			sortingVector.push_back(aux);
		}
		sort(sortingVector.begin(), sortingVector.end(), comparisonFoo());
	printf("%d %d\n", N, M);
	for (vector<int>::iterator i = sortingVector.begin(); i != sortingVector.end(); i++){
		printf("%d\n", *i);
	}
	}
	printf("%d %d\n",0,0);
}