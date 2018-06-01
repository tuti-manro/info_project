// ListaDisparos.cpp: implementation of the ListaDisparos class.
//
//////////////////////////////////////////////////////////////////////

#include "ListaDisparos.h"
#include "Interaccion.h"
#include "Esfera.h"
#include "Ladrillos.h"

ListaDisparos::ListaDisparos()
{
	destruirContenido();
}

ListaDisparos::~ListaDisparos()
{

}

void ListaDisparos::dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->Dibuja();
}

void ListaDisparos::mueve(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->Mover(t);
}

void ListaDisparos::destruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];

	numero=0;
}

void ListaDisparos::destruirDisparo(int index)
{
		if((index<0)||(index>=numero))
		return;
	
	delete lista[index];

	numero--;
	for(int i=index;i<=numero;i++)
		lista[i]=lista[i+1];
}

bool ListaDisparos::agregar(Esfera *d)
{
	for(int i=0;i<numero;i++)//para evitar que se a�ada una esfera ya existente
		if(lista[i]==d)
			return false;

	if(numero<MAX_DISPAROS)
	   lista[numero++]=d;
	else 
		return false;
	return true;
}

Esfera *ListaDisparos::operator [](int i)
{
	if(i>=numero)
		i=numero-1;
	if(i<0)
		i=0;
	
	return lista[i];
}

