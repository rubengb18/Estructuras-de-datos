
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "queue_eda.h"
using namespace std; // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
vector<int> resolver(queue<int>&cola1, queue<int> &cola2) {
    vector<int>res;
    int tam = cola1.size() + cola2.size();
    for (int i = 0;i < tam;i++) {
        if (!cola1.empty() && !cola2.empty()) {
            if (cola1.front() < cola2.front()) {
                res.push_back(cola1.front());
                cola1.pop();
            }
            else if (cola1.front() >= cola2.front()) {
                res.push_back(cola2.front());
                cola2.pop();
            }
        }
        else if (cola1.empty()) {
            res.push_back(cola2.front());
            cola2.pop();
        }
        else if(cola2.empty()){
            res.push_back(cola1.front());
            cola1.pop();
        }
    }
    return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   vector<int>res;   
   queue<int>cola1, cola2;
   int n;
   cin >> n;
   while (n != 0) {
       cola1.push(n);
       cin >> n;
   }
   cin >> n;
   while (n != 0) {
       cola2.push(n);
       cin >> n;
   }

   res = resolver(cola1,cola2);
   for (auto num : res) {
       cout << num << " ";
   }
   cout << '\n';
   // escribir solución
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   cin.ignore(1);
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
