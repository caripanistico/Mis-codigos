#include <iostream>
using namespace std;

int main(){
	int steaks, pan;
	cin>> steaks >> pan;
	if(steaks<=pan)
		cout<< "2\n";
	else{
		if((2*steaks%pan)>=1)
			cout<< (2*steaks/pan)+(1) << "\n";
		else{

			cout<< (2*steaks/pan) << "\n";
		}
	return 0;
}
}