// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "clase.h"

using namespace std;  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string funcion,dni;
	int puntos;
	carnet_puntos i;
	cin >> funcion;
	if (funcion=="FIN") {
		return false;
	}
	if (funcion == "consultar") {
		cin >> dni;
		cout<<"Puntos de DNI: "<<i.consultar(dni);
	}
	else if(funcion == "cuantos_con_puntos") {
		cin >> puntos;
		cout << i.consultar(dni);
	}
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
