#pragma once
#include "persona.h"

class Predicate {
private:
	int ini;
	int fin;
public:
	Predicate(int i, int f) {
		ini = i;
		fin = f;
	}

	bool operator() (persona p) {
		if (p.getEdad()<=fin && p.getEdad()>=ini) {
			return true;
		}
		else {
			return false;
		}
	}

};

