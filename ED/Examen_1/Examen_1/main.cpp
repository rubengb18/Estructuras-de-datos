
//RUBEN GOMEZ BLANCO DG16

/*
Recorremos en un bucle la cola para ir mirando elemento por elemento, con el puntero act que empieza en el siguiente del fantasma.
Si el elemento apuntado es mayor que el pivote, primero cambiamos el sigiente del anterior de act al siguiente de act, y luego el anterior dl siguiente de act
para que apunte al anterior de act. Coin esto ya habremos "sacado" al nodo apuntado por act.
Ahora falta meterlo al final de la lista. Para ello ponemos el siguiente de act al fantasma, el anterior al anterior del fantasma, el anterior del fantasma a act
y el siguiente del anterior del fantasma( el que era antes el ultimo) a act.
Antes de todo esto, habiamos creado un nodo auxiliar que apuntase al siguiente de act para no perder esareferencia y poder seguyir avanzando nodos en la cola doble.
Por esto, una vez realizado todos los cambios en los punteros, ponemos act=aux para actualizarlo y seguir con el bucle.

Si el elemento apuntado por act es menor que el pivote, se queda como estas y avanzamos el act a su siguiente.

Para el metoo print empezamos con el nodo act apuntando al siguiente del fantasma(el primero) y con un for nos recorremos el tamaño de la cola doble imprimiendo por pantalla el 
elemento apuntado. Despues actualizamos el act a su siguiente.


El algoritmo de particion tiene orden lineal O(N) siendo N el numero de nodo de la cola doble, ya que solo hacemos un bucle for de esa longitud
y la operacion de igualdad con los punteros es constante.

El algoritmo de print tambien es lineal O(N) con N el numero de nodos de la cola doble ya que solo hacemos un bucle for de esa longitud
y imprimir por pantalla es constante
*/



#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
public:
   void print(std::ostream& o = std::cout) const {
       Nodo* act = this->fantasma->sig;
       for (int i = 0;i < this->size();i++) {
           o << act->elem << " ";
           act = act->sig;
       }
   }
   
   // produce la partición de la lista respecto al privote
   void particion(int pivote) {
       Nodo* act = this->fantasma->sig;
       for(int i=0;i<this->size();i++){
           if (act->elem > pivote) {
               Nodo* aux = act->sig;
               act->ant->sig = act->sig;
               act->sig->ant = act->ant;

               act->sig = this->fantasma;
               act->ant = this->fantasma->ant;
               this->fantasma->ant->sig = act;
               this->fantasma->ant = act;
               
               act = aux;
           }
           else {
               act = act->sig;
           }
       }
   }
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, ListaParticion const& a) {
   a.print(o);
   return o;
}

bool resuelveCaso() {
   int N, pivote;
   cin >> N >> pivote;
   if (!cin)
      return 0;
   
   ListaParticion lista;
   // leemos la lista de la entrada
   int elem;
   for (int i = 0; i < N; ++i) {
      cin >> elem;
      lista.push_back(elem);
   }
   
   
   lista.particion(pivote);
   
   cout << lista << '\n';
   
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif
   return 0;
}
