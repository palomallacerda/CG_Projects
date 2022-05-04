#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define x_position 10
#define y_position 10

// Angles around the earth
static GLfloat velocidade1, velocidade2, moon1, moon2;
static float flag1 = 0.0f;
static float flag2 = 0.0f;
static float flag3 = 0.0f;
static float flag4 = 0.0f;
static GLfloat angle, fAspect;
float cam_x, cam_y, cam_z;
float center_x, center_y, center_z;

//###############################################################
//Função responsável pela chamada de gerenciamento do teclado
void keyboard_setting(unsigned char key, int x, int y){
    switch (key){
		case 'X':
        case 'x':
            glRotatef(moon1, 3,0, 0);
            glRotatef(moon2, 0, 3, 0);
            velocidade1 = flag1;
            velocidade2 = flag2;
            break;
		case 'Y':
        case 'y':
			glTranslatef (5, 0 , 0);
            glRotatef(velocidade1, 5,0,0);
            velocidade2 = flag2;
            moon1 = flag3;
            moon2 = flag4;
            break;
		default:
            // glRotatef(velocidade1, 0,5, 0);
			// exit(0);
			break;
    }

	// EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

//###############################################################
// Função usada para especificar o volume de visualização

void EspecificaParametrosVisualizacao(){
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle,fAspect,0.1,1100);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(cam_x,cam_y,cam_z, center_x,center_y,center_z, 0,1,1);
}

//###############################################################
// Função callback chamada para gerenciar eventos do mouse

void GerenciaMouse(int button, int state, int x, int y){
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

//###############################################################
//Função responsável pelos ajustes de tela
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;
	EspecificaParametrosVisualizacao();
}

//###############################################################
// Called to draw scene
void display(){
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    // Reset the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Translate the whole scene out and into view
    // This is the initial viewing transformation
    glTranslatef(0.0f, 0.0f, -120.0f);
    // glRotatef(0, 0,40, 360);

    // Yellow sun
    glColor3ub(255, 255, 0);
    // glScaled(2,2,2);s
    glutSolidSphere(7.0f, 30, 30);
    // // Save viewing transformation
    glPushMatrix();
    // // Primeira lua 
    // // Rotate by angle of the moon
    // glRotatef(velocidade2, 0.0f, 1.0f, 0.0f);
    // // Translate out from origin to orbit distance
    // glTranslatef(90.0f, 0.0f, 0.0f);

    // Restore the viewing transformation
    // glPopMatrix();
    
    // firt planet
    glPushMatrix();
    glRotatef(180.0f, 0.0f, 0.0f, 50.0f);
    glRotatef(velocidade1, 0.0f, 1.0f, 0.0f);
    glTranslatef(-30.0f, 0.0f, 0.0f);
    glColor3ub(0,0,255);
    glutSolidSphere(3.0f, 15.5f, 15.5f);
    glPopMatrix();

   //##############################################################//
    // glPushMatri/x();
    // Second planet
    glRotatef(360.0f, -45.0f, 0.0f, 2.0f);
    glRotatef(velocidade1, 0.0f, 1.0f, 0.0f);
    glTranslatef(10.0f, 0.0f, 30.0f);
    glColor3ub(255,0,0);
    glutSolidSphere(3.0f, 15.5f, 15.5f);
    
    //Drawing moons
    glPushMatrix();
    glColor3ub(192,192,192);
    glRotatef(moon1, 5.0f, 0.0f, 0.0f);
    glTranslatef(5.0f, 1.0f, 10.0f);
    glutSolidSphere(1.0f, 15, 15);
    glColor3ub(235,192,192);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(moon2, 1.0f, 0.0f, 0.0f);
    glTranslatef(5.0f, 5.0f, 5.0f);
    // glRotatef(45.0f, 0,0,0);
    glutSolidSphere(1.0f,15,15);
    glPopMatrix();

    //##############################################################//
    flag1 = velocidade1;
    flag2 = velocidade2;
    flag3 = moon1;
    flag4 = moon2;
    // 
    angle +=10.0f;
    velocidade1 -= 10.0f;
    velocidade2 += 40.0f;
    moon1 += 4.0f;
    moon2 += 8.0f;
    
    if(angle > 360.0f) 
        angle = 0.0f;

    if(velocidade1 <=0)
        velocidade1 = 360.0f;

    if(velocidade2 > 360.0f)
        velocidade2 = 0.0f;

    if(moon1 > 360.0f)
        moon1 = 0.0f;

    if(moon2 > 360.0f)
        moon2 = 0.0f;
    // Show the image
    glutSwapBuffers();
}

//###############################################################
void starting (){ 
    //definindo a cor e o angulo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle= 45;
    velocidade1 = 360;
    velocidade2 = 0;
    moon1 = 0;
    moon2 = 0;
	cam_z = 0.0f;
	cam_y = 50.0f;
	cam_x = 0.0f;
	center_x = 0.0f; center_y = 10.0f; center_z = 0.0f;
}
//###############################################################
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);

	glutCreateWindow("Paloma - Solar_System");
    glutPositionWindow(x_position,y_position);
    starting();    
    glutKeyboardFunc(keyboard_setting);
    // glutMouseFunc(GerenciaMouse);
    glutDisplayFunc(display);
    glutReshapeFunc(AlteraTamanhoJanela);

    glutMainLoop();
    return 0;
}