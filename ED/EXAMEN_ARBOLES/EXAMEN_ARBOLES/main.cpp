
// RUBEN GOMEZ BLANCO

/* La idea del algoritmo es ir acomulando la suma que tiene cada arbol, el izq y el derecho, con un entero por parametro que se vaya encargando de acumular las sumas.
Por lo tanto si el arbol es vacio, la suma es 0 y devuelvo verdadero. Si el arbol no lo es, veo si es una hoja, en este caso a la suma le sumo la raiz del nodo apuntado y devuelvo true
Cuando me meta en un nodo interno, la suma ya sera la de este nodo mas la suma de sus dos arboles hijos. La funcion aux devolvera en este caso un booleano
que comprobara tanto si la suma del hijo iz es menor que la del derecho, como que tanto el arbol derecho como el izquierdo son diestros.

El algoritmo es lineal respecto al numero de nodos O(N) con N numero de nodos, ya que llamo recursivamente a hijo y me recorro tods los nodos del arbol.

*/


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites

bool aux(bintree<int>arbol, int &suma) {
    if (!arbol.empty()) {
        if (arbol.left().empty() && arbol.right().empty()) {
            suma = arbol.root();
            return true;
        }
        else {
            int suma_iz, suma_dr;
            auto cam_iz = aux(arbol.left(), suma_iz);
            auto cam_dr = aux(arbol.right(), suma_dr);

            suma =arbol.root()+ suma_iz + suma_dr;

            return cam_iz && cam_dr && suma_iz < suma_dr;
        }
    }
    else {
        suma = 0;
        return true;
    }
}

bool diestro(bintree<int>arbol) {
    int i;
    if (aux(arbol, i)) {
        return true;
    }
    else {
        return false;
    }
    
}

void resuelveCaso() {
   auto arbol = leerArbol(-1);
   if (diestro(arbol))
      cout << "SI\n";
   else
      cout << "NO\n";
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
   // system("PAUSE");
#endif
   return 0;
}
