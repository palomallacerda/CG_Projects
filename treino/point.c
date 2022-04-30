#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
GLfloat angle, fAspect;
float cam_x, cam_y, cam_z;
float center_x, center_y, center_z;

//Função responsável pela chamada de gerenciamento do teclado
void keyboeard_setting(unsigned char key, int x, int y){
    switch (key){
        case 'x':
            //Gira ao redor do eixo x
			glTranslatef (0.5, 0 , 0);
            glRotatef(angle, 1,0,0);
            break;
        case 'y':
            //Gira ao redor do eixo y
			glTranslatef (0 , 0.5, 0);
            glRotatef(angle, 0,1, 0);
            break;
        default: 
            printf("ESTIVE AQUI\n");   
            break;
    }

	// EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}



// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao()
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle,fAspect,0.1,300);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(cam_x,cam_y,cam_z, center_x,center_y,center_z, 0,0,1);
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;
	EspecificaParametrosVisualizacao();
}

// Called to draw scene
void display(){
    // Angle of revolution around the nucleus
    static GLfloat fElect1 = 0.0f;
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    // Reset the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Translate the whole scene out and into view
    // This is the initial viewing transformation
    glTranslatef(0.0f, 0.0f, -100.0f);

    // Yellow sun
    glColor3ub(255, 255, 0);
    glutSolidSphere(7.0f, 15, 15);
    
    // blue earth
    glColor3ub(0,0,255);
    
    // Draw the electron
    glTranslatef(50.0f, 0.0f, -50.0f);

    glutSolidSphere(6.0f, 15, 15);
    
    // First Electron 
    
    // Save viewing transformation
    glPushMatrix();
    
    // Rotate by angle of revolution
    glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
    
    // Translate out from origin to orbit distance
    glTranslatef(90.0f, 0.0f, 0.0f);

    // Restore the viewing transformation
    glPopMatrix();
    
    // firts moon
    glPushMatrix();
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
    glTranslatef(-40.0f, 0.0f, 0.0f);
    glColor3ub(192,192,192);
    glutSolidSphere(6.0f, 15.0f, 15.0f);
    glPopMatrix();

    // Second Moon
    glPushMatrix();
    glRotatef(360.0f, -45.0f, 0.0f, 1.0f);
    glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 30.0f);
    glColor3ub(192,192,192);
    glutSolidSphere(6.0f, 15, 15);
    glPopMatrix();  

    // 
    fElect1 += 10.0f;
    if(fElect1 > 360.0f)
        fElect1 = 0.0f;

    // Show the image
    glutSwapBuffers();
}
void starting (void)
{ 
    //definindo a cor e o angulo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle= 45;
	cam_z = 5.0f;
	cam_y = 80.0f;
	cam_x = 0.0f;
	center_x = 0.0f; center_y = 0.0f; center_z = 0.0f;

}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);

	glutCreateWindow("Meu ponto");
    starting();    
    glutKeyboardFunc(keyboeard_setting);
    glutMouseFunc(GerenciaMouse);
    glutDisplayFunc(display);
    glutReshapeFunc(AlteraTamanhoJanela);

    glutMainLoop();
    return 0;
}