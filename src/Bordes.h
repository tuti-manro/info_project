#pragma once
#include "Pared.h"

class Bordes
{
public:
	friend class Interaccion;

	Bordes(void);
	virtual ~Bordes(void);
	void Dibuja();
	Pared getSuelo();

private:
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
	
public: Pared suelo;
};

