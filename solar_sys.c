#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define x_position 1100
#define y_position 10

// Variaveis para controlar a camera
float fov_y;
float cam_x, cam_y, cam_z;
float center_x, center_y, center_z;

typedef struct coords
{
    float x, y, z;
}coords;

//Angulo de rotação em torno do sol
static GLfloat fElect1 = 50.0f;
static GLfloat fElect2 = 360.0f;
static GLfloat fElect3 = 0.0f;
static GLfloat fElect4 = 45.0f;
static coords example;
static coords moon;
static coords moon2;

void keyboard_planet(unsigned char key, int x, int y){
    if(key == 'z' || key == 'Z'){
        example.x = 0.0f; 
        example.y = 1.0f;
        example.z = 0.0f;
          // Increment the angle of revolution
        fElect1 += 1.0f;
        if(fElect1 > 360.0f)
            fElect1 = 0.0f;

        // Increment the angle of revolution
        fElect2 -= 1.0f;
        if(fElect2 == 0)
            fElect2 = 360.0f;
        // exit(0);
    }
    else if(key == 'x'|| key == 'X'){
        moon.x = 0; 
        moon.y = 1;
        moon.z = 0;
        fElect3 += 10.0f;
        if(fElect3 > 360.0f)
            fElect3 = 0.0f;

        // ###################################
        moon2.x = 0;
        moon2.y = 1;
        moon2.z = 1;

        fElect4 +=5.0f;
        if(fElect4 > 360.0f)
            fElect4 = 0.0f;
    }
    else if(key =='y' || key == 'Y'){
        example.x = 0.0f; 
        example.y = 1.0f;
        example.z = 0.0f;
          // Increment the angle of revolution
        fElect1 += 1.0f;
        if(fElect1 > 360.0f)
            fElect1 = 0.0f;

        // Increment the angle of revolution
        fElect2 -= 1.0f;
        if(fElect2 == 0)
            fElect2 = 360.0f;

        moon.x = 0; 
        moon.y = 1;
        moon.z = 0;
        fElect3 += 5.0f;
        if(fElect3 > 360.0f)
            fElect3 = 0.0f;

        // ###################################
        moon2.x = 0;
        moon2.y = 1;
        moon2.z = 1;

        fElect4 +=5.0f;
        if(fElect4 > 360.0f)
            fElect4 = 0.0f;
        
    }

    //Atualiza a janela
    glutPostRedisplay();
}


void planet2(){
    // glPushMatri/x();
    // Second planet
    glColor3ub(255,0,0);

    //Fazendo a rotação com o angulo setado no eixo y
    glRotatef(fElect2, example.x, example.y, example.z);

    //translada da origem até -90x
    glTranslatef(-90.0f, 0.0f, 0.0f);

    glutSolidSphere(3.0f, 15.5f, 15.5f);

    //Drawing moons
    glPushMatrix();
    glColor3ub(255,244,255);
    //"Translation"
	glRotatef(fElect3, moon.x, moon.y, moon.z);
	
	glTranslatef(20.0f, 0.0f, 1.0f);
	
	glutSolidSphere(1, 200, 200);

    glPopMatrix();
    

    //Second moon
    glPushMatrix();
    glColor3ub(192,192,192);

    //"Translation"
	glRotatef(fElect4, moon2.x, moon2.y, moon2.z);
	
	glTranslatef(10.0f, 0.0f, 0.0f);
	
	glutSolidSphere(1, 200, 200);

    glPopMatrix();

}
void planet1(){

    //Salvando o estado 
    glPushMatrix();

    glColor3ub(0,0,255);

    //Fazendo a rotação com o angulo setado no eixo y
    glRotatef(fElect1, example.x, example.y, example.z);

    //translada da origem até +90x
    glTranslatef(90.0f, 0.0f, 0.0f);
    glutSolidSphere(3.0f, 15.5f, 15.5f);
    //restaura o estado
    glPopMatrix();

}
void sun(){

    // Setando Translatação inicial
    glTranslatef(0.0f, 0.0f, -300.0f);
    // glRotatef(0, 0,40, 360);

    // Yellow sun
    glColor3ub(255, 255, 0);
    glutSolidSphere(7.0f, 30, 30);
    planet1();
    planet2();

}

//###############################################################
// Inicio
void display(){
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    // Resetando a matriz de transformações
    glLoadIdentity();

    //Definindo posicionamento da câmera
    gluLookAt(cam_x, cam_y, cam_z, center_x, center_y, center_z, 0.0f, 1.0f, 0.0f);
    
    sun();

    glutSwapBuffers();
}


//###############################################################
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutCreateWindow("Paloma - Solar_System");
    glutPositionWindow(x_position,y_position);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard_planet);

    // Angulo de observação 
    fov_y = 45.0f;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // angulo, tam de corte, near, far (respectivamente)
    gluPerspective(fov_y, 1.0f*WINDOW_WIDTH/WINDOW_HEIGHT, 0.1f, 1050.0f);
    glEnable(GL_DEPTH_TEST);

    cam_z = 5.0f;
    cam_y = 0.0f;
    glutMainLoop();
    return 0;
}

