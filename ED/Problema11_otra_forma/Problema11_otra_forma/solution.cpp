//Ruben Gomez y Adrian Perez


#include "Clase.h"



bool resuelveCaso() {
	ListaNueva<int>cola1, cola2;
	int n;
	cin >> n;
	while (n != 0) {
		cola1.push(n);
		cin >> n;
	}
	cin >> n;
	while (n != 0) {
		cola2.push(n);
		cin >> n;
	}

	cola1.insertar(cola2);
	cola1.print();
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