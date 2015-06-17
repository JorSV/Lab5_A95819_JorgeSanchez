#include "stdafx.h"
#include "ElementoDouble.h"

ElementoDouble::ElementoDouble(double d) : Elemento(),
d(d) { 
}

ElementoDouble::~ElementoDouble() {
}

int ElementoDouble::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoDouble * eDoub = static_cast<ElementoDouble *>(otro);
	if (eDoub != 0) {
		cmp = this->d < eDoub->d ? -1 : this->d == eDoub->d ? 0 : 1;
	}
	return cmp;
}

void ElementoDouble::imprimir(ostream& out) const {
	out << d;
}