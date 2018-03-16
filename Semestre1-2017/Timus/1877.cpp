#include <bits/stdc++.h>
using namespace std;

int main(){
	int key1, key2;
	cin>> key1 >> key2;
	if((key1%2 == 0) || (key2%2 == 1))
		cout<< "yes\n";
	else cout<< "no\n";
	return 0;
}