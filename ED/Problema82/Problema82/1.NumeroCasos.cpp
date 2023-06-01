
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


int tramos(bintree<int> arbol, int& cont) {
	if (!arbol.empty()) {
		if (!arbol.left().empty() || !arbol.right().empty()) {
			int tr_iz = tramos(arbol.left(), cont);
			int tr_dr = tramos(arbol.right(), cont);
			if (tr_iz < 0) {
				tr_iz = 0;
			}
			if (tr_dr < 0) {
				tr_dr = 0;
			}
			if (tr_iz + tr_dr - arbol.root() >= 3) {
				cont++;
			}
			return tr_iz + tr_dr - arbol.root();
		}

		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int vacio =-1;
	bintree<int> arbol = leerArbol<int>(vacio);
	int cont = 0,cont2=0;
	tramos(arbol.left(), cont);
	tramos(arbol.right(), cont2);
	cout << cont+cont2 << '\n';
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