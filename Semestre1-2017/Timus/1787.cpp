#include <iostream>
using namespace std;

int main(){
	int carsin1min, mins;
	cin >> carsin1min >> mins;
	int total = 0, minute[mins];
	for(int i = 0;i<mins;i++)
		cin >> minute[i];

	for(int i = 0;i<mins;i++){
		total = total + minute[i];
		total = total - carsin1min;
		if (total<0)
			total = 0;
	}

	cout << total << "\n";

}