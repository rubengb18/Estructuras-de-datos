
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool es_sim(bintree<char> arbol1, bintree<char> arbol2) {
	if (!arbol1.empty() && !arbol2.empty()) {
		if ((!arbol1.left().empty() && arbol2.right().empty()) || (arbol1.left().empty() && !arbol2.right().empty())|| (!arbol1.right().empty() && arbol2.left().empty()) || (arbol1.right().empty() && !arbol2.left().empty())) {
			return false;
		}
		else{
			return es_sim(arbol1.left(), arbol2.right()) && es_sim(arbol1.right(), arbol2.left());
		}
	}
	else if(!arbol1.empty()){
		return false;
	}
	else if (!arbol2.empty()) {
		return false;
	}
	else {
		return true;
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char vacio ='.';
	bintree<char> arbol = leerArbol<char>(vacio);
	bool sim = es_sim(arbol.left(), arbol.right());
	if(sim) {
		cout << "SI";
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
