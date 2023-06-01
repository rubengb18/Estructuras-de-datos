//Ruben Gomez y Adrian Perez


#include <string>
#include <fstream>
#include <iostream>
#include "stack_eda.h"
using namespace std;

struct tAcc {
	string fecha;
	int victimas;
};

bool resuelveCaso() {
	stack<tAcc> pila;
	int num,vic;
	string fecha;
	cin >> num;
	if (!cin) {
		return false;
	}

	for (int i = 0;i < num;i++) {
		cin >> fecha >> vic;
		tAcc ac;
		ac.fecha = fecha;
		ac.victimas = vic;
		if (pila.empty()) {
			cout << "NO HAY" << '\n';
			pila.push(ac);
		}
		else {
			bool sal = false;
			int m = pila.size();
			int j = 0;
			while (!sal && j < m-1) {
				if (pila.top().victimas > vic) {
					cout << pila.top().fecha << '\n';
					pila.push(ac);
					sal = true;
				}
				else {
					pila.pop();
				}
			}
			if (!sal) {
				cout << "NO HAY" << '\n';
				pila.push(ac);
			}
		}
	}
	cout << "---\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {  }

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}