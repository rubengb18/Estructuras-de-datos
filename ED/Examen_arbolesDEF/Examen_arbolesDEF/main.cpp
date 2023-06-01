
//RUBEN GOMEZ BLANCO(en la primera entrega se me olvido el nombre)

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

/*La idea es ir cogiendo las alturas de los hijos izq y der (como el haciamos para calcular el diametro en el problema del juez) pero 
distinguiendo el caso de que cuando la raiz no sea par dejamos la altura a 0
La longitud del camino sera siempre el maximo entre el camino del hijo izq y del hijo der, a no ser que la raiz sea par y entonces hay que tener en cuenta tambien
el maximo entre este y 1+altIz+altDr
El orden sera lineal respectoal numero n de nodos en el arbol (O(n))
int alt_iz,alt_dr,cam,aux;
	if (!arbol.empty()) {
		auto cam_iz = caminoPares(arbol.left(),alt_iz);
		auto cam_dr = caminoPares(arbol.right(),alt_dr);

		if (arbol.root() % 2 == 0) {
			alt =1 + max(alt_iz, alt_dr);
			aux = 1 + alt_dr + alt_iz;
		}
		else {
			alt= 0;
			aux = 0;
		}
		cam = max(max(cam_iz, cam_dr),aux);
		return cam;
	}
	else {
		alt = 0;
		cam = 0;
	}
	return cam;*/

int caminoPares(bintree<int> arbol,int &alt) {
	int alt_iz, alt_dr,m;
	if (!arbol.empty()) {
		auto cam_iz = caminoPares(arbol.left(), alt_iz);
		auto cam_dr = caminoPares(arbol.right(), alt_dr);

		int m = 0;
		if (arbol.root() % 2 == 0) {
			alt = 1 + max(alt_iz, alt_dr);
			m = 1 + alt_iz + alt_dr;
		}
		else {
			m = 0;
		}
		return max(max(cam_iz, cam_dr),m);
	}
	else {
		alt = 0;
		return 0;
	}
	
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   int alt=0;
   cout << caminoPares(arbol,alt) << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
