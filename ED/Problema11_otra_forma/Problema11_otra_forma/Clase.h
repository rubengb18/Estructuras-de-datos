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
	void insertar(ListaNueva &listaSec) {
		
		Nodo* aux_lp = this->prim;
		Nodo* aux_ls = listaSec.prim;
		Nodo* act = aux_lp;
		if (!this->empty() && !listaSec.empty()) {
			if (this->front() > listaSec.front()) {
				this->prim = listaSec.prim;
				act = aux_ls;
				aux_ls = aux_ls->sig;
			}
			else {
				aux_lp = aux_lp->sig;
			}
			if (this->ult->elem < listaSec.ult->elem) {
				this->ult = listaSec.ult;
			}
			while (aux_lp != NULL && aux_ls != NULL) {
				if (aux_lp->elem < aux_ls->elem) {
					act->sig = aux_lp;
					aux_lp = aux_lp->sig;
				}
				else {
					act->sig = aux_ls;
					aux_ls = aux_ls->sig;
				}
				act = act->sig;
			}
			if (aux_lp == NULL) {
				act->sig = aux_ls;
			}
			else {
				act->sig = aux_lp;
			}
		}
		else if(this->empty()){
			this->prim = listaSec.prim;
			this->ult = listaSec.ult;
		} 
		this->nelems += listaSec.size();
		listaSec.prim = NULL;
		listaSec.nelems = 0;
	}
};