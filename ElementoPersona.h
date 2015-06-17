#pragma once

#include "Elemento.h"
using namespace std;

class ElementoPersona : public Elemento {

protected:
	int id;
	string nombre;

public:
	ElementoPersona();
	ElementoPersona(int, string);
	virtual ~ElementoPersona();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;

	void setId(int);
	void setNombre(string);
	int getId();
	string getNombre();
};