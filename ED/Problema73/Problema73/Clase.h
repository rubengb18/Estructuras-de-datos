#pragma once

#include <iostream>
#include"queue_eda.h"
#include"horas.h"

template <class T>
class Lista : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		for (int i = 0; i <this->size(); i++) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << '\n';
	}
	void salta() {
		int tam = this->size();
		Nodo* ant= this->prim;
		Nodo* aux = this->prim->sig;
		while(ant->sig!=NULL) {
			if (aux->elem<ant->elem) {
				ant->sig = aux->sig;
				aux = aux->sig;
				--this->nelems;
			}
			else {
				ant = ant->sig;
				aux=aux->sig;
			}
		}
		
		
	}
};
