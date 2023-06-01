
//Ruben Gomez y Adrian Perez

#ifndef HORAS_H
#define HORAS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument

class horas {
private:
   int HH; // las horas
   int MM; // los minutos
   int SS; // los segundos 
public:
   // constructora
   horas(int h, int m, int s) {
       if (check(h, m, s)) {
           HH = h;
           MM = m;
           SS = s;
       }
       else {
           throw std::domain_error("datos invalidos");
       }
   }
   horas() {
       HH = 0;
       MM = 0;
       SS = 0;
   }
   
   // observadoras
   int hora() const { return HH; }
   int minuto() const { return MM; }
   int segundo() const { return SS; }

   bool check(int h, int m, int s) {
       return h >= 0 && m >= 0 && s >= 0 && h < 24 && m < 60 && s < 60;
   }

   // operador de comparación
   bool operator<(horas const& h) {
       return HH * 3600 + MM * 60 + SS < h.HH * 3600 + h.MM * 60 + h.SS;
   }

 

   void read(std::istream & input = std::cin) {
       int h, m, s;
       char c;
       input >> h >> c >> m >> c >> s;
       *this = horas(h, m, s);
   }
   void print(std::ostream& o = std::cout) const {
      o << std::setfill('0') << std::setw(2) << HH << ':'
        << std::setfill('0') << std::setw(2) << MM << ':'
        << std::setfill('0') << std::setw(2) << SS;
   }
};

inline std::ostream & operator<<(std::ostream & salida, horas const& h) {
   h.print(salida);
   return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h) {
   h.read(entrada);
   return entrada;
}

#endif
