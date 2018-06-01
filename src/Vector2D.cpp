#include "Vector2D.h"
#include <cmath>

Vector2D::~Vector2D(void)
{
}

float Vector2D::modulo()						//modulo
{
	return (float)sqrt(x*x+y*y);
}

float Vector2D::argumento()						//arg. vector
{
	return (float)atan2(y,x);
}

Vector2D Vector2D::unitario()					//vector unitario
{
	Vector2D retorno(x,y);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod;
	}
	return retorno;
}

Vector2D Vector2D::operator - (Vector2D &v)			//resta de vectores
{
	Vector2D res;
	res.x=x-v.x;
	res.y=y-v.y;
	return res;
}

Vector2D Vector2D::operator + (Vector2D &v)		//suma vectores
{
	Vector2D res;
	res.x=x+v.x;
	res.y=y+v.y;
	return res;
}

float Vector2D::operator *(Vector2D &v)			//producto escalar
{
	return x*v.x+y*v.y;
}

Vector2D Vector2D::operator *(float esc)		//producto por un escalar
{
	Vector2D res;
	res.x = x*esc;
	res.y = y*esc;
	return res;
}