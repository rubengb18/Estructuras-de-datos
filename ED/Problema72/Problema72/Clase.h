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
		for (int i = 0;i < tam/2; i++) {
			Nodo* aux = ant->sig;
			ant->sig = aux->sig;
			ant = ant->sig;
			aux->sig = nullptr;
			delete(aux);
			--this->nelems;
		}
		
		
	}
};
