
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <fstream>
#include <unordered_map>
#include <ctype.h>
#include <unordered_set>
#include <vector>
#include "treemap_eda.h"
using namespace std;




bool resuelveCaso() {
	unordered_map<string, unordered_set<string>>map1;//Para cada deporte la lista de nombres
	map<string, string>map2;//Para cada nombre el deporte
	vector<pair<string, int>> res;
	string palabra, deporte;
	if (!cin) {
		return false;
	}
	cin >> palabra;
	while (palabra != "_FIN_") {
		if (isupper(palabra[0])) {
			deporte = palabra;
			map1.insert({ deporte,{} });
		}
		else {
			auto insertado = map2.insert({ palabra,deporte });
			if (insertado) {
				map1[deporte].insert(palabra);
			}
			else {
				if (map2.at(palabra)!=deporte) {
					map2.erase(palabra);
				}
			}

		}
		cin >> palabra;
	}

	for (auto const& par:map1) {
		res.push_back({ par.first,par.second.size() });
	}

	sort(res.begin(), res.end(), [](pair<string, int> const& a, pair<string, int> const& b) {
		return (a.second > b.second) || (a.second == b.second && a.first < b.first);
	});
	
	for (auto par : res) {
		cout << par.first << " " << par.second << "\n";
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
   while(resuelveCaso()){
   }
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
