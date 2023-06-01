//Ruben Gomez y Adrian Perez


#include "Clase.h"



bool resuelveCaso() {
	ListaDuplica<int> cola;
	int c;
	cin >> c;
	while (c != 0) {
		cola.push_back(c);
		cin >> c;
	}
	cola.duplica();
	cola.print();
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numcasos;
	std::cin >> numcasos;
	char c;
	cin.get(c);
	for (int i = 0; i < numcasos; i++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}