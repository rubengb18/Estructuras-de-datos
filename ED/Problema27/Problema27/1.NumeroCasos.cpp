
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <sstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bintree<int> calcularArbol(vector<int>& preorden) {
	vector<int>pre_hijo_iz, pre_hijo_dr;
	int i = 1;
	if (preorden.size() > 0) {
		while (i < preorden.size() && preorden[i] < preorden[0]) {
			pre_hijo_iz.push_back(preorden[i]);
			i++;
		}
		while (i < preorden.size()) {
			pre_hijo_dr.push_back(preorden[i]);
			i++;
		}

		return { calcularArbol(pre_hijo_iz),preorden[0], calcularArbol(pre_hijo_dr) };
	}
	else {
		return {};
	}

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	vector<int>preorden, res;
	string linea;
	getline(cin, linea);
	if (!cin) {
		return false;
	}
	stringstream ss(linea);
	int valor;
	while (ss >> valor) {
		preorden.push_back(valor);
		// tratar valor  (el bucle da una vuelta por cada entero en la linea)

	}
	bintree<int> arbol;
	arbol = calcularArbol(preorden);
	res = arbol.postorder();
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << '\n';
	return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	  while( resuelveCaso()){
   }
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
