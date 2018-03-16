#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	int t,n;
	string in,in2;
	map <string , string> out;
	map <string , string> :: iterator it;
	cin >> t;
	getchar();
	while(t--){
		getline(cin , in);
		getline(cin , in2);						//este programa lee strings, que son eslogans, que estan separados en una primera y una segunda parte
		out[in] = in2;							//la primera parte del programa lee cuantos slogan se leeran, seguidos de su respuesta, es decir la primera y segunda parte
	}											//luego se lee cuantos slogans se preguntaran, y cuando se ingrese el determinada pregunta, se debe responde con la determinada respuesta
	cin >> n;
	getchar();
	while(n--){
		getline(cin , in);
		it = out.begin();
		while(it!=out.end()){					//por lo tanto este problema puede ser facilmente completado usando un map de strings
			if(it->first==in){					//que cuando se ingrese el string que es 'key', se devuelve el string que es 'value'
				cout << it->second << endl;		//de igual forma que uno espera de una pregunta y respuesta.
				break;
			}
			else if(it->second==in){
				cout << it->first << endl;
				break;
			}
			it++;
		}
	}
	return 0;
}
