
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
bintree<int> calcularArbol(vector<int>& preorden, vector<int>& inorden, int a, int b, int c, int d) {
	if (a > b ) {
		return {};
	}
	else {
		int indice_raiz_inorden = c;
		int raiz = preorden[a];
		while (raiz != inorden[indice_raiz_inorden]) {
			indice_raiz_inorden++;
		}
		int tamizq = indice_raiz_inorden - c;
		auto iz = calcularArbol(preorden, inorden, a + 1, a + tamizq, c, indice_raiz_inorden - 1);
		auto der = calcularArbol(preorden, inorden, a + tamizq + 1, b, indice_raiz_inorden + 1, d);

		return { iz,raiz,der };
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	vector<int>preorden;
	vector<int>inorden;
	string linea;

	getline(cin, linea);
	if (!cin) {
		return false;
	}
	stringstream ss(linea);

	int valor;

	while (ss >> valor) {
		preorden.push_back(valor);
	}
	getline(cin, linea);
	stringstream ss2(linea);
	while (ss2 >> valor) {
		inorden.push_back(valor);
	}
	int k = inorden.size();
	bintree<int> arbol;
	arbol = calcularArbol(preorden, inorden, 0, k - 1, 0, k - 1);
	vector<int>posorden = arbol.postorder();

	for (auto x : posorden) {
		cout << x << ' ';
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

   while(resuelveCaso()){
   }
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
