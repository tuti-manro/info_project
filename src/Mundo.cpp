#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"
#include "Barra.h"
#include"Ladrillos.h"
#include"ListaLadrillos.h"
#include"Esfera.h"

void Mundo::Dibuja()

{
	int c=0;
	char nombre[] = "ARKANOID";

	gluLookAt(50.0,50.0,65.0,
			50.0,50.0,0.0,
			0.0,1.0,0.0);
		
		//METER EN UNA CLASE - BACKGROUND 
	
	glDisable(GL_LIGHTING);
	/*
	glColor3ub(0,0,200);
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(100, 0);
		glVertex2f(100, 100);
        glVertex2f(0, 100);
    glEnd();
	*/

	//Nombre Juego ARKANOID
	glColor3ub(255,255,255);
	for(int i=0;nombre[i]!='\0';i++)
	{
	glRasterPos3i(30+c,100,1);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,nombre[i]);
	c+=5;
	}

	//Dibujar
	ladrillos.dibuja();
//	esfera.Dibuja();
	disparos.dibuja();
	bordes.Dibuja();
	deslizante.Dibuja();
//	amarillo1.Dibuja();
	player.vidas(player.vida);
	if(player.vida=='0')
		player.gameover=true;
}

void Mundo::Mover()
{
	disparos.mueve(0.025f);
//	esfera.Mover(0.025f);
	deslizante.Mover(0.025f);
	Interaccion::rebote(disparos, bordes);
	Interaccion::rebote(deslizante, bordes);
	Interaccion::rebote(disparos, deslizante);
	Interaccion::rebote(disparos, ladrillos);
/*
	for(int i=0;i<disparos.numero;i++){				////EL PROBLEMA DE QUE NO SE ROMPAN LOS LADRILLOS ESTÁ AQUÍ EN LOS ÍNDICES 
		for(int j=0;j<ladrillos.numero;j++){		////HAY QUE REVISARLO PUES
			if(Interaccion::rebote(*disparos[i], *ladrillos[j]))	ladrillos.eliminar(j);
		}
	}
*/
for(int j=0;j<disparos.numero;j++){
	if(Interaccion::rebote(*disparos[j], bordes.suelo) == true)
	{
		disparos.destruirDisparo(j);
		if(player.vida>'0')player.vida-=1;
	}
//	if(player.vida=='0')
//		player.gameover = true;

}
}

