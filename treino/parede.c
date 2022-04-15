#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 550
#define WINDOW_HEIGHT 480

typedef struct pontos
{
    float x,y,z; // para os vertices
    float r, g, b; //para as cores
}pontos;


//controle de camera
float fov_y;
float cam_x, cam_y, cam_z;
float center_x, center_y, center_z;

//posicão da parede
float parede_x, parede_y, parede_z;
float wall_rotation;
float wall_width, wall_heigth, wall_thick;

//renderizando

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Seleciona a matriz ModelView e reseta todas as transformacoes   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   
    // Define a matriz View
    gluLookAt(cam_x, cam_y, cam_z, center_x, center_y, center_z, 0.0f, 1.0f, 0.0f);
   
    // Define a matriz Model
    /*
    * Lembre-se, a ordem das transformacoes importa - escala, 
    * depois as rotacoes e translacao
    */
	glTranslatef(parede_x, parede_y, parede_z);
	glRotatef(wall_rotation, 0.0f, 1.0f, 0.0f); // rotacao em torno do eixo y
    // como o cubo tem lado 1 podemos escalar ele para as dimensoes desejadas
	glScalef(wall_width, wall_heigth, wall_thick); 
	
	/*
	Desenha o cubo de lado 1 com todas as transformacoes acima
	aplicadas.
	A origem do cubo eh no centro, entao lembre de colocar
	altura/2 na coordenada y da posicao para ficar
	perfeitamente no chao
	*/
	glutSolidCube(0.7f);
   
	glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("PAREDE");


    glutDisplayFunc(display);

    fov_y = 75.0f;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov_y, 1.0f *WINDOW_WIDTH / WINDOW_HEIGHT, 0.001f, 1000.0f);

    // Inicializando camera e parede
	cam_z = 5.0f; // 5m atrás da parede
	cam_y = 1.7f; // altura de uma pessoa 
	wall_heigth = 3.0f; // 3m
	wall_thick = 0.3f; // 30cm
	wall_width = 4.0f; // 4m
	wall_rotation = 45.0f; 
	parede_x = 0.0f;
	parede_y = 1.5f; // metade da altura
	parede_z = 0.0f;

    // representando o centro que estaremos olhando 
    center_x = parede_x;
    center_y = parede_y;
    center_z = parede_z;

    glutMainLoop();
    return 0;
}