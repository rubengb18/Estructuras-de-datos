
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
vector<bool> numerosprimos() {
	vector<bool>lista(5000, true);
	lista[0] = lista[1] = false;
	for (int i = 2; i < sqrt(5000); ++i) {
		if (lista[i]) {
			for (int j = i * i; j < 5000; j += i){
				lista[j] = false;
			}
		}
	}
	return lista;
}



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int i = -1;
	bintree<int>arbol;
	vector<bool> primos = numerosprimos();
	arbol = leerArbol(i);

	bool encontrado = false;
	int cercano = 0, profundidad = 0;
	if (!arbol.empty() && !primos[arbol.root()]) {
		queue<bintree<int>> cola;
		cola.push(arbol);
		int nivel = 1, actual = 1, siguiente = 0;
		while(!encontrado && !cola.empty()){
			auto a = cola.front();
			cola.pop();
			--actual;
			if (a.root() % 7 == 0) {
				encontrado = true;
				cercano = a.root();
				profundidad = nivel;
			}
			else {
				auto iz = a.left();
				if (!iz.empty() && !primos[iz.root()]) {
					cola.push(iz);
					++siguiente;
				}
				auto dr = a.right();
				if (!dr.empty() && !primos[dr.root()]) {
					cola.push(dr);
					++siguiente;
				}
				if (actual == 0) {
					actual = siguiente;
					siguiente = 0;
					++nivel;
				}
			}
		}
	}

	if (encontrado) {
		cout << cercano << ' ' << profundidad << '\n';
	}
	else {
		cout << "NO HAY\n";
	}
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   int num;
   cin >> num;
   for (int i = 0; i < num; i++) {
	   resuelveCaso();
   }
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
