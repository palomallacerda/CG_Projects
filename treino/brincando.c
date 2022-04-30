#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

// Called to draw scene
void display(){
    // Angle of revolution around the nucleus
    GLfloat fElect1 = 0.0f;
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutWireSphere(50.0f, 25.0f, 20.0f);
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);

	glutCreateWindow("Meu ponto");
    
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}