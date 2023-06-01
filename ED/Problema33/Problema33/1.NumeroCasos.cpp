
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <fstream>
#include <unordered_map>
#include <ctype.h>
#include <vector>
#include "treemap_eda.h"
using namespace std;


struct tProblema {
	bool resuelto = false;
	int fallos = 0;
};

struct tEquipo {
	int num_prob = 0;
	int tiempo = 0;
	unordered_map<string, tProblema>map;
};

struct tRes {
	string equipo;
	int tiempo;
	int num_prob_resueltos;
	bool operator<(tRes const& r)const {
		return r.num_prob_resueltos < num_prob_resueltos || (r.num_prob_resueltos == num_prob_resueltos && tiempo < r.tiempo) || (r.num_prob_resueltos == num_prob_resueltos && tiempo == r.tiempo && equipo < r.equipo);
	}
};

void resuelveCaso() {
	unordered_map<string, tEquipo> dicc;
	vector<tRes>result;
	string grupo, problema, veredicto;
	int minutos;
	cin >> grupo;
	while (grupo != "FIN") {
		cin >> problema >> minutos >> veredicto;
		if (!dicc[grupo].map[problema].resuelto) {
			if (veredicto == "AC") {
				dicc[grupo].map[problema].resuelto = true;
				dicc[grupo].tiempo += minutos+dicc[grupo].map[problema].fallos*20;
				dicc[grupo].num_prob++;

			}
			else {
				dicc[grupo].map[problema].fallos++;
			}
		}
		cin >> grupo;
	}
	
	for (auto par : dicc) {
		tRes res;
		res.equipo = par.first;
		res.num_prob_resueltos = par.second.num_prob;
		res.tiempo = par.second.tiempo;
		result.push_back(res);
	}

	sort(result.begin(), result.end());

	for (auto r : result) {
		cout << r.equipo <<" " << r.num_prob_resueltos << " " << r.tiempo<<'\n';
	}
	cout<<"---\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   int num;
   cin >> num;
   cin.ignore();
   for (int i = 0; i < num;i++) {
	   resuelveCaso();
   }
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
