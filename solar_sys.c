/* Atividade realizada por Paloma Lacerda para a disciplina de Computação Gráfica
na Universidade Federal de Alagoas. 

Para compilar:  gcc solar_sys.c -o solar -lGL -lglut -lGLU */

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 640
#define x_position 1800
#define y_position 45

GLuint textura[10];

// Variaveis para controlar a camera
GLfloat angle, fAspect;
float cam_x, cam_y, cam_z;
float center_x, center_y, center_z;



void setup_lighting()
{  
	float mat_specular[] = {1.0f, 0.0f, 1.0f};
	float mat_shininess[] = {70.0f};
	float light_ambient[] = {0.9f, 0.7f, 0.1f};
	float light_position[] = {1.0f, 0.0f, 1.0f};
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void texture_define(){
}

// Função callback chamada para fazer o desenho
void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenha o Sol
	GLUquadric *qobj = gluNewQuadric();

	setup_lighting(); 
	glEnable(GL_TEXTURE_2D);
	gluQuadricTexture(qobj,GL_TRUE); 
	
	glBindTexture(GL_TEXTURE_2D,textura[0]);
	glPushMatrix();
	glRotated(60*angle, 1, 0, 1);
	gluSphere(qobj,10.39,40,40);

	glDisable(GL_TEXTURE_2D);

	//desenha planeta 1

	glTranslatef(-25.0f, 0.0f, 0.0f);
	GLUquadric *qobj1 = gluNewQuadric();
	gluQuadricTexture(qobj1,GL_TRUE);

	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D,textura[1]);
	glPushMatrix();
	gluSphere(qobj1,5.0,20,20);
	glRotated(60*angle, 1, 0, 1);


	// glPopMatrix();

	//gluDeleteQuadric(qobj);

	// glColor3f(0.0f, 0.0f, 1.0f);
    // glutWireSphere(50.0f, 25.0f, 20.0f);
    
	// Desenha o teapot com a cor corrente (wire-frame)
	// glutWireTeapot(50.0f);
    // glutSolidSphere(40.0f, 20.0f, 15.0f);
    // glColor3f(1.0f, 0.0f,0.0f);
    // glutWireSphere(30.0f, 5.0f, 3.0f);
    // glTranslatef(5.0f, 5.0f,0.5f);

	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void starting (void)
{ 
    //definindo a cor e o angulo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle=45;
	cam_z = 5.0f;
	cam_y = 80.0f;
	cam_x = 0.0f;
	center_x = 0.0f; center_y = 0.0f; center_z = 0.0f;

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
	gluLookAt(cam_x,cam_y,cam_z, center_x,center_y,center_z, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
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

//Função responsável pela chamada de gerenciamento do teclado
void keyboeard_setting(unsigned char key, int x, int y){
    switch (key){
        case 'x':
            //Gira ao redor do eixo x
            glRotatef(angle, 1,0,0);
            break;
        case 'y':
            //Gira ao redor do eixo y
            glRotatef(angle, 0,1, 0);
            break;
        default: 
            printf("ESTIVE AQUI\n");   
            break;
    }

	// EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}


// Programa Principal
int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInit(&argc, argv);

	glutCreateWindow("Solar_System");
    
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutPositionWindow(x_position, y_position);
    glutDisplayFunc(display);

	glutReshapeFunc(AlteraTamanhoJanela);

	glutMouseFunc(GerenciaMouse);
    
    glutKeyboardFunc(keyboeard_setting);
	// glEnable(GL_DEPTH_TEST);
	

    starting();

	glutMainLoop();
}
