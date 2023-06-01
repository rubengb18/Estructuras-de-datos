#pragma once
#include <list>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


using DNI = string;

class carnet_puntos {

	unordered_map<DNI, pair<int, list<DNI>::iterator>> conductores;

	vector<list<DNI>>por_puntos;

	list<DNI>::iterator insertar_por_puntos(DNI c, int p) {
		auto & lista = por_puntos[p];
		return lista.insert(lista.begin(), c); //devuelve el iterador que habra que insertar en el diccionario
	}

public:
	carnet_puntos() :por_puntos(16) {}

	void nuevo(DNI conductor) {
		if (conductores.count(conductor) == 1) {
			throw std::domain_error("Conductor duplicado");
		}
		conductores.insert({ conductor,{15,insertar_por_puntos(conductor,15)} });

	}

	void quitar(DNI conductor, int p) {
		auto it = conductores.find(conductor);
		if (it==conductores.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		auto& par = it->second;
		if (par.first > 0 && p > 0) {
			por_puntos[par.first].erase(par.second);
			par.first = max(0, par.first - p);
			par.second = insertar_por_puntos(conductor, par.first);
		}
	}

	void recuperar(DNI conductor, int p) {
		auto it = conductores.find(conductor);
		if (it == conductores.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		auto& par = it->second;
		if (par.first < 15 && p > 0) {
			por_puntos[par.first].erase(par.second);
			par.first = min(15, par.first +p);
			par.second = insertar_por_puntos(conductor, par.first);
		}
	}

	int consultar(DNI conductor) {
		auto it = conductores.find(conductor);
		if (it == conductores.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		return it->second.first;
	}

	int cuantos_con_puntos(int p) const {
		if (p < 0 || p>15) {
			throw domain_error("Puntos no validos");
		}
		return (int)por_puntos[p].size();
	}

	list<DNI> const& lista_por_puntos(int p) const {
		if (p < 0 || p>15) {
			throw domain_error("Puntos no validos");
		}
		return por_puntos[p];
	}
};