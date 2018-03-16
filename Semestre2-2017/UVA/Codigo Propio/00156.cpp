#include <bits/stdc++.h>
using namespace std;

int main(){

	string input,sortedInput;
	vector<string> vC;
	vector< pair<string,bool> > sortedvC;

	while((cin>>input) && input!="#"){
		sortedInput = input;
		pair<string,bool> aux;
		transform(sortedInput.begin(), sortedInput.end(), sortedInput.begin(), ::tolower);
		stable_sort(sortedInput.begin(), sortedInput.end());
		aux.first = sortedInput; aux.second = false;
		vC.push_back(input);
		sortedvC.push_back(aux);
	}

	for(int i = 0 ; i < sortedvC.size() ; i++){
		if(sortedvC.at(i).second == true) continue;
		for(int j = 0; j < sortedvC.size() ; j++)
			if(((sortedvC.at(i).second == false)|(sortedvC.at(j).second == false)) && i != j){
				if(sortedvC.at(i).first == sortedvC.at(j).first){
					sortedvC.at(i).second=true;
					sortedvC.at(j).second=true;
				}
			}
	}
	vector<string> sortedOutput;
	for (int i = 0; i < vC.size(); i++)
	{
		if(sortedvC.at(i).second == false)
			sortedOutput.push_back(vC.at(i));
	}
	sort(sortedOutput.begin(), sortedOutput.end());
	for(int i = 0; i < sortedOutput.size(); i++){
		cout<<sortedOutput.at(i)<<endl;
	}
}