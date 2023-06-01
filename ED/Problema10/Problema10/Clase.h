#pragma once
#include "queue_eda.h"


template <class T>
class ListaNueva : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		for (int i = 0; i < this->size(); i++) {
			o << aux->elem<< " ";
			aux=aux->sig;
		}
		o <<'\n';
	}
	// inserta la listaSec en la lista principal
	void insertar(ListaNueva &listaSec,int P) {
		if (P == 0) {
			Nodo* aux2 = listaSec.prim;
			Nodo* aux = listaSec.prim;
			for (int i = 0;i < listaSec.size() - 1;i++) {
				aux2 = aux2->sig;
			}
			aux2->sig = this->prim;
			this->prim = aux;
		}
		else {
			Nodo* aux = this->prim;
			for (int i = 0;i < P - 1;i++) {
				aux = aux->sig;
			}
			Nodo* aux3 = aux->sig;
			aux->sig = listaSec.prim;
			Nodo* aux2 = listaSec.prim;
			for (int i = 0;i < listaSec.size() - 1;i++) {
				aux2 = aux2->sig;
			}
			aux2->sig = aux3;
		}
		this->nelems += listaSec.size();
		listaSec.nelems = 0;
		listaSec.prim = NULL;
	}
};