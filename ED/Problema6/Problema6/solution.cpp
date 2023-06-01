//Ruben Gomez y Adrian Perez


#include <string>
#include <fstream>
#include <iostream>
#include "stack_eda.h"
using namespace std;

bool resuelveCaso() {
	stack<char>pila;
	string linea;
	getline(cin, linea);
	if (!cin) {
		return false;
	}
	bool res = true;
	int i = 0;
	while (res==true && i<linea.size()) {
		if (linea[i] == '(' || linea[i] == '[' || linea[i] == '{') {
			pila.push(linea[i]);
		}
		else if (linea[i] == ')') {
			if (pila.empty()) {
				res = false;
			}
			else {
				if (pila.top() != '(') {
					res = false;
				}
				else {
					pila.pop();
				}
			}
		}
		else if (linea[i] == ']') {
			if (pila.empty()) {
				res = false;
			}
			else {
				if (pila.top() != '[') {
					res = false;
				}
				else {
					pila.pop();
				}
			}
		}
		else if (linea[i] == '}') {
			if (pila.empty()) {
				res = false;
			}
			else {
				if (pila.top() != '{') {
					res = false;
				}
				else {
					pila.pop();
				}
			}
		}
		i++;
	}
	if (res) {
		cout << "SI" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	while (resuelveCaso()) {}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}