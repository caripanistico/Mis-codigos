#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n, op, x;
	while (scanf("%d", &n) != EOF) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool isS = true, isQ = true, isPQ = true;

		for (int i = 0; i < n; i++) {				//se crean las 3 estructuras para comprobar si es alguna de ellas
			scanf("%d %d", &op, &x);

			switch (op) {
			case 1:
				if (isS)
					s.push(x);
				if (isQ)							//al inicio de crean las 3 estructuras, y se agregan los valores correspondientes
					q.push(x);
				if (isPQ)
					pq.push(x);
				break;
			case 2:
				if (isS) {
					if (s.empty() || s.top() != x)
						isS = false;
					else
						s.pop();					//si alguno de los outputs no es igual al valor correspondiente, se descarta, desactivando su flag
				}									//en el caso contrario, solo se quita de la estructura
				if (isQ) {
					if (q.empty() || q.front() != x)
						isQ = false;
					else
						q.pop();
				}
				if (isPQ) {
					if (pq.empty() || pq.top() != x)
						isPQ = false;
					else
						pq.pop();
				}
				break;
			}
		}

		if (isS == true && isQ == false && isPQ == false)			//al final del programa, comprueba los flags y da el resultado
			cout << "stack" << endl;
		else if (isS == false && isQ == true && isPQ == false)
			cout << "queue" << endl;
		else if (isS == false && isQ == false && isPQ == true)
			cout << "priority queue" << endl;
		else if (isS == false && isQ == false && isPQ == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
}
