
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
struct tRes {
	bool es_gen=true;
	int generaciones=0;
};

tRes es_gen(bintree<int> arbol) {
	tRes res;
	if (!arbol.empty()) {
		if (!arbol.left().empty() && !arbol.right().empty()) {
			if (arbol.left().root()+18 > arbol.root() || arbol.right().root() + 18 > arbol.root()) {
				res.es_gen = false;
			}
		}
		else if (!arbol.left().empty()) {
			if (arbol.left().root() + 18 > arbol.root()) {
				res.es_gen = false;
			}
		}
		else if (!arbol.right().empty()) {
			if (arbol.right().root() + 18 > arbol.root()) {
				res.es_gen = false;
			}
		}
		if (!arbol.left().empty() && !arbol.right().empty()) {
			if (arbol.left().root()-2 < arbol.right().root()) {
				res.es_gen = false;
			}
		}
		else if (arbol.left().empty() && !arbol.right().empty()) {
			res.es_gen = false;
		}
		res.generaciones = 1 + max(es_gen(arbol.right()).generaciones, es_gen(arbol.left()).generaciones);
		if (res.es_gen) {
			res.es_gen = es_gen(arbol.right()).es_gen && es_gen(arbol.left()).es_gen;
		}
		return res;
	}
	else{
		res.es_gen = true;
		res.generaciones = 0;
		return res;
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int vacio = -1;
	bintree<int> arbol = leerArbol<int>(vacio);
	tRes res= es_gen(arbol);

	if (res.es_gen) {
		cout<<"SI " << res.generaciones;
	}
	else {
		cout << "NO";
	}
	cout << '\n';
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
