#pragma once
#include "queue_eda.h"
#include "vector"

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
	void saltar(int N,vector<int>&res) {
		if (N > 1) {
			Nodo* aux = this->prim;
			bool no_metas = false;
			int tam = this->size();
			for (int i = 0;i < tam-N+1;i++) {
				int max = -1;
				Nodo* aux2 = aux;
				for (int j = 0;j < N;j++) {
						if (max < aux2->elem) {
							max = aux2->elem;
						}
						aux2 = aux2->sig;
						
				}
				if (!no_metas) {
					res.push_back(max);
				}
				aux=aux->sig;
			}
		}
		else {
			Nodo* aux = this->prim;
			for (int i = 0; i < this->size(); i++) {
				res.push_back( aux->elem);
				aux = aux->sig;
			}
		}
	}
};