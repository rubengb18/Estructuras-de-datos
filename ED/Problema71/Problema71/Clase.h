#pragma once
#include "queue_eda.h"
template <class T>
class ListaInsert : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		for (int i = 0; i< this->size(); i++) {
			o << aux->elem << ' ';
			aux = aux->sig;
		}
		o << '\n';
	}

	void insertar() {
		int tam = this->size();
		if (tam > 1) {
			Nodo* aux = this->prim->sig;
			this->prim->sig = aux->sig;
			aux->sig = this->prim;
			this->prim = aux;
			Nodo* ant = this->prim->sig;
			while (ant->sig != NULL && ant->sig->sig != NULL) {
				aux = ant->sig->sig;
				ant->sig->sig = aux->sig;
				aux->sig = ant->sig;
				ant->sig = aux;
				ant = ant->sig->sig;
			}
			if (tam % 2 == 0) {
				this->ult = ant;
			}
		}
	}
};

