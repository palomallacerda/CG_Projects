/**
* @file    MAIN.cpp
* @author  Thales Vieira <thalesv@gmail.com>
* @author  Instituto de Matem�tica, UFAL
* @version 0.1
* @date    16/03/2010
*
* @brief   Esqueleto de programa usando a GLUT para
* @brief   o curso de Computa��o Gr�fica Interativa
*/
//________________________________________________
#include <GL/gl.h>
#include <GL/glut.h> 
#include <iostream>

#include <math.h>
/***
* display():
*   Esta fun��o � chamada quando a janela precisa ser
*   redesenhada
***/

typedef struct {
	float x;
	float y;
} ponto2D;

ponto2D p1;
ponto2D p2;


ponto2D ponto_medio;


ponto2D CalcularPontoMedio(ponto2D p1, ponto2D p2)
{
	ponto2D pm;
	pm.x=(p1.x+p2.x)/2.;
	pm.y=(p1.y+p2.y)/2.;
	return pm;
};


void keyboard_callback(unsigned char key, int x, int y) 
{
	if (key == 'P') 
	{
		ponto_medio=CalcularPontoMedio(p1,p2);
		printf("\nPonto Medio: %f %f",ponto_medio.x,ponto_medio.y);
	}
}


void display() {
   // Limpa a tela com a cor preta (RGB: preta)

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);

   // Determina a cor de desenho(RGB: branca)
   
   // Ativa o modo de desenho LINES (segmentos de reta)
   //  Desenha os v�rtices dos segmentos sequencialmente
   //  usando glVertex3f.

	glColor3f(1.,1.,0.);

	glPointSize(4);
	glLineWidth(2);

   glBegin(GL_LINES);
	glVertex2f(p1.x,p1.y);
	glVertex2f(p2.x,p2.y);
   glEnd();

   if(ponto_medio.x>-99. && ponto_medio.y >-99.)
   {
	   glColor3f(0.,0.,1.);
	   glBegin(GL_POINTS);
	   glVertex2f(ponto_medio.x,ponto_medio.y);
	   glEnd();
   }

   glutSwapBuffers(); //Atualiza o BUFFER
}

/***
* init():
*   Configura o OpenGL.
*   Configuramos a matriz de 
*   proje��o ortogonal ortogonal, neste caso.
***/
void init() {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

/***
* main():
*    Esta � a fun��o que � chamada quando executamos o programa. Vamos inicializar janelas
e configurar o GLUT aqui.
***/
int main(int argc, char** argv) {

	p1.x=0.5;
	p1.y=0.9;
	p2.x=0.1;
	p2.y=0.7;

	ponto_medio.x=ponto_medio.y=-100.;

   // Inicializa o ambiente do GLUT
   glutInit(&argc, argv);

   // Configura��es de janela e de sistema de cor.
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(250,250);
   glutInitWindowPosition(100,100);

   // Cria a janela do GLUT com o t�tulo "Hello World!"
   glutCreateWindow("Hello World!");

   // Determina qual fun��o deve ser chamada para desenhar na tela (draw)
   glutDisplayFunc(display);

   glutKeyboardFunc(keyboard_callback); 


   // Esta fun��o inicializa configura��es do OpenGL
   init();

   // Exibe a janela e desenha na tela, usando a fun��o determinada em glutDisplayFunc
   glutMainLoop();
   return 0;
}