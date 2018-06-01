#pragma once
#include "ObjetoMovil.h"

class Barra:public ObjetoMovil
{
public:
	friend class Interaccion;
	float distancia(Vector2D punto, Vector2D *direccion, float *);
	Barra(void);
	float * getLado(int);
	virtual ~Barra(void);

	void Dibuja(void);
};

