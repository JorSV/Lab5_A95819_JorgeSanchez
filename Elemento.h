#pragma once

#include <iostream>
using namespace std;

class Elemento {

	//friend ostream & operator<<(ostream &, const Elemento &);

protected:
	//Elemento();

public:
	Elemento();
	~Elemento();
	 //int compareTo(Elemento *);
	//void imprimir(ostream &) const;

	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);

};

//ostream & operator<<(ostream &, const Elemento &);