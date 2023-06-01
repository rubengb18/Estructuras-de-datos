//Ruben Gomez y Adrian Perez


#include "dequeue_eda.h"
#include <iostream>
#include <fstream>
using namespace std;
struct tNum {
	int n;
	int pos;
};

bool resuelveCaso() {
	deque<tNum>cola;
	int n,P,N;
	tNum num;
	cin >> P>>N;
	if (P == 0 && N == 0) {
		return false;
	}
	for (int i = 0; i < P; i++) {
		cin >> n;
		num.n = n;
		num.pos = i;

		while (!cola.empty() && cola.back().n < num.n) {
			cola.pop_back();
		}
		cola.push_back(num);
		while (!(cola.front().pos > i - N)) {
			cola.pop_front();
		}
		if (i >= N - 1) {
			cout << cola.front().n << " ";
		}
	}
	cout << '\n';
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso()) {
		
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}