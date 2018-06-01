#include "Bordes.h"
#include "Barra.h"
#include "Esfera.h"
#include "Ladrillos.h"
#include "Jugador.h"
#include "ListaLadrillos.h"
#include "ListaDisparos.h"

class Mundo
{
public:
	Bordes bordes;
	Pared fin;
//	Esfera esfera;
	Barra deslizante;
	ListaLadrillos ladrillos;
	ListaDisparos disparos;
	Ladrillos rojo4;
	Ladrillos azul3;
	Ladrillos verde2;
	Ladrillos amarillo1;
	Jugador player;


	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void teclaEspecial2(unsigned char key);
	void Dibuja();
	void Mover();
	void Inicializa();
	void gameover();
};