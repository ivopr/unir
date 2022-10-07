#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

int id;

struct screenPt {
	GLint x;
	GLint y;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(screenPt pt1, screenPt pt2) {
	glBegin(GL_LINES);
	glVertex2i(pt1.x, pt1.y);
	glVertex2i(pt2.x, pt2.y);
	glEnd();
}

void drawCurve() {
	const GLdouble twoPi = 6.283185;
	const GLint a = 175, b = 60;

	GLfloat r, theta, dtheta = 1.0 / float (a);
	GLint x0 = 200, y0 = 250;
	screenPt curvePt[2];

	glColor3f(0.0, 0.0, 0.0);

	curvePt[0].x = x0;
	curvePt[0].y = y0;
	curvePt[0].x += a;

	theta = dtheta;
	while(theta < twoPi) {
		r = a * cos(3 * theta);
		curvePt[1].x = x0 + r * cos(theta);
		curvePt[1].y = y0 + r * sin(theta);
		lineSegment(curvePt[0], curvePt[1]);
		curvePt[0].x = curvePt[1].x;
		curvePt[0].y = curvePt[1].y;
		theta += dtheta;
	}
}

void display() {
	glClear (GL_COLOR_BUFFER_BIT); // Clear display window.

	drawCurve();

	// Flush buffers to screen 
	glFlush();
}

void reshapeFunc(GLint newWidth, GLint newHeight) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

void keyboardFunc(unsigned char key, int, int) {
	if (key == 27) {
		glutDestroyWindow(id);
		exit(0);
	}
}

int main(int argc, char **argv) {
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(
		(glutGet(GLUT_SCREEN_WIDTH) - 600) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 500) / 2
	);
	glutInitWindowSize(600, 500);
	id = glutCreateWindow("Draw Curves");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc);
	glutReshapeFunc(reshapeFunc);
	glutMainLoop();

	return 0;
}