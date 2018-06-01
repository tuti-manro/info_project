#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Esfera:public ObjetoMovil
{
public:
	friend class Interaccion;

	Esfera(void);
	virtual ~Esfera(void);
	void Dibuja();
	void SetRadio(float);


private:

	float radio;
};


