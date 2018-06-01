#include "Objeto.h"

Objeto::Objeto(void)
{
}

Objeto::~Objeto(void)
{
}

void Objeto::SetPos(float x,float y)
{
	posicion.x=x;
	posicion.y=y;
}

Vector2D Objeto::GetPos(void)
{
	return posicion;
}

void Objeto::SetPos(float x1,float y1,float x2,float y2)
{
	limite1.x=x1;
	limite1.y=y1;
	limite2.x=x2;
	limite2.y=y2;
	posicion.x=x1;
	posicion.y=y1;
}


void Objeto::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo	= r;
	verde	= v;
	azul	= a;
}
