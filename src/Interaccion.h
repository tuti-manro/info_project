#include "Bordes.h"
#include "Esfera.h"
#include "Barra.h"
#include "ListaLadrillos.h"
#include"ListaDisparos.h"

#pragma once
class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();
	static bool rebote(Esfera &e,  Pared p);
	static void rebote(Esfera &e, Bordes b);
	static void rebote(ListaDisparos disparos, Bordes p);  ///// HECHA


	static void rebote(Barra &b, Bordes c);
	static bool rebote(Esfera &e, Barra &b);
	static void rebote(ListaDisparos disparos, Barra &b);  ///// HECHA

	static void rebote(Esfera &e, ListaLadrillos lista);
	static bool rebote(ListaDisparos disparos, ListaLadrillos lista);  ////// 
	
};
