#pragma once
#include "Vector2D.h"

class Objeto
{
public:
	Vector2D posicion;
	Vector2D limite1;  
	Vector2D limite2;
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;

	Objeto(void);
	virtual ~Objeto(void);
	void SetPos(float,float);
	void SetPos(float,float,float,float);
	void SetColor(unsigned char, unsigned char, unsigned char);
	Vector2D GetPos(void);
};
