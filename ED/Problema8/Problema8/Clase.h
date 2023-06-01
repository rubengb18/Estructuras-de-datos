#pragma once
#include "deque_eda.h"
#include <iostream>

template <class T>
class ListaDuplica : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		for (int i = 0; i < 2 * this->size(); i++) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << '\n';
	}
	// duplicar los nodos de una lista enlazada simple
	void duplica() {
		Nodo* aux = this->fantasma->sig;

		for (int i = 0; i < this->size(); i++) {
			Nodo* aux2 = new Nodo(aux->elem, aux,aux->sig);
			aux->sig = aux2;
			aux = aux2->sig;
		}
	}
};
