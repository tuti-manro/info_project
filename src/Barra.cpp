#include "Barra.h"
#include "glut.h"
#include "cmath"

Barra::Barra(void)
{
}


Barra::~Barra(void)
{

}

void Barra::Dibuja()//CAMBIO
{
	//como la barra tiene unas dimensiones de 10x1 , con saber un punto ya vale
	//Cuando hacemos SetPos en mundo.cpp(inicializa) para la barra tenemos que indicar la esquina superior derecha de la barra.
	float rangox,rangoy;
	rangox = limite2.x-limite1.x;
	rangoy = limite1.y-limite2.y;
	glColor3ub(rojo,verde,azul);
	glBegin(GL_QUADS);
	glVertex3f(posicion.x,posicion.y-rangoy, 1.0f);	//esquina inferior izquierda
	glVertex3f(posicion.x+rangox,posicion.y-rangoy, 1.0f);		//esquina inferior derecha
	glVertex3f(posicion.x+rangox,posicion.y, 1.0f);		//esquina superior izquierda
	glVertex3f(posicion.x,posicion.y, 1.0f);		//esquina superior derecha
    glEnd();
}

float Barra::distancia(Vector2D punto, Vector2D *direccion, float *vector)
{  
	Vector2D l1,l2;
	l1.x = vector[0];
	l1.y = vector[1];
	l2.x = vector[2];
	l2.y = vector[3];

	Vector2D u=(punto-l1);
	Vector2D v=(l2-l1).unitario();
	float longitud=(l1-l2).modulo(); 
	Vector2D dir; 
	float valor=u*v; 
	float distancia=0; 

	if (valor<0)   
		dir = u; 
	else if (valor>longitud)  
		dir = (punto - l2);  
	else
		dir = u - v * valor;  
	distancia = dir.modulo(); 
	if (direccion != 0) //si nos dan un vector…  
		*direccion=dir.unitario();  
	return distancia;
}

float * Barra::getLado(int i)
{
	float vector[4]; //(l1x,l1y,l2x,l2y)
	switch(i)
	{
	case '0':	//superior
		vector[0] = posicion.x;
		vector[1] = posicion.y;
		vector[2] = posicion.x + abs(limite2.x-limite1.x);
		vector[3] = posicion.y;
		break;
	case '1':	//derecho
		vector[0] = posicion.x + abs(limite2.x-limite1.x);
		vector[1] = posicion.y;
		vector[2] = posicion.x + abs(limite2.x-limite1.x);
		vector[3] = limite2.y;
		break;
	case '2':	//inferior
		vector[0] = posicion.x + abs(limite2.x-limite1.x);
		vector[1] = limite2.y;
		vector[2] = posicion.x;
		vector[3] = limite2.y;
		break;
	case '3':	//izquierdo
		vector[0] = posicion.x;
		vector[1] = limite2.y;
		vector[2] = posicion.x;
		vector[3] = posicion.y;
		break;
	}
	return vector;

		// BARRA (45,2,55,1)
	/*
	POSICION = 45,2
	LIMITE 2 = 55,1
	rango = limite 2-limite1
	para 0 (superior)-> l1 = 45,2;
						l2 = 55,2;
	para 1 (derecho)->	l1 = 55,2;
						l2 = 55,1;
	para 2 (inferior)->	l1 = 55,1;
						l2 = 45,1;
	para 3 (izquier)->	l1 = 45,1;
						l2 = 45,2;
	*/

}