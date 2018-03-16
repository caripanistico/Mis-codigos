#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int month;
	double deprePercent;
}dataList;

int main(){
	int numbersMonth = 1, depreRegists, auxIndex = 1;
	double downPayment, loan, currentLoan, monthPayment, carValue, percent = 0.0;
	while(numbersMonth>0){

		do{
			cin>>numbersMonth;
		}while(numbersMonth>100);
			cin>>downPayment;
		do{
			cin>>loan;
		}while(loan>75000.0);
			cin>>depreRegists;

		if(numbersMonth<0) break;

		dataList depreList[depreRegists];
		for(int index = 0; index<depreRegists;index++){
			cin>>depreList[index].month>>depreList[index].deprePercent;
		}
		currentLoan = loan;
		monthPayment=(double)((loan)/(double)numbersMonth);
		carValue=(double)((loan+downPayment)*(1.0-depreList[0].deprePercent));

		for (int monthIndex = 0; monthIndex <= numbersMonth; monthIndex++)
		{

			if(monthIndex == depreList[auxIndex].month){
				percent = depreList[auxIndex].deprePercent;
				if(auxIndex<depreRegists)
					auxIndex++;
			}

			if(monthIndex>0){
				carValue = carValue*(1.0 - percent);
				currentLoan = currentLoan - monthPayment;
			}

			if(carValue>currentLoan){
				if(monthIndex!=1)
					cout<<monthIndex<<" months"<<endl;
				else{
					cout<<monthIndex<<" month"<<endl;
				}
				auxIndex = 1;
				break;

			}
			else if(monthIndex == numbersMonth){
				cout<<"0 months"<<endl;
				auxIndex = 1;
				break;
			}



		}


	}






	return 0;
}