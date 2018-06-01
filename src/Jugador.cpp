#include "Jugador.h"
#include "glut.h"

Jugador::Jugador(void)
{
	vida='3';
	gameover=false;
}


Jugador::~Jugador(void)
{
}

void Jugador::vidas(char v)
{
	char vidas[] = "VIDAS:";
	int a=0;

	glColor3ub(255,50,50);
	for(int i=0;vidas[i]!='\0';i++)
	{
	glRasterPos3i(4+a,95,1);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,vidas[i]);
	a+=2;
	}
	glRasterPos3i(4+a,95,1);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,v);
}

/*
void Jugador::gameover(void)
{

}
*/