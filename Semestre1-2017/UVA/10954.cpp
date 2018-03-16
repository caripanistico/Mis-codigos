#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int n;

	while (scanf("%d", &n), n) {
		priority_queue<int, vector<int>, greater<int> > q;  //se crea un priority queue, en donde se almacenaran los enteros

		while (n--) {
			int x;
			scanf("%d", &x);
			q.push(x);   //se pregunta por los numeros y se agregan al queue
		}

		int total = 0, cost = 0;
		while (q.size() > 1) {
			total = q.top();        //luego se crea un total donde se van sumando los numeros, junto con su costo
			q.pop();
			total += q.top();
			q.pop();
			cost += total;
			q.push(total);
		}

		printf("%d\n", cost);  //y luego se imprime el costo total de la operacion
	}

	return 0;
}
