#pragma once
#include <string>


class persona {
protected:
	string nombre;
	int edad;
public:
	int getEdad() {
		return edad;
	}
	string getNombre() {
		return nombre;
	}
	void setEdad(int ed) {
		edad = ed;
	}
	void setNombre(string nom) {
		nombre = nom;
	}
};
