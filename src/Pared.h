#pragma once
#include "Vector2D.h"
#include "Objeto.h"
class Pared:public Objeto
{
public:
	Pared(void);
	virtual ~Pared(void);
	float distancia(Vector2D punto, Vector2D *direccion=0);

	void Dibuja();
};


