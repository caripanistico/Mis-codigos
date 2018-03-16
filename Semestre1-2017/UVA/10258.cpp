#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Contestant {							//se crea un struct, para cada participante
	bool solved[10];
	int attempt[10];
	int penalty, count;
};

map<int, Contestant> Contest;			//y se crea un mapa que contiene un int y un struct y un vector de indices
vector< int > Index;

bool comp(int A, int B) {
	if (Contest[A].count != Contest[B].count)
		return (Contest[A].count > Contest[B].count);		//se crea una funcion booleana que compara 2 competidores dentro del mapa
	if (Contest[A].penalty != Contest[B].penalty)
		return (Contest[A].penalty < Contest[B].penalty);
	return (A < B);
}

int main() {
	int T;
	stringstream ss;
	string str;            //utiliza stringstream para obtener un int a partir de un string del input
	getline(cin, str);
	//cout << str << endl;
	ss.clear();
	ss << str;
	ss >> T;
	//cout << T << endl;
	getline(cin, str);
	//cout << str << endl;
	while (T--) {
		//cout << "T--\n";
		Contest.clear();			//al inicio de cada test, se limpia el mapa y los indices
		Index.clear();
		while (getline(cin, str)) {
			//cout << str << endl;
			if (str.empty()) break; //si el string es nulo, se sale del loop
			int A, B, C;
			string D;
			ss.clear();		//de otra forma, pregunta por los valores de cada competidor y los agrega al mapa
			ss << str;
			ss >> A >> B >> C >> D;
			//cout << A << " " << B << " " << C << " " << D << endl;
			
			if (Contest.find(A) == Contest.end()) {
				Contestant Con;
				memset(Con.solved, false, sizeof Con.solved);  //crea memoria para un struct temporal
				memset(Con.attempt, 0, sizeof Con.attempt);
				Con.penalty = 0;
				Con.count = 0;
				
				Index.push_back(A);
				Contest[A] = Con;
			}
			if (D == "C" || D == "I") {
				if (Contest[A].solved[B]) continue;
				
				if (D == "C") {									//solo se toman en cuenta los inputs que tiene 'C' de correcto o 'I' de incorrecto
					Contest[A].solved[B] = true;
					Contest[A].penalty += (20 * Contest[A].attempt[B] + C);
					Contest[A].count += 1;
				}
				else {
					Contest[A].attempt[B] += 1;
				}
			}
		}
		sort(Index.begin(), Index.end(), comp); //ordena el indice y luego lo utiliza para imprimir cada dato en la forma pedida
		for (int i = 0; i < Index.size(); i++) {
			cout << Index[i] << " " << Contest[Index[i]].count << " " << Contest[Index[i]].penalty << endl;
		}
		if (T) cout << endl;
	}
	return 0;
}