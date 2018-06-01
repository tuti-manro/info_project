#include "ListaLadrillos.h"
#include"Ladrillos.h"


ListaLadrillos::ListaLadrillos(void)
{
	numero=0;
	for(int i=0;i<MAX_LADRILLOS;i++)lista[i]=0;
}

ListaLadrillos::~ListaLadrillos(void)
{
}

void ListaLadrillos::dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->Dibuja();
}

Ladrillos *ListaLadrillos::operator [](int i)
{
	if(i>=numero)
		i=numero-1;
	if(i<0)
		i=0;
	
	return lista[i];
}

bool ListaLadrillos::agregar(Ladrillos *e)
{
	for(int i=0;i<numero;i++)//para evitar que se añada un ladrillo ya existente
		if(lista[i]==e)
			return false;

	if(numero<MAX_LADRILLOS)
	   lista[numero++]=e;
	else 
		return false;
	return true;
}

void ListaLadrillos::eliminar(int index)
{
	if((index<0)||(index>numero))
		return;
	
	delete lista[index];

	numero--;
	for(int i=index;i<=numero;i++)
		lista[i]=lista[i+1];

}

/*
void ListaLadrillos::eliminar(Ladrillos *e)
{
	for(int i=0;i<numero;i++)
  		if(lista[i]==e)
		{
	  		eliminar(i);
	  		return;
		}
}
*/