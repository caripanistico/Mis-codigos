#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n, s, q, TC;

	cin >> TC;				//se inicia preguntando por el numero de tests

	for (; TC > 0; TC--) {
		stack<int> carrier;
		queue<int> stationQueue[100];			//se crean un stack y un queue

		cin >> n >> s >> q;				//se pregunta por el numero de estaciones, la capacidad de cada carrier y en numero de carga que el queue puede acomodar

		for (int i = 0; i < n; i++) {
			int nc;						// luego se pregunta por el largo de cada estacion
			cin >> nc;
			for (int j = 0; j < nc; j++) {
				int target;
				cin >> target;
				stationQueue[i].push(target - 1);
			}
		}

		int currPos = 0, time = 0;
		while (true) {

			//descargar carga hasta que falle, o que el stack este vacio @ 1min
			while (!carrier.empty()
					&& (carrier.top() == currPos
							|| stationQueue[currPos].size() < q)) {
				if (carrier.top() != currPos) {
					stationQueue[currPos].push(carrier.top());
				}
				carrier.pop();
				time++;
			}

			//cargar hasta que el stack este lleno, o el queue este vacio @ 1min
			while ((carrier.size() < s) && !stationQueue[currPos].empty()) {
				carrier.push(stationQueue[currPos].front());
				stationQueue[currPos].pop();
				time++;
			}

			bool clear = carrier.empty();
			for (int i = 0; i < n; i++) {
				clear &= stationQueue[i].empty();	//se sale del loop si el carries esta limpio
			}
			if (clear)
				break;

			//mover @ 2 min
			currPos = (currPos + 1) % n;
			time += 2;
		}

		cout << time << endl; //imprime el tiempo acumulado
	}

	return 0;
}