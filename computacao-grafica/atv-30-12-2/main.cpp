#include <GL/freeglut.h>
#include <cmath>

const float PI = 3.141618;

/* angulos para as articulacoes */
float shoulderAngle = 0;
float elbowAngle = 0;
float handAngle = 0;
float finger1Angle = 0;
float finger2Angle = 0;
float finger3Angle = 0;

int flag = 1; // flag para selecionar o elemento a ser animado
int stop = 1; // flag para parar a animacao

/* para a camera, vale o mesmo do exercício anterior */
#define y_min 60
#define ro_min 120
float eyex = 0;
float eyey = y_min;
float eyez = ro_min;

void display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

// Draw Robot Arm
	glPushMatrix();
	glColor3f(0.1, 1, 0.1);
	glRotatef(shoulderAngle, 0, 0, 1);
	glTranslatef(0, 4, 0);
	glPushMatrix();
	glScalef(1, 8, 1);
	glutSolidCube(1);
	glPopMatrix();

	glTranslatef(0, 4, 0);

	glColor3f(0.1, 0.1, 1);
	glRotatef(elbowAngle, 0, 0, 1);
	glTranslatef(0, 3.5, 0);
	glPushMatrix();
	glScalef(0.8, 7, 0.8);
	glutSolidCube(1);
	glPopMatrix();

	glTranslatef(0, 3.5, 0);

	glColor3f(1, 0.1, 0.1);
	glRotatef(handAngle, 0, 0, 1);
	glTranslatef(0, 0.75, 0);
	glPushMatrix();
	glScalef(1.0, 1.5, 0.6);
	glutSolidCube(1);
	glPopMatrix();

	glTranslatef(0, 0.75, 0);

	glPushMatrix();
	glRotatef(finger1Angle, 1, 0, 0);
	glTranslatef( -0.5, 0.75, 0 );
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(finger2Angle, 1, 0, 0);
	glTranslatef(0, 0.75, 0);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(finger3Angle, 1, 0, 0);
	glTranslatef(0.5, 0.75, 0);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void increment(int delta) {
	switch(flag) {
		case 1: shoulderAngle += delta; break;
		case 2: elbowAngle += delta; break;
		case 3: handAngle += delta; break;
		case 4: finger1Angle += delta; break;
		case 5: finger2Angle += delta; break;
		case 6: finger3Angle += delta; break;
	}
	glutPostRedisplay();
}

void key(unsigned char k, int x, int y) {
	switch(k) {
		case '1': flag = 1; break;
		case '2': flag = 2; break;
		case '3': flag = 3; break;
		case '4': flag = 4; break;
		case '5': flag = 5; break;
		case '6': flag = 6; break;
		case ' ': stop = 1-stop; break;
	}

}

void specialkey(int k, int x, int y) {
	switch(k) {
		case GLUT_KEY_RIGHT: increment(5); break;
		case GLUT_KEY_LEFT: increment(-5); break;
	}
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height); // Reset The Current Viewport

	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (float)640/(float)480, 0.1f, 1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window

	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (float)640/(float)480, 0.1f, 1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window

	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

void TimerCamera(int value) {
	float ro;

	if(stop) {
		value++;

		if(value == 720) value = 0;

		ro = ro_min - sin(value/2.0 * PI/360) * ro_min * 0.8;
		eyey = y_min - sin(value/2.0 * PI/360) * y_min * 0.8;
		eyex = ro * sin(value/2.0 * PI/180);
		eyez = ro * cos(value/2.0 * PI/180);

		glutPostRedisplay();
	}
	glutTimerFunc(33, TimerCamera, value);
}

int main(int argc, char **argv) {
	//Initialize GLUT
	glutInit(&argc, argv);

	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// window size
	glutInitWindowSize(768, 512);

	glutInitWindowPosition(
		(glutGet(GLUT_SCREEN_WIDTH) - 768) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 512) / 2
	);

	// create the window
	glutCreateWindow("Mão Muito Braba");

	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Assign the functions used in events
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	TimerCamera(50);

	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading

	glutKeyboardFunc(key);
	glutSpecialFunc(specialkey);

	// Let start glut loop
	glutMainLoop();

	return 0;
}
