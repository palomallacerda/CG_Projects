
#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 550
#define WINDOW_HEIGHT 480

typedef struct Vertex
{
	float x, y, z;
	float r, g, b;
} Vertex;

Vertex vertices[] = {
	{-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f}, // vermelho
	{ 0.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f}, // verde
	{ 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f}, // azul
};

// float vertices[] = {
// 	-0.5f, -0.5f, 0.0f,
// 	0.0f, 0.5f, 0.0f,
// 	0.5f, -0.5f, 0.0f
// };

void display(){
    int i;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	Vertex v;
	


	for(i = 0;i < sizeof(vertices);i++)
	{
		v = vertices[i];
		glColor3f(v.r, v.g, v.b);
		glVertex3f(v.x, v.y, v.z);
	}
	// for(i = 0;i < sizeof(vertices) / sizeof(float);i += 3)
	// {
	// 	glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
	// }
	glEnd();

	//perguntar o swapBuffers
	glutSwapBuffers();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(WINDOW_WIDTH , WINDOW_HEIGHT);
	
    glutCreateWindow("My first Triangle");

    glutDisplayFunc(display);
    glutMainLoop();
    return 0; 
}
