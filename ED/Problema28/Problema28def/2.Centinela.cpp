
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "treemap_eda.h"  // propios o los de las estructuras de datos de clase
#include <unordered_map>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	char c;
	cin >> n;
   if (n==0)
      return false;
   string nombre, punt;
   map<string, int> dicc;
   for (int i = 0; i < n; i ++) {
	   cin.get(c);
	   getline(cin, nombre);
	   cin>> punt;
	   if (dicc.count(nombre) == 1) {
		   if (punt == "INCORRECTO") {
			   dicc[nombre] += -1;
		   }
		   else {
			   dicc[nombre] += 1;
		   }
	   }
	   else {
		   if (punt == "INCORRECTO") {
			   dicc[nombre] = -1;
		   }
		   else {
			   dicc[nombre] = 1;
		   }
	   }
   }
   auto it=dicc.begin();
   auto it2 = it;
   while (it2 != dicc.end()) {
	   it = it2;
	   if (dicc[it->clave]==0) {
		   ++it2;
		   dicc.erase(it->clave);
	   }
	   else {
		   ++it2;
	   }
   }

   for (auto const& par : dicc) {
	   cout << par.clave << ", " << par.valor << '\n';
   }
   cout << "---"<<'\n';
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
   system("PAUSE");
#endif
   return 0;
}
