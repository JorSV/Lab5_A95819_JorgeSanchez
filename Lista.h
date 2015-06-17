#pragma once

#include <iostream>
#include "Elemento.h"
using namespace std;

class Lista {

	friend ostream& operator<<(ostream &, const Lista&);
public:

	class Nodo {

		friend ostream& operator<<(ostream &, const Nodo&);

	public:
		Elemento elemento;
		Nodo * siguiente;	// Apunta la siguiente Nodo en la lista
		Nodo * anterior;	// Apunta a la Nodo anterior en la lista
		Nodo(Elemento);		// inicializa un Nodo con un elemento
		~Nodo();			// Elimina todos los Nodos siguientes...
	};

private:
	Nodo * primero; // apunta a la primer Nodo de la lista
	Nodo * ultimo;  // apunta a la ultimo Nodo de la lista

	int longitud;        // cantidad de elementos
	int esPosicionValida(int);

	// Retorna puntero a la Nodo anterior al indicado
	Nodo * anterior(int);

public:
	Lista();
	Lista(const Lista&);
	~Lista();
	int vacia();
	int tamano();
	void agregarAlFinal(Elemento);
	void agregarEnMedio(int, Elemento);  // Agregar una Nodo nuevo con en una posicion > 0 y < longitud
	Elemento getElemento(int);	// retorna el elemento ubicado en la posicion int, si no existe la posicion retorna null
	int reemplazar(int posicion, Elemento dato);	//reemplaza un elemento con otro enviado como parametro
};