#include "Esfera.h"
#include "glut.h"

Esfera::Esfera(void)
{
	SetColor(0,255,0);
	SetPos(50.0f,5.0f);
	SetRadio(1.0f);
	setVel(0.0f,18.0f);
}

Esfera::~Esfera(void)
{
}

void Esfera::Dibuja()
{
	glColor3ub(rojo,verde,azul);
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio, 100, 100);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Esfera::SetRadio(float rad)
{
	radio=rad;
}
