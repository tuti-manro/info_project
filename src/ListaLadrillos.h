#pragma once
#include"Ladrillos.h"

#define MAX_LADRILLOS 100

class ListaLadrillos
{
public:
	ListaLadrillos(void);
	~ListaLadrillos(void);
	void dibuja();
	int numero;
	Ladrillos* operator[] (int index);
	bool agregar(Ladrillos *e);
//	void eliminar(Ladrillos *e);
	void eliminar(int index);

private:
	Ladrillos * lista[MAX_LADRILLOS];
	
};

