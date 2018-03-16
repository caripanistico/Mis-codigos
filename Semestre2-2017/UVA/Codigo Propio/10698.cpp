#include <bits/stdc++.h>
using namespace std;

struct teamData{
	int points, numberGames, numberTGoals, numberOGoals, goalDifference;
	double percentagePoints;
};

bool lexicalFoo(string a, string b){
	string auxA = a, auxB = b;
	transform(auxA.begin(), auxA.end(), auxA.begin(), ::tolower);
	transform(auxB.begin(), auxB.end(), auxB.begin(), ::tolower);
	return lexicographical_compare(auxA.begin(), auxA.end(), auxB.begin(), auxB.end());
}

bool comparisonFoo(const pair<string,teamData*> &t1, const pair<string,teamData*> &t2){

	if (t1.second->points != t2.second->points) return t1.second->points > t2.second->points;
    if (t1.second->goalDifference != t2.second->goalDifference) return t1.second->goalDifference > t2.second->goalDifference;
    if (t1.second->numberTGoals != t2.second->numberTGoals) return t1.second->numberTGoals > t2.second->numberTGoals;

    return lexicalFoo(t1.first, t2.first);
}

int main(){
	bool start=true;
	int T, G;
	while(scanf("%d %d",&T,&G) > 0 and (T!=0 or G!=0)){
		if(start)
			start=false;
		else cout<<endl;
		map<string, teamData> teams;
		pair<string, teamData> newPair;
		string newTeamName;
		teamData newTeam;
		vector<pair<string, teamData*> > sortVector;
		newTeam.points = 0; newTeam.numberGames= 0; newTeam.numberTGoals= 0; newTeam.numberOGoals= 0; newTeam.goalDifference = 0;
		newTeam.percentagePoints = -1.0;
		for (int i = 0; i < T; i++){
			cin>>newTeamName;
			newPair.first = newTeamName;
			newPair.second = newTeam;
			teams.insert(newPair);
		}
		string teamHome, teamAway;
		int scoreHome, scoreAway;
		for (int j = 0; j < G; j++){
			cin>>teamHome>>scoreHome;
			cin.ignore(256,'-');
			cin>>scoreAway>>teamAway;
			if(teams[teamHome].percentagePoints=-1.0)
				teams[teamHome].percentagePoints = 0;
			if(teams[teamAway].percentagePoints=-1.0)
				teams[teamAway].percentagePoints = 0;
			teams[teamHome].numberGames++;
			teams[teamAway].numberGames++;
			teams[teamHome].numberTGoals+=scoreHome;
			teams[teamAway].numberTGoals+=scoreAway;
			teams[teamHome].numberOGoals+=scoreAway;
			teams[teamAway].numberOGoals+=scoreHome;
			teams[teamHome].goalDifference+=(scoreHome-scoreAway);
			teams[teamAway].goalDifference+=(scoreAway-scoreHome);
			if(scoreHome==scoreAway){
				teams[teamHome].points++;
				teams[teamAway].points++;
			}else{
				scoreHome>scoreAway? teams[teamHome].points+=3:teams[teamAway].points+=3;
		}
			if(teams[teamHome].numberGames!=0){
				teams[teamHome].percentagePoints = (teams[teamHome].points * 100.00)/(3.0 * teams[teamHome].numberGames) + 1e-9;
			}
			if(teams[teamAway].numberGames!=0){
				teams[teamAway].percentagePoints = (teams[teamAway].points * 100.00)/(3.0 * teams[teamAway].numberGames) + 1e-9;
			}
	}

		pair<string, teamData*> vectorPair;
	for (map<string,teamData>::iterator it = teams.begin(); it != teams.end(); it++){
		vectorPair.first = it->first;
		vectorPair.second = &(it->second);
		sortVector.push_back(vectorPair);
	}
		sort(sortVector.begin(), sortVector.end(), comparisonFoo);
		int position = 1;
		int samePlace = false;
		for (int i = 0; i < T; i++){
			int numberSpaces = 16;
			if(!samePlace){
				printf("%2d. ", position);
			}else{
				cout<<"    ";
			}
			if(i!=T-1){
				if(sortVector.at(i).second->points == sortVector.at(i+1).second->points and sortVector.at(i).second->numberTGoals == sortVector.at(i+1).second->numberTGoals and sortVector.at(i).second->goalDifference == sortVector.at(i+1).second->goalDifference)
					samePlace = true;
				else{samePlace = false;}
			}

			position++;
			
			printf("%15s %3d %3d %3d %3d %3d ", sortVector.at(i).first.c_str(), sortVector.at(i).second->points, sortVector.at(i).second->numberGames, sortVector.at(i).second->numberTGoals, sortVector.at(i).second->numberOGoals, sortVector.at(i).second->goalDifference);

			if(sortVector.at(i).second->percentagePoints!=-1){
				if(sortVector.at(i).second->percentagePoints >= 100.0){
					printf("%6.2f", sortVector.at(i).second->percentagePoints);
				}
				else{ if(sortVector.at(i).second->percentagePoints>=10.0f and sortVector.at(i).second->percentagePoints<100.0f){
						printf("%6.2f",sortVector.at(i).second->percentagePoints);
					}
					 else printf("%6.2f",sortVector.at(i).second->percentagePoints);
					}
					}
			else cout<<"   N/A";
			cout<<endl;
			}
		}
	}