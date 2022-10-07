#include <GL/glut.h>
#include <cstdio>

/**
	Exec.: glc
*/

int timebase = 0;
int currenttime = 0;
int frame = 0;
int id;

GLdouble size = 1;

void display(void) {
	glMatrixMode(GL_PROJECTION);

	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	// clear the identity matrix.
	glLoadIdentity();

	glBegin(GL_QUADS);
		// Direita
		glColor3f(1, 0, 0);
		glVertex3f(0.2,  0.0, 0);
		glVertex3f(0.5, -0.2, 0);
		glVertex3f(0.8,  0.0, 0);
		glVertex3f(0.5,  0.2, 0);

		// Esquerda
		glColor3f(1, 1, 0);
		glVertex3f(-0.2,  0.0, 0);
		glVertex3f(-0.5, -0.2, 0);
		glVertex3f(-0.8,  0.0, 0);
		glVertex3f(-0.5,  0.2, 0);

		// Baixo
		glColor3f(0, 0, 0);
		glVertex3f( 0.0, -0.2, 0);
		glVertex3f(-0.2, -0.5, 0);
		glVertex3f( 0.0, -0.8, 0);
		glVertex3f( 0.2, -0.5, 0);

		// Cima
		glColor3f(0, 0, 1);
		glVertex3f( 0.0, 0.2, 0);
		glVertex3f(-0.2, 0.5, 0);
		glVertex3f( 0.0, 0.8, 0);
		glVertex3f( 0.2, 0.5, 0);
	glEnd();

	frame++;

	// get the current time
	currenttime = glutGet(GLUT_ELAPSED_TIME);

	// check if a second has passed
	if (currenttime - timebase > 1000) {
		double calc = frame * 1000.0 / (currenttime - timebase);
		printf("FPS: %.2f\n", calc);
		timebase = currenttime;
		frame = 0;
	}

	// Flush buffers to screen 
	glFlush();

	// sawp buffers called because we are using double buffering 
	// glutSwapBuffers();
}

void reshapeFunc(int x, int y) {
	if (y == 0 || x == 0) return;  // Nothing is visible then, so return

	// Set a new projection matrix
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Angle of view: 40 degrees
	// Near clipping plane distance: 0.5
	// Far clipping plane distance: 20.0
	gluPerspective(50.0, (GLdouble) x / (GLdouble) y, 0.5, 20.0);

	glViewport(0, 0, x, y);  // Use the whole window for rendering
}

void idleFunc(void) {
	display();
}

void keyboardFunc(unsigned char key, int x, int y) {
	if (key == 27) {
		glutDestroyWindow(id);
		exit(0);
	}
}

int main(int argc, char **argv) {
	//Initialize GLUT
	glutInit(&argc, argv);

	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// window size
	glutInitWindowSize(300, 300);

	glutInitWindowPosition(
		(glutGet(GLUT_SCREEN_WIDTH) - 300) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 300) / 2
	);

	// create the window 
	id = glutCreateWindow("GLUT Teapot");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glClearColor(0, 1, 0, 0.3);

	// Assign the functions used in events
	glutDisplayFunc(display);

	// Setup reshape function
	glutReshapeFunc(reshapeFunc);

	// Setup idle function
	glutIdleFunc(idleFunc);

	// Setup keyboard interaction
	glutKeyboardFunc(keyboardFunc);

	// Let start glut loop
	glutMainLoop();

	return 0;
}