//Ruben Gomez y Adrian Perez


#include <string>
#include <fstream>
#include <iostream>
#include "deque_eda.h"
using namespace std;

bool resuelveCaso() {
	deque<int>lista,aux1;
	int c;
	int num;
	cin >> num;
	for (int i = 0; i < num;i++) {
		cin >> c;
		lista.push_back(c);
	}
	cin >> num;
	for (int i = 0; i < num;i++) {
		cin >> c;
		aux1.push_back(c);
	}
	lista.engordar(aux1);
	lista.print();
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numcasos;
	cin >> numcasos;
	char a;
	cin.get(a);
	for (int i = 0; i < numcasos; i++) { resuelveCaso(); }

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}