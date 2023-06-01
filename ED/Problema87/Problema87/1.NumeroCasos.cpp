
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "set_eda.h"
 // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n,c,m,low,up;
	set<int> conj;
	pair<bool, int> par;
	cin >> n>>m;
	if (!cin) {
		return false;
	}
	for (int i = 0;i < n;i++) {
		cin >> c;
		conj.insert(c);
	}

	for (int i = 0;i < m;i++) {
		cin >> low >> up;
		cout<<conj.count_interval(low, up) << '\n';
	}

	cout << "---\n";
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
