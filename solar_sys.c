#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define x_position 10
#define y_position 10

typedef struct Vertex{
	float x, y, z;
	float r, g, b;
} Vertex;

Vertex vertices[] = {
	{-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f}, // vermelho
	{ 0.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f}, // verde
	{ 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f}, // azul
};

// Variaveis para controlar a camera
float fov_y;
float cam_x, cam_y, cam_z;
float center_x, center_y, center_z;

/*
Aqui faremos as operacoes de renderização
*/
void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Seleciona a matriz ModelView e reseta todas as transformacoes   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   
    // Define a matriz View
    gluLookAt(cam_x, cam_y, cam_z, center_x, center_y, center_z, 0.0f, 1.0f, 0.0f);
    
    glTranslatef(-4.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.5f, 10, 10); //faz esferas
    
    glutSwapBuffers();
}

void setup_lighting()
{  
	float mat_specular[] = {1.0f, 1.0f, 1.0f};
	float mat_shininess[] = {50.0f};
	float light_ambient[] = {0.1f, 0.1f, 0.1f};
	float light_position[] = {0.0f, 4.0f, 3.0f};
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int main(int argc, char** argv)
{
    // Inicializacao
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Sistema solar - Paloma");
	
    glutDisplayFunc(display);
	
	fov_y = 80.0f;
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Faz a definição do que pode ser visto no tam da tela
    gluPerspective(fov_y, 1.0f * WINDOW_WIDTH / WINDOW_HEIGHT, 0.001f, 1000.0f);
	
	
	glEnable(GL_DEPTH_TEST);
    
	setup_lighting();
    
	// Inicializando camera
	
	cam_z = 5.0f; 
	cam_y = 0.0f; 
		
    // Inicia o loop de eventos da GLUT
    glutMainLoop();
    
    return 0;
}