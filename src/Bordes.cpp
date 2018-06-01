#include "Bordes.h"


Bordes::Bordes(void)
{
	pared_izq.SetColor(150,150,150);
	pared_izq.SetPos(0.0f,0.0f,1.0f,97.0f);

	techo.SetColor(150,150,150);
	techo.SetPos(0.0f,97.0f,98.0f,98.0f);

	pared_dcha.SetColor(150,150,150);
	pared_dcha.SetPos(97.0f,98.0f,98.0f,0.0f);

	suelo.SetColor(150,150,150);
	suelo.SetPos(0.0f,0.0f,98.0f,0.0f);
}


Bordes::~Bordes(void)
{
}

void Bordes::Dibuja()
{
	pared_izq.Dibuja();
	techo.Dibuja();
	pared_dcha.Dibuja();
}
//FALTA COMENT WHAT IS THIS?
Pared Bordes::getSuelo()
{
	return suelo;
}