#pragma once

#define MAX_DISPAROS 3
#include "Esfera.h"
#include "Bordes.h"

class ListaDisparos  
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	
	bool agregar(Esfera* d);
	void destruirContenido();
	void destruirDisparo(int i);
	void mueve(float t);
	void dibuja();

	void colision(Pared p);		//no estan realizadas
	void colision(Bordes c);	//tampoco
	int numero;

	Esfera* operator[] (int index);
private:
	Esfera * lista[MAX_DISPAROS];
	
};
