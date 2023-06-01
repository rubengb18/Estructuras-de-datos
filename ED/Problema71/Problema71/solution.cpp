//Ruben Gomez y Adrian Perez


#include "Clase.h"
#include <fstream>
using namespace std;

bool resuelveCaso() {
	int N,c;
	ListaInsert<int>listaPrincipal;
	cin >> N;
	if (N == 0) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		listaPrincipal.push(c);
	}
	listaPrincipal.insertar();
	listaPrincipal.print();
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