#pragma once
#include "queue_eda.h"
#include <iostream>
template <class T>
class ListaInvert : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		for (int i = 0; i< this->size(); i++) {
			o << aux->elem << ' ';
			aux = aux->sig;
		}
	}

	void invertir() {
		Nodo* act = this->prim->sig;
		Nodo* inv = NULL;
		Nodo* amover = this->prim;
		while (amover != NULL) {
			amover->sig = inv;
			inv = amover;
			amover = act;
			if (act != NULL) {
				act = act->sig;
			}
		}

		swap(this->prim, this->ult);
	}
};

