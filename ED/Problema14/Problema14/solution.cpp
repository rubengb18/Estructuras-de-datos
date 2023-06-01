//Ruben Gomez y Adrian Perez


#include <string>
#include <fstream>
#include <iostream>
#include "Clase.h"
using namespace std;

bool resuelveCaso() {
	ListaNueva<char>lista;
	ListaNueva<char> aux1, aux2;
	string c;

	getline(cin, c);
	if (!cin) {
		return false;
	}
	for (int i = 0; i < c.size();i++) {
		lista.push_back(c[i]);
	}
	lista.volcarLista(aux1,aux2);
	lista.cambiarCons();
	lista.print();
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	while(resuelveCaso()) { }

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}