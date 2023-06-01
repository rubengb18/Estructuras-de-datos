
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool resuelveCaso() {
	unordered_map<int,int> dicc;
	int num, c;
	int p = 0, maximo = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> c;
		if (dicc.count(c) && dicc[c] >= p) {
			p = dicc[c] + 1;
		}
		maximo = max(maximo, i - p + 1);
		dicc[c] = i;
	}
	cout << maximo << '\n';
	return true;
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
