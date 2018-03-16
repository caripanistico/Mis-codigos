#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {
	int n;
	string msg;
	unordered_map<string, int> freq;					//este es un problema simple, este programa ocupa un mapa no ordenado
	while (cin >> n >> msg) {							//se pregunta por los inputs...
		freq.clear();
		int max = 0;
		string pass = "";
		for (int ini = 0; ini + n <= msg.length(); ini++) {		//se va analizando cada substring de largo n
			string sub = msg.substr(ini, n);					//y va guardando cada substring dentro del mapa
			if (!freq.count(sub)) freq.insert(pair<string, int>(sub, 0));
			freq[sub]++;
			if (freq[sub] > max) max = freq[sub], pass = sub;	//al final, el substring con mas coincidencias es imprimido
		}
		cout << pass << endl;
	}
	return 0;
}