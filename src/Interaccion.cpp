#include "Interaccion.h"
#include "Bordes.h"
#include "Esfera.h"
#include "ListaLadrillos.h"
#include "Barra.h"
#include "ListaDisparos.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion:: rebote(Esfera &e,  Pared p) //ESFERA PAREDES
{
	Vector2D dir; 
	float dif = p.distancia(e.posicion, &dir) - e.radio;  
	if (dif <= 0.0f) 
	{
		Vector2D v_inicial = e.velocidad; 
		e.velocidad = v_inicial - dir * 2.0*(v_inicial*dir); 
		e.posicion = e.posicion - dir * dif; 
		return true; 
	} 
	return false;
}

//AQUI ABAJO, CREO Q YA NOS SOBRA... 
void Interaccion::rebote(Esfera &e, Bordes b)	//ESFERA PAREDES
{
		Interaccion::rebote(e, b.pared_izq);
		Interaccion::rebote(e, b.techo);
		Interaccion::rebote(e, b.pared_dcha);
		Interaccion::rebote(e, b.suelo);
}

void Interaccion::rebote(ListaDisparos disparos, Bordes b)	//ESFERA PAREDES
{
	for(int i=0;i<disparos.numero;i++)
	{
		Interaccion::rebote(*(disparos[i]), b.pared_izq);
		Interaccion::rebote(*(disparos[i]), b.techo);
		Interaccion::rebote(*(disparos[i]), b.pared_dcha);
		Interaccion::rebote(*(disparos[i]), b.suelo);
	}
}

void Interaccion::rebote(Barra &b, Bordes c) //BARRA PAREDES		//CORREGIDA YA PARA NO TENER EN CUENTA EL SUELO
{
	float xmax = (c.pared_dcha.limite1.x)-10; 
	float xmin = c.pared_izq.limite2.x; 
	if (b.posicion.x>xmax)b.posicion.x = xmax; 
	if (b.posicion.x<xmin)b.posicion.x = xmin;
}
		//todavia no funciona, 

bool Interaccion::rebote(Esfera &e, Barra &b)	//ESFERA BARRA****
{
	Vector2D dir;
	float dif = b.distancia(e.posicion, &dir, b.getLado(0)) - e.radio; 
	float li = b.posicion.x;
	float ld = b.posicion.x+(b.limite2.x-b.limite1.x);
	if((e.posicion.x>=li) && (e.posicion.x<=ld) && (dif<=0.0f))
	{
		Vector2D v_inicial = e.velocidad; 
		e.velocidad = v_inicial - dir * 2.0*(v_inicial*dir); 
		e.posicion = e.posicion - dir * dif; 
		return true;
	}
	return false;
}

void Interaccion::rebote(ListaDisparos disparos, Barra &b)	//ESFERAS BARRA***
{
	for(int i=0;i<disparos.numero;i++)
	{
		Interaccion::rebote(*(disparos[i]), b);
	}
}

void Interaccion::rebote(Esfera &e, ListaLadrillos lista)	//ESFERAS LADRILLOS******
{
	for(int i=0;i<lista.numero;i++)
		Interaccion::rebote(e,*(lista[i]));
}

bool Interaccion::rebote(ListaDisparos disparos, ListaLadrillos lista)
{
	for(int i=0;i<disparos.numero;i++){
			for(int j=0;j<lista.numero;j++)
				if(Interaccion::rebote(*(disparos[i]),*(lista[j]))) 
				{
					lista.eliminar(j);
					return true;
				}
	}
	return false;
}