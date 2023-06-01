
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;  // propios o los de las estructuras de datos de clase


struct tRes {
	int nivel = 0;
	bool com=false, semicom=false;
};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tRes funcion(bintree<char> arbol, int nivel) {
	tRes res;
	int niv_iz, niv_dr;
	if (!arbol.empty()) {
		auto res_iz = funcion(arbol.left(), niv_iz);
		auto res_dr = funcion(arbol.right(), niv_dr);
		nivel = max(niv_iz, niv_dr) + 1;
		if (res_iz.nivel == res_dr.nivel && res_iz.com && res_dr.com) {
			res.com = true;
			res.semicom = true;
		}
		else {
			if (!arbol.left().empty() && !arbol.right().empty()) {
				if (res_iz.semicom && res_dr.com && res_dr.nivel + 1 == res_iz.nivel) {
					res.semicom = true;
				}
				else if (res_iz.com && (res_dr.com || res_dr.semicom) && res_iz.nivel == res_dr.nivel) {
					res.semicom = true;
				}
			}
			else if(!arbol.left().empty()){
				if (res_dr.nivel + 1 == res_iz.nivel) {
					res.semicom = true;
				}
			}
		}
	}
	else {
		res.com = true;
		res.semicom = true;
		res.nivel = 0;
	}
	return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char vacio ='.';
	tRes res;
	bintree<char> arbol = leerArbol<char>(vacio);
	res=funcion(arbol, 0);
	if (res.semicom) {
		cout << "SEMICOMPLETO\n";
	}
	else if (res.com) {
		cout << "COMPLETO\n";
	}
	else {
		cout << "NADA\n";
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
