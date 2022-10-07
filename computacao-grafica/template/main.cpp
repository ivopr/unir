#include <GL/glut.h>
#include <cstdio>

/**
	Exec.: glc
*/

int timebase = 0;
int currenttime = 0;
int frame = 0;
int id;

GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1;

void display(void) {
	glMatrixMode(GL_MODELVIEW);

	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);

	// clear the identity matrix.
	glLoadIdentity();

	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(0.0, 0.0, -4.5);

	// Red color used to draw.
	glColor3f(1, 1, 1); 

	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 0.0, 0.0, 0.0);

	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);

	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 0.0);

	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);

	// built-in (glut library) function , draw you a Teapot.
	glutSolidTeapot(size);

	// Flush buffers to screen 
	glFlush();

	frame++;

	// get the current time
	currenttime = glutGet(GLUT_ELAPSED_TIME);

	// check if a second has passed
	if (currenttime - timebase > 1000) {
		double calc = frame * 1000.0 / (currenttime - timebase);
		printf("FPS: %4.2f\n", calc);
		timebase = currenttime;
		frame = 0;
	}

	// sawp buffers called because we are using double buffering 
	glutSwapBuffers();
}

void reshapeFunc(int x, int y) {
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return

	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Angle of view: 40 degrees
	// Near clipping plane distance: 0.5
	// Far clipping plane distance: 20.0
	gluPerspective(50.0, (GLdouble) x / (GLdouble) y, 0.5, 20.0);

	glViewport(0, 0, x, y);  // Use the whole window for rendering
}

void idleFunc(void) {
	yRotated += 0.05;
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

	xRotated = yRotated = zRotated = 30.0;

	glClearColor(0.0, 0.0, 0.0, 0.0);

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