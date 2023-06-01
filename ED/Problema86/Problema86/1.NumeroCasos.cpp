
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

vector<int> funcion(bintree<int> arbol) {
	vector<int> res;
	bool mete = true;
	if (!arbol.empty()) {
		queue<bintree<int>>cola;
		cola.push(arbol);
		int nivel = 1, act = 1, sig = 0;
		while (!cola.empty()) {
			auto a = cola.front();
			if (mete) {
				res.push_back(a.root());
			}
			mete = false;
			cola.pop();
			--act;
			auto iz = a.left();
			if (!iz.empty()) {
				cola.push(iz);
				sig++;
			}
			auto dr = a.right();
			if (!dr.empty()) {
				cola.push(dr);
				sig++;
			}
			if (act == 0) {
				act = sig;
				sig = 0;
				nivel++;
				mete = true;
			}
		}
	}
	return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int vacio =-1;
	bintree<int> arbol = leerArbol<int>(vacio);
	vector<int> res = funcion(arbol);
	for (auto a : res) {
		cout << a << " ";
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
