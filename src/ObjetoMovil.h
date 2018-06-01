#pragma once
#include "Objeto.h"

class ObjetoMovil:public Objeto
{
	public:
	Vector2D velocidad;
	Vector2D aceleracion;

	void Mover(float);
	void setVel(float, float);
	ObjetoMovil(void);
	virtual ~ObjetoMovil(void);
};