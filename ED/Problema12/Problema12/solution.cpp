//Ruben Gomez y Adrian Perez


#include "queue_eda.h"



bool resuelveCaso() {
	int N,c;
	queue<int>listaPrincipal;
	cin >> N;
	for (int i = 0; i < N; i++) {
		listaPrincipal.push(i+1);
	}
	cin >> c;
	if (N == 0 && c == 0) {
		return false;
	}
	cout<<listaPrincipal.funcion(c)<<'\n';
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