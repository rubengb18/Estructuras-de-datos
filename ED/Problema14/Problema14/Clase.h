#pragma once
#include "deque_eda.h"


template <class T>
class ListaNueva : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
    void print(std::ostream& o = std::cout) const {
        Nodo* aux = this->fantasma->sig;
        for (int i = 0; i < this->size(); i++) {
            o << aux->elem;
            aux = aux->sig;
        }
        o << '\n';
    }

    void volcarLista(ListaNueva<char>& aux1, ListaNueva<char>& aux2) {
        int tam = this->size();
        bool otra = true;
        for (int i = 0; i < tam; i++) {
            if (otra) {
                aux1.push_back(this->front());
            }
            else {
                aux2.push_front(this->front());
            }
            this->pop_front();
            otra = !otra;
        }
        Nodo* punt = aux1.fantasma->sig;
        while (punt != aux1.fantasma) {
            this->push_back(punt->elem);
            punt = punt->sig;
        }
        punt = aux2.fantasma->sig;
        while (punt != aux2.fantasma) {
            this->push_back(punt->elem);
            punt = punt->sig;
        }
    }

    void cambiarCons() {
        Nodo* aux1;
        Nodo* aux2;
        aux1 = this->fantasma->sig;
        aux2 = this->fantasma->sig->sig;
        while (aux2 != this->fantasma) {
            if (!es_vocal(aux1->elem) && !es_vocal(aux2->elem)) {
                int cont = 1;
                while (!es_vocal(aux2->sig->elem)) {
                    aux2 = aux2->sig;
                    cont++;
                }
                if (cont >= 2) {
                    Nodo* aux3 = aux2;
                    for (int i = 0;i < cont / 2;i++) {
                        char c;
                        c = aux2->elem;
                        aux2->elem = aux1->elem;
                        aux1->elem = c;
                        aux1 = aux1->sig;
                        aux2 = aux2->ant;
                    }
                    aux2 = aux3;
                    aux1 = aux3->ant;
                }
                else {
                    char c;
                    c = aux2->elem;
                    aux2->elem = aux1->elem;
                    aux1->elem = c;
                }
            }
            aux1 = aux1->sig;
            aux2 = aux2->sig;
        }
    }

    bool es_vocal(char c) {
        if (c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'E' || c == 'e' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            return true;
        }
        return false;
    }

};