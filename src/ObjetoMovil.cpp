#include "ObjetoMovil.h"


ObjetoMovil::ObjetoMovil(void)
{
}


ObjetoMovil::~ObjetoMovil(void)
{
}

void ObjetoMovil::Mover(float t)
{
	posicion = posicion + velocidad*t + aceleracion*(0.5f*t*t);
	velocidad = velocidad + aceleracion*t;
}

void ObjetoMovil::setVel(float vx, float vy) 
{  
	velocidad.x=vx;  
	velocidad.y=vy; 
}