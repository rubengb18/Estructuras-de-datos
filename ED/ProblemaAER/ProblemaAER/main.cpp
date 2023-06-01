
//RUBEN GOMEZ BLANCO(en la primera entrega se me olvido el nombre)

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


bintree<int> funcion(bintree<int> arbol1, bintree<int> arbol2) {
    if (arbol1.empty() && arbol2.empty()) {
        return {};
    }
    else if (arbol1.empty()){
        return arbol2;
    }
    else if (arbol2.empty()) {
        return arbol1;
    }
    else {
        return { funcion(arbol1.left(),arbol2.left()),arbol1.root() + arbol2.root(),funcion(arbol1.right(),arbol2.right()) };
    }
}

void escribir(bintree<int> arbol) {
    if (!arbol.empty()) {
        cout << arbol.root()<<" ";
        escribir(arbol.left());
        escribir(arbol.right());
    }
    else {
        cout << "-1 ";
    }
}

bool resuelveCaso() {
   bintree<int> arbol1 = leerArbol(-1), arbol2 = leerArbol(-1),res;
   
   res=funcion(arbol1, arbol2);
   if (arbol1.empty() && arbol2.empty()) {
       return false;
   }
   else {
       escribir(res);
   }
   cout << '\n';
   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
  while(resuelveCaso()) {
      
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
