#include "Pared.h"
#include "glut.h"

Pared::Pared(void)
{
}


Pared::~Pared(void)
{
}

void Pared::Dibuja(void)
{
	glColor3ub(rojo,verde,azul);
	glBegin(GL_QUADS);
		glVertex3f(limite1.x, limite1.y, 1.0f);
		glVertex3f(limite2.x, limite1.y, 1.0f);
		glVertex3f(limite2.x, limite2.y, 1.0f);
        glVertex3f(limite1.x, limite2.y, 1.0f);
    glEnd();
}

float Pared::distancia(Vector2D punto, Vector2D *direccion)
{  
	Vector2D u=(punto-limite1);
	Vector2D v=(limite2-limite1).unitario();
	float longitud=(limite1-limite2).modulo(); 
	Vector2D dir; 
	float valor=u*v; 
	float distancia=0; 

	if (valor<0)   
		dir = u; 
	else if (valor>longitud)  
		dir = (punto - limite2);  
	else
		dir = u - v * valor;  
	distancia = dir.modulo(); 
	if (direccion != 0) //si nos dan un vector…  
		*direccion=dir.unitario();  
	return distancia;
}