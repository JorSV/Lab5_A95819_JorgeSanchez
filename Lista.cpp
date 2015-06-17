#include "stdafx.h"
#include "Lista.h"

ostream& operator<<(ostream & salida, const Lista& lista){
	//salida << " { ";
	if (lista.primero){
		salida << *(lista.primero); // invoca al operator<<(cout, const Nodo& primero)
	}
	salida << endl;
	return salida;
}

ostream& operator<<(ostream & salida, const Lista::Nodo& Nodo){
	salida << Nodo.elemento;
	if (Nodo.siguiente){
		//salida << " , ";
		salida << endl;
		salida << *(Nodo.siguiente); // Llamado recursivo a si mismo
	}
	return salida;
}

Lista::Nodo::Nodo(Elemento elemento){
	this->elemento = elemento;
	this->siguiente = 0;
	this->anterior = 0;
}

Lista::Nodo::~Nodo(){
	if (this->siguiente){
		delete this->siguiente;
	}
}

Lista::Lista(){
	primero = ultimo = 0;	// 0 es null
	longitud = 0;           // 0 es 0
}

Lista::Lista(const Lista& otra){
	primero = ultimo = 0;
	longitud = 0;
	if (otra.primero){
		this->agregarAlFinal(otra.primero->elemento);
		Nodo * actualPtr = otra.primero;
		while (actualPtr->siguiente){
			this->agregarAlFinal(actualPtr->siguiente->elemento);
			actualPtr = actualPtr->siguiente;
		}
	}
}

Lista::~Lista(){
	if (this->primero){
		delete this->primero;		//Destruyendo el primer Nodo se destruyen todos
	}
}


int Lista::vacia(){
	return !primero;
}

int Lista::esPosicionValida(int posicion){
	return (posicion >= 0 && posicion < longitud);
}

void Lista::agregarAlFinal(Elemento elemento){
	Nodo * nuevaPtr = new Nodo(elemento);
	if (vacia()){
		primero = ultimo = nuevaPtr;
	}
	else {
		nuevaPtr->anterior = ultimo;
		ultimo->siguiente = nuevaPtr;
		ultimo = nuevaPtr;
	}
	longitud++;

}

Lista::Nodo * Lista::anterior(int posicion){
	Nodo * anteriorPtr = primero;
	int i = 0;
	while (anteriorPtr && i < (posicion - 1)){
		anteriorPtr = anteriorPtr->siguiente;
		i++;
	}
	return anteriorPtr;
}

// La posicion debe ser valida antes de invocar al metodo
Elemento Lista::getElemento(int posicion){
	Nodo * actualPtr = anterior(0);
	Elemento resultado = actualPtr->elemento;
	if (esPosicionValida(posicion)){ // Si la posicion es valida!
		actualPtr = anterior(posicion + 1);
		resultado = actualPtr->elemento;
	}
	return resultado;
}

int Lista::reemplazar(int posicion, Elemento elemento){

	if (esPosicionValida(posicion)){

		int i = 0;
		Nodo* it = primero;

		while (i<posicion){
			it->siguiente;
			i++;
		}

		it->elemento = elemento;
		return 0;

	}
	else{
		return -2;
	}
}

int Lista::tamano(){
	return longitud;
}