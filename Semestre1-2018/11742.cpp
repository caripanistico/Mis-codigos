#include <bits/stdc++.h>
using namespace std;

int findDistance(int arr[], int x, int y, int size){
	int posx = -1, posy = -1, count;
	for (int i = 0; i < size; i++){
		if(arr[i] == x) posx = i;
		if(arr[i] == y) posy = i;
		if(posx != -1 and posy != -1) break;
	}
	if(posx < posy){
		count = 0;
		for (int i = 0; i < size; i++){
			if(posx + i != posy) count++;
			else break;
		}
	}
	else{
		count = 0;
		for (int i = 0; i < size; i++){
			if(posy + i != posx) count++;
			else break;
		}
	}	
	return count;
}


int main(){
	int n,m;
	while(scanf("%d %d",&n,&m) and (n||m)){
		int asientos[n];
		for (int i = 0; i < n; i++){
			asientos[i]=i;
		}
		int condiciones[m][3], permutaciones = 0;
		bool sesientan = true;
		int distancia = 0;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d",&condiciones[i][0],&condiciones[i][1],&condiciones[i][2]);
		}
		if(m!=0) do{
			sesientan = true;
					for (int i = 0; i < m; i++){
					distancia = findDistance(asientos,condiciones[i][0],condiciones[i][1],n);
						if(condiciones[i][2]>0){
							if(distancia>condiciones[i][2]){
								sesientan=false;
								break;
							}
						}
						else{
							if(distancia<(-condiciones[i][2])){
								sesientan=false;
								break;
							}
						}
					}
					if(sesientan) permutaciones++;
		}while(next_permutation(asientos, asientos+n));
		
		else{
			int sum = 1;
			for (int i = 2; i <= n; i++){
				sum*=i;
			}
			permutaciones = sum;
		}
		printf("%d\n", permutaciones);
	}
	return 0;
}