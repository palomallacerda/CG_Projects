#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 
#include <stdio.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

// // Angles around the earth
// static GLfloat velocidade;
// static float flag1 = 0.0f;
// static float flag2 = 0.0f;
// static GLfloat angle, fAspect;
// float cam_x, cam_y, cam_z;
// float center_x, center_y, center_z;

// //Função responsável pela chamada de gerenciamento do teclado
// void keyboeard_setting(unsigned char key, int x, int y){
//     switch (key){
// 		case 'X':
//         case 'x':
//             //Gira ao redor do eixo x
// 			glTranslatef (5, 0 , 0);
//             glRotatef(velocidade, 5,0,0);
//             angle = flag2;
//             break;
// 		case 'Y':
//         case 'y':
//             //Gira ao redor do eixo y
// 			glTranslatef (0 ,5, 0);
//             glRotatef(angle, 0,5, 0);
//             velocidade = flag1;
//             break;
// 		default:
// 			//fecha o sistema
// 			exit(0);
// 			break;
//     }

// 	// EspecificaParametrosVisualizacao();
//     glutPostRedisplay();
// }



// // Função usada para especificar o volume de visualização
// void EspecificaParametrosVisualizacao(){
// 	// Especifica sistema de coordenadas de projeção
// 	glMatrixMode(GL_PROJECTION);
// 	// Inicializa sistema de coordenadas de projeção
// 	glLoadIdentity();

// 	// Especifica a projeção perspectiva
// 	gluPerspective(angle,fAspect,0.1,600);

// 	// Especifica sistema de coordenadas do modelo
// 	glMatrixMode(GL_MODELVIEW);
// 	// Inicializa sistema de coordenadas do modelo
// 	glLoadIdentity();

// 	// Especifica posição do observador e do alvo
// 	gluLookAt(cam_x,cam_y,cam_z, center_x,center_y,center_z, 0,0,1);
// }

// // Função callback chamada para gerenciar eventos do mouse
// void GerenciaMouse(int button, int state, int x, int y){
// 	if (button == GLUT_LEFT_BUTTON)
// 		if (state == GLUT_DOWN) {  // Zoom-in
// 			if (angle >= 10) angle -= 5;
// 		}
// 	if (button == GLUT_RIGHT_BUTTON)
// 		if (state == GLUT_DOWN) {  // Zoom-out
// 			if (angle <= 130) angle += 5;
// 		}
// 	EspecificaParametrosVisualizacao();
// 	glutPostRedisplay();
// }

// void AlteraTamanhoJanela(GLsizei w, GLsizei h){
// 	// Para previnir uma divisão por zero
// 	if ( h == 0 ) h = 1;

// 	// Especifica o tamanho da viewport
// 	glViewport(0, 0, w, h);

// 	// Calcula a correção de aspecto
// 	fAspect = (GLfloat)w/(GLfloat)h;
// 	EspecificaParametrosVisualizacao();
// }

// // Called to draw scene
// void display(){
//     // Clear the window with current clearing color
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Reset the modelview matrix
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();

//     // Translate the whole scene out and into view
//     // This is the initial viewing transformation
//     glTranslatef(0.0f, 0.0f, -100.0f);

//     // Yellow sun
//     glColor3ub(255, 255, 0);
//     glutSolidSphere(7.0f, 15, 15);
    
//     // cor da terra
//     glColor3ub(0,0,255);
//     // Desenhando a terra
// 	glTranslatef(50.0f, 0.0f, -50.0f);
//     glutSolidSphere(6.0f, 15, 15);
    
//     // Save viewing transformation
//     glPushMatrix();
    
//     // Primeira lua 
//     // Rotate by angle of the moon
//     glRotatef(velocidade, 0.0f, 1.0f, 0.0f);
//     // Translate out from origin to orbit distance
//     glTranslatef(90.0f, 0.0f, 0.0f);

//     // Restore the viewing transformation
//     glPopMatrix();
    
//     // firt moon
//     glPushMatrix();
//     glRotatef(45.0f, 0.0f, 0.0f, 2.0f);
//     glRotatef(angle, 0.0f, 1.0f, 0.0f);
//     glTranslatef(-30.0f, 0.0f, 0.0f);
//     glColor3ub(192,192,192);
//     glutSolidSphere(3.0f, 7.5f, 7.5f);
//     glPopMatrix();

//     // Second Moon
//     glPushMatrix();
//     glRotatef(360.0f, -45.0f, 0.0f, 2.0f);
//     glRotatef(velocidade, 0.0f, 1.0f, 0.0f);
//     glTranslatef(0.0f, 0.0f, 30.0f);
//     glColor3ub(192,192,192);
//     glutSolidSphere(3.0f, 7.5f, 7.5f);
//     glPopMatrix();  
    
//     flag1 = velocidade;
//     flag2 = angle;
//     // 
//     angle +=10.0f;
//     velocidade += 10.0f;
//     if(angle > 360.0f) 
//         angle = 0.0f;

//     if(velocidade > 360.0f)
//         velocidade = 0.0f;

//     // Show the image
//     glutSwapBuffers();
// }
// void starting (void){ 
//     //definindo a cor e o angulo
//     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//     angle= 45;
//     velocidade = 0;
// 	cam_z = 0.0f;
// 	cam_y = 50.0f;
// 	cam_x = 0.0f;
// 	center_x = 0.0f; center_y = 0.0f; center_z = 0.0f;

// }

// Change viewing volume and viewport.
void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat fAspect;
    // Called when window is resized
    // Prevent a divide by zero
    if(h == 0)
        h = 1;
    // Set viewport to window dimensions
    glViewport(0, 0, w, h);
    // Calculate aspect ratio of the window
    fAspect = (GLfloat)w/(GLfloat)h;
    // Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Field of view of 45 degrees, near and far planes 1.0 and 425
    gluPerspective(45.0f, fAspect, 1.0, 425.0);
    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Called to draw scene
    void RenderScene(void){
    // Earth and moon angle of revolution
    static float fMoonRot = 0.0f;
    static float fEarthRot = 0.0f;
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Save the matrix state and do the rotations
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    // Translate the whole scene out and into view
    glTranslatef(0.0f, 0.0f, -300.0f);
    // Set material color, to yellow
    // Sun
    glColor3ub(255, 255, 0);

    glDisable(GL_LIGHTING);
    glutSolidSphere(15.0f, 15, 15);
    glEnable(GL_LIGHTING);
    // Position the light after we draw the Sun!
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    // Rotate coordinate system
    glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);
    // Draw the earth
    glColor3ub(0,0,255);
    glTranslatef(105.0f,0.0f,0.0f);
    glutSolidSphere(15.0f, 15, 15);
    // Rotate from Earth-based coordinates and draw moon
    glColor3ub(200,200,200);
    glRotatef(fMoonRot,0.0f, 1.0f, 0.0f);
    glTranslatef(30.0f, 0.0f, 0.0f);
    fMoonRot+= 15.0f;
    if(fMoonRot > 360.0f)
        fMoonRot = 0.0f;
    glutSolidSphere(6.0f, 15, 15);
    // Restore the matrix state
    glPopMatrix();
    // Modelview matrix
    // Step Earth orbit 5 degrees
    fEarthRot += 5.0f;
    if(fEarthRot > 360.0f)
        fEarthRot = 0.0f;
    // Show the image
    glutSwapBuffers();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);

	glutCreateWindow("Paloma - Solar_System");
    // starting();    
    // glutKeyboardFunc(keyboeard_setting);
    // glutMouseFunc(GerenciaMouse);
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    glutMainLoop();
    return 0;
}