
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int altura(int p) {
	int n, tot = 0;
	cin >> n;
	if (n == 0 && p <= 0) {
		tot++;
	}
	for (int i = 0;i < n;i++) {
		tot += altura(p - 1);
	}
	return tot;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int lim;
	cin >>lim;
	if (!cin) {
		return false;
	}
	cout << altura(lim) << '\n';
	return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
 while(resuelveCaso()){}
      
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
