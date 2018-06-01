//#include "Mundo.h"


#include "Interaccion.h"
#include <stdlib.h>
#include <glut.h>
#include "Coordinador.h"

Coordinador coordinador;
//Mundo mundo;

//Keyboard

#define KEY_LEFT 100
#define KEY_RIGHT 102
#define KEY_ESCAPE 27

//State del cursor key
static int left = 0;
static int right = 0;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);										//esta funcion sera llamada para dibujar
void OnTimer(int value);								//esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y);	//cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y) ;
void onSpecialKeyboardDown2(int key, int x, int y) ;
//void glutSpecialUpFunc(void);
/*void keyboard(unsigned char, int, int);
void keyPress(int,int,int);
*/

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Arkanoid");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 80.0, 1.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(5,OnTimer,0);		//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	
	//Keyboard
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);
	glutSpecialUpFunc(onSpecialKeyboardDown2);

//	mundo.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	coordinador.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	coordinador.Tecla(key);
//	coordinador.teclaEspecial(key);							 //repetido debajo y no se por qué
	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	coordinador.teclaEspecial(key);
}
void onSpecialKeyboardDown2(int key, int x, int y)
{
	coordinador.teclaEspecial2(key);
}

void OnTimer(int value)
{
//poner aqui el código de animacion

	coordinador.mueve();
	//no borrar estas lineas
//	mundo.teclaEspecial();

	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