void Mundo::Inicializa()
{
/*
	esfera.SetColor(0,255,0);
	esfera.SetPos(50.0f,5.0f);
	esfera.SetRadio(1.0f);
	esfera.setVel(0.0f,40.0f);
*/
	disparos.destruirContenido();
	player.vida='3';
	player.gameover=false;

	deslizante.SetColor(255,0,0);
	deslizante.SetPos(45.0f,2.0f,55.0f,1.0f);	//Unico, cambio setpos de x e y , no limites

/*
	Ladrillos *l1=new Ladrillos(55.0f,2.0f,65.0f,5.0f);  // A LA HORA DE CONSTRUIR LOS LADRILLOS EL ARGUMENTO 3>1, ARGUMENTO 4>2 SIEMPRE
	l1->SetColor(0,0,255);								 // SINO LA COLISIÓN Y ELIMINACIÓN DE LADRILLOS NO FUNCIONA
	ladrillos.agregar(l1); 

	Ladrillos *l2=new Ladrillos(25.0f,9.0f,35.0f,6.0f);
	l2->SetColor(0,255,0);
	ladrillos.agregar(l2); 

	Ladrillos *l3=new Ladrillos(5.0f,16.0f,15.0f,13.0f);
	l3->SetColor(255,0,0);
	ladrillos.agregar(l3); 

	Ladrillos *l4=new Ladrillos(55.0f,20.0f,65.0f,23.0f);
	l4->SetColor(0,0,255);
	ladrillos.agregar(l4); 

	Ladrillos *l5=new Ladrillos(25.0f,36.0f,35.0f,39.0f);
	l5->SetColor(255,255,255);
	ladrillos.agregar(l5); 

	Ladrillos *l6=new Ladrillos(5.0f,26.0f,15.0f,29.0f);
	l6->SetColor(255,0,0);
	ladrillos.agregar(l6); 
*/
	Ladrillos *l1=new Ladrillos(5.0f,20.0f,15.0f,23.0f);  // A LA HORA DE CONSTRUIR LOS LADRILLOS EL ARGUMENTO 3>1, ARGUMENTO 4>2 SIEMPRE
	l1->SetColor(0,0,255);								 // SINO LA COLISIÓN Y ELIMINACIÓN DE LADRILLOS NO FUNCIONA
	ladrillos.agregar(l1); 

	Ladrillos *l2=new Ladrillos(17.0f,20.0f,27.0f,23.0f);
	l2->SetColor(0,255,0);
	ladrillos.agregar(l2); 

	Ladrillos *l3=new Ladrillos(29.0f,20.0f,39.0f,23.0f);
	l3->SetColor(255,0,0);
	ladrillos.agregar(l3); 

	Ladrillos *l4=new Ladrillos(41.0f,20.0f,51.0f,23.0f);
	l4->SetColor(0,0,255);
	ladrillos.agregar(l4); 

	Ladrillos *l5=new Ladrillos(53.0f,20.0f,63.0f,23.0f);
	l5->SetColor(255,255,255);
	ladrillos.agregar(l5); 

	Ladrillos *l6=new Ladrillos(65.0f,20.0f,75.0f,23.0f);
	l6->SetColor(255,0,0);
	ladrillos.agregar(l6); 

	Ladrillos *l7=new Ladrillos(5.0f,30.0f,15.0f,33.0f);  // A LA HORA DE CONSTRUIR LOS LADRILLOS EL ARGUMENTO 3>1, ARGUMENTO 4>2 SIEMPRE
	l7->SetColor(255,0,255);								 // SINO LA COLISIÓN Y ELIMINACIÓN DE LADRILLOS NO FUNCIONA
	ladrillos.agregar(l7); 

	Ladrillos *l8=new Ladrillos(17.0f,30.0f,27.0f,33.0f);
	l8->SetColor(136,0,0);
	ladrillos.agregar(l8); 

	Ladrillos *l9=new Ladrillos(29.0f,30.0f,39.0f,33.0f);
	l9->SetColor(255,255,0);
	ladrillos.agregar(l9); 

	Ladrillos *l10=new Ladrillos(41.0f,30.0f,51.0f,33.0f);
	l10->SetColor(0,0,255);
	ladrillos.agregar(l10); 

	Ladrillos *l11=new Ladrillos(53.0f,30.0f,63.0f,33.0f);
	l11->SetColor(255,255,255);
	ladrillos.agregar(l11); 

	Ladrillos *l12=new Ladrillos(65.0f,30.0f,75.0f,33.0f);
	l12->SetColor(255,0,100);
	ladrillos.agregar(l12); 
/*
	amarillo1.SetColor(0,255,0);
	amarillo1.SetPos(45.0f,7.0f,55.0f,5.0);
*/

/*
	player.vida = '3';
	player.gameover = false;					SE INICIALIZA EN EL CONSTRUCTOR ANA
*/

//	fin.SetPos(10.0f,10.0f,90.0f,90.0f);
//	fin.SetColor(0,0,255);
}

void Mundo::teclaEspecial(unsigned char key) 
{ 
		switch(key) 
		{  
			case GLUT_KEY_LEFT: 
				deslizante.setVel (-25.0f, 0.0f);
					break;  
			case GLUT_KEY_RIGHT:  
				deslizante.setVel (25.0f, 0.0f);  
					break;	
		}
} 

void Mundo::teclaEspecial2(unsigned char key)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		deslizante.setVel (0.0f,0.0f);
			break;
	case GLUT_KEY_RIGHT:
		deslizante.setVel (0.0f,0.0f);
			break;
	}
}

void Mundo::gameover()
{
//	fin.Dibuja();
}

void Mundo::tecla(unsigned char key)
{
		switch(key)
	{
		case ' ':
			{
 				Esfera* d=new Esfera();
				Vector2D pos=deslizante.GetPos();
				d->SetPos(pos.x + 1,pos.y + 1);
				disparos.agregar(d);

				break;
			}
//		case 'r':
//			Inicializa();
//			break;

	}

}
