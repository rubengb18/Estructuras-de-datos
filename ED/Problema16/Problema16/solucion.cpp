//Ruben Gomez y Adrian Perez

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "list_eda.h"
#include "persona.h"
#include "Predicate.h"

bool resuelveCaso() {
    int N, ini, fin;
    int ed;
    string nom;
    persona per;
    list<persona>listaPersonas;
    cin >> N >> ini >> fin;
    Predicate pred(ini, fin);
    if (N == 0 && ini == 0 && fin == 0) {
        return false;
    }

    for (int i = 0; i < N; i++) {
		cin >> ed;
		getline(cin, nom);
        per.setEdad(ed);
        per.setNombre(nom);
        listaPersonas.push_back(per);
    }
	listaPersonas.removeif(pred);
    for (auto per : listaPersonas) {
        cout << per.getEdad() << " " << per.getNombre() << '\n';
    }
	cout<<"---"<<'\n';
    
    return true;
}
int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}