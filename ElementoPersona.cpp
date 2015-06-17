#include "stdafx.h"
#include "ElementoPersona.h"

ElementoPersona::ElementoPersona() {
	id = 0;
	nombre = " ";
}

ElementoPersona::ElementoPersona(int id, string nombre) {
	this->id = id;
	this->nombre = nombre;
}

ElementoPersona::~ElementoPersona() {
}

int ElementoPersona::getId() {
	return id;
}

string ElementoPersona::getNombre() {
	return nombre;
}

void ElementoPersona::setId(int id) {
	this->id = id;
}

void ElementoPersona::setNombre(string nombre) {
	this->nombre = nombre;
}

int ElementoPersona::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoPersona * ePer = static_cast<ElementoPersona *>(otro);
	if (ePer != 0) {
		cmp = this->id < ePer->id ? -1 : this->id == ePer->id ? 0 : 1;
	}
	return cmp;
}

void ElementoPersona::imprimir(ostream& out) const {
	out << id << " - " << nombre;
}