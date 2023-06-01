
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int calcularExcursionistas(bintree<int>arbol, int &max) {
	int num_eq;
	if (!arbol.empty()) {
		int max_iz, max_dr;
		int cam_iz = calcularExcursionistas(arbol.left(), max_iz);
		int cam_dr = calcularExcursionistas(arbol.right(), max_dr);
		
		if (max_iz < max_dr) {
			max = max_dr;
		}
		else {
			max = max_iz;
		}
		max += arbol.root();
		if (cam_iz == 0 && cam_dr == 0) {
			if (arbol.root() > 0) {
				num_eq = 1;
			}
			else {
				num_eq = 0;
			}
		}
		else {
			num_eq = cam_iz + cam_dr;
		}

	}
	else {
		num_eq = 0;
		max = 0;
	}
	return num_eq;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int vacio = -1, max=0;
	bintree<int> arbol =leerArbol<int>(vacio);
	int res = calcularExcursionistas(arbol, max);
	cout << res << " " << max << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int i;
   cin >> i;
   for (int j = 0; j < i; j++) {
	   resuelveCaso();
   }
      
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
