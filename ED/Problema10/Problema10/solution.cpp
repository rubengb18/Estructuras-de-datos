//Ruben Gomez y Adrian Perez


#include "Clase.h"



bool resuelveCaso() {
	int N,c;
	cin >> N;
	ListaNueva<int>listaPrincipal,listaSec;
	for (int i= 0; i < N; i++) {
		cin >> c;
		listaPrincipal.push(c);
	}
	int M, P;
	cin >> M >> P;
	for (int i = 0; i < M; i++) {
		cin >> c;
		listaSec.push(c);
	}
	listaPrincipal.insertar(listaSec,P);
	listaPrincipal.print();
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