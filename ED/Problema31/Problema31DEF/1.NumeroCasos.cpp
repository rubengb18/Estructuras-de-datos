
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <fstream>
#include <unordered_map>
#include <ctype.h>
#include <vector>
#include <sstream>
#include "treemap_eda.h"
using namespace std;

void escribirVector(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

void escribirDicc(map<string, vector<int>>& dicc1) {
	for (auto  par : dicc1) {
		cout << par.clave << " ";
		escribirVector(par.valor);
		cout<< '\n';
	}
}


void resolver(map<string,vector<int>>&dicc1,int fila) {
	string linea;
	getline(cin, linea);
	stringstream ss(linea);
	string palabra;
	while (ss >> palabra) {
		for (char & c:palabra)
			c=tolower(c);
		if (palabra.size() > 2 ) {
			if(dicc1[palabra].empty()|| dicc1[palabra].back() != fila)
				dicc1[palabra].push_back(fila);
		}
	}
}

bool resuelveCaso() {
	map<string, vector<int>> dicc1;
	int num;
	cin >> num;
	if(num==0) {
		return false;
	}
	cin.ignore();
	for (int i = 0; i<num; i++) {
		resolver(dicc1,i+1);
	}
	escribirDicc(dicc1);
	cout << "---\n";
	return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   while(resuelveCaso()){
   }
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
