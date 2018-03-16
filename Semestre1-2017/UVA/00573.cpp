#include <bits/stdc++.h>
using namespace std;



double H,U,D,F;

int main(){

	while(scanf("%lf %lf %lf %lf",&H,&U,&D,&F) == 4){
			if(H==0)
				break;
			else{
				double currentHeight = 0.0;
				double fatigue = U*(F/100);
				int day = 0;
				double speed = U;
				while(true){
					day++;
					currentHeight += speed;
					if(currentHeight>H /*&& day>1 && ((currentHeight-D) > 0)*/){
						cout<<"success on day "<<day<<endl;
						break;
					}
					currentHeight -= D;
					speed -= fatigue;
					if(speed < 0.0)
						speed = 0.0;
					if(currentHeight<0.0 /*&& day>=1 && (((currentHeight-D) < 0))*/){
						cout<<"failure on day "<<day<<endl;
						break;
					}
				} 

			}
}
return 0;
}