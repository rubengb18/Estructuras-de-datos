
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include "treemap_eda.h"
using namespace std;

void escribirlista(vector<string> lista) {
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i] << " ";
	}
	cout << '\n';
}

bool resolver(map<string, int> dicc1, map<string, int> dicc2,vector<string>&listaadd , vector<string>&listamas , vector<string>&listamenos ) {
	bool cambia = false;
	for (auto key:dicc2) {
		if (dicc1.find(key.clave)==dicc2.end()) {
			cambia = true;
			listamas.push_back(key.clave);
		}
		else {
			if (key.valor != dicc1[key.clave]) {
				cambia = true;
				listaadd.push_back(key.clave);
			}
		}
	}
	for (auto key : dicc1) {
		if (dicc2.find(key.clave)== dicc2.end()) {
			cambia = true;
			listamenos.push_back(key.clave);
		}
	}
	return cambia;
}

map<string, int> leerDicc() {
	map<string, int> dicc;
	string c, v;
	int t;
	getline(cin, c);
	stringstream ss(c);
	while (ss >> v) {
		ss >> t;
		dicc[v] = t;
	}
	return dicc;
}

bool resuelveCaso() {
	vector<string>listaadd, listamas, listamenos;
	auto dicc1 = leerDicc();
	auto dicc2 = leerDicc();
	
	if (resolver(dicc1, dicc2, listaadd, listamas, listamenos)) {
		if (listamas.size() > 0) {
			cout << "+ ";
			escribirlista(listamas);
		}
		if (listamenos.size() > 0) {
			cout << "- ";
			escribirlista(listamenos);
		}
		if (listaadd.size() > 0) {
			cout << "* ";
			escribirlista(listaadd);
		}
	}
	else {
		cout << "SIN CAMBIOS" << '\n';
	}
	cout << "---" << '\n';
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
   cin.ignore(1);
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
