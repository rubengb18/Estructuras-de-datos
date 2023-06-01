
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int altura_sub(bintree<char> arbol, int& alt) {
	int m;
		if (arbol.left().empty() || arbol.right().empty()) {
			m = 1;
			if (!arbol.left().empty()) {
				altura_sub(arbol.left(), alt);

			}
			if (!arbol.right().empty()) {
				altura_sub(arbol.right(), alt);
			}
		}
		else {
			m = min(altura_sub(arbol.right(), alt), altura_sub(arbol.left(), alt))+1;
		}
		alt = max(m,alt);
		return m;

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char vacio ='.';
	bintree<char> arbol = leerArbol<char>(vacio);
	int i = 0;
	if (arbol.empty()) {
		cout << "0" << '\n';
	}
	else {
		altura_sub(arbol, i);
		cout << i << '\n';
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
