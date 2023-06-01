
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	char c;
	cin >> c;
	if (!cin) {
		return false;
	}
	if (c=='N') {
		int vacio = -1;
		bintree<int> arbol = leerArbol<int>(vacio);
		cout << arbol.calcularMin() << '\n';
	}
	else if (c=='P') {
		string vacio = "#";
		bintree<string> arbol = leerArbol<string>(vacio);
		cout << arbol.calcularMin() << '\n';
	}

	return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso()) {
   }
      
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
