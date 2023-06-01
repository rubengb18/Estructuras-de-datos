
//Ruben Gomez y Adrian Perez

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "Clase.h"
#include <fstream>

bool resuelveCaso() {
	ListaInvert<int> list;
	int num;
	cin >> num;
	while (num != 0) {
		list.push(num);
		cin >> num;
	}
	if (list.size() > 0) {
		list.invertir();
		list.print();
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
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}