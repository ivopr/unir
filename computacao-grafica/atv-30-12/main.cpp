#include <GL/freeglut.h>
#include <iostream>

/* angulos de rotacao para os corpos celestes */
float angleMercury = 0;
float angleVenus = 0;
float angleEarth = 0;
float angleMoon = 0;
float angleMars = 0;
float angleJupiter = 0;
float angleJupiterMoonEuropa = 0;
float angleJupiterMoonGanymede = 0;
float angleJupiterMoonIo = 0;
float angleJupiterMoonCallisto = 0;
float angleSaturn = 0;
float angleUranus = 0;
float angleNeptune = 0;

/* para a camera, lembrem-se dos exercicios anteriores */
#define ro_min 120
float eyex = 200;
float eyey = 200;
float eyez = ro_min;

void drawSun() {
	glColor3f(1, 1, 0);
	glutSolidSphere(12, 16, 16);
}

void drawMercury() {
	glColor3f(0.3, 0.3, 0.3);
	glutSolidSphere(2, 16, 16);
}

void drawVenus() {
	glColor3f(1, 0.5, 0.1);
	glutSolidSphere(3, 16, 16);
}

void drawEarth() {
	glColor3f(0, 0, 1);
	glutSolidSphere(5, 16, 16);
}

void drawMoon() {
	glColor3f(0.5, 0.5, 0.5);
	glutSolidSphere(1, 16, 16);
}

void drawMars() {
	glColor3f(0.58, 0.29, 0);
	glutSolidSphere(2, 16, 16);
}

void drawJupiter(){
	glColor3f(1, 0.27, 0.27);
	glutSolidSphere(15, 16, 16);
}

void drawJupiterMoonEuropa(){
	glColor3f(1, 0.8, 0.7);
	glutSolidSphere(2, 16, 16);
}

void drawJupiterMoonGanymede(){
	glColor3f(0.8, 0.8, 0.8);
	glutSolidSphere(2, 16, 16);
}

void drawJupiterMoonIo(){
	glColor3f(0.9, 0.9, 0.5);
	glutSolidSphere(2, 16, 16);
}

void drawJupiterMoonCallisto(){
	glColor3f(0.4, 0.6, 0.4);
	glutSolidSphere(2, 16, 16);
}

void drawSaturn(){
	glColor3f(0.9, 0.8, 0.7);
	glutSolidSphere(12, 16, 16);
}

void drawUranus(){
	glColor3f(0.4, 0.8, 0.9);
	glutSolidSphere(10, 16, 16);
}

void drawNeptune(){
	glColor3f(0.2, 0.3, 0.9);
	glutSolidSphere(8, 16, 16);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

	// Draw planetary system
	// Deaw Sun
	glPushMatrix();
	drawSun();

	// Draw Mercury
	glPushMatrix();
	glRotatef(angleMercury, 0, 1, 0);
	glTranslatef(15, 0, 0);
	drawMercury();

	// Then go back to Sun
	glPopMatrix();

	// Draw Venus
	glPushMatrix();
	glRotatef(angleVenus, 0, 1, 0);
	glTranslatef(22.5, 0, 0);
	drawVenus();

	// Then go back to Sun
	glPopMatrix();

	// Draw Earth
	glPushMatrix();
	glRotatef(angleEarth, 0, 1, 0);
	glTranslatef(35, 0, 0);
	drawEarth();

	// In Earth, Draw Moon
	glPushMatrix();
	glRotatef(angleMoon, 0, 1, 0);
	glTranslatef(7, 0, 0);
	drawMoon();

	// Then go back to Earth, then Sun
	glPopMatrix();
	glPopMatrix();

	// Draw Mars
	glPushMatrix();
	glRotatef(angleMars, 0, 1, 0);
	glTranslatef(50, 0, 0);
	drawMars();

	// Then go back to Sun
	glPopMatrix();

	// Draw Jupiter
	glPushMatrix();
	glRotatef(angleJupiter, 0, 1, 0);
	glTranslatef(65, 0, 0);
	drawJupiter();

	// In Jupiter, Draw Europa
	glPushMatrix();
	glRotatef(angleJupiterMoonEuropa, 0, 1, 0);
	glTranslatef(18, 0, 0);
	drawJupiterMoonEuropa();

	// Then go back to Jupiter
	glPopMatrix();

	// In Jupiter, Draw Ganymede
	glPushMatrix();
	glRotatef(angleJupiterMoonGanymede, 0, 1, 0);
	glTranslatef(18, 5, 0);
	drawJupiterMoonGanymede();

	// Then go back to Jupiter
	glPopMatrix();

	// In Jupiter, Draw Io
	glPushMatrix();
	glRotatef(angleJupiterMoonIo, 0, 1, 0);
	glTranslatef(18, -5, 0);
	drawJupiterMoonIo();

	// Then go back to Jupiter
	glPopMatrix();

	// In Jupiter, Draw Callisto
	glPushMatrix();
	glRotatef(angleJupiterMoonCallisto, 0, 1, 0);
	glTranslatef(18, 10, 0);
	drawJupiterMoonCallisto();

	// Then go back to Jupiter, then to Sun
	glPopMatrix();
	glPopMatrix();

	// Draw Saturn
	glPushMatrix();
	glRotatef(angleSaturn, 0, 1, 0);
	glTranslatef(80, 0, 0);
	drawSaturn();

	// Then go back to Sun
	glPopMatrix();

	// Draw Uranus
	glPushMatrix();
	glRotatef(angleUranus, 0, 1, 0);
	glTranslatef(95, 0, 0);
	drawUranus();

	// Then go back to Sun
	glPopMatrix();

	// Draw Neptune
	glPushMatrix();
	glRotatef(angleNeptune, 0, 1, 0);
	glTranslatef(110, 0, 0);
	drawNeptune();

	// Then go back to Sun
	glPopMatrix();

	glutSwapBuffers();
}

void TimerFunction(int value) {
	angleMercury += 8;
	if(angleMercury >= 360) angleMercury = 0;

	angleVenus += 7;
	if(angleVenus >= 360) angleVenus = 0;

	angleEarth += 6;
	if(angleEarth >= 360) angleEarth = 0;

	angleMoon += 7;
	if(angleMoon >= 360) angleMoon = 0;

	angleMars += 5;
	if(angleMars >= 360) angleMars = 0;

	angleJupiter += 4;
	if(angleJupiter >= 360) angleJupiter = 0;

	angleJupiterMoonEuropa += 4;
	if(angleJupiterMoonEuropa >= 360) angleJupiterMoonEuropa = 0;

	angleJupiterMoonGanymede += 3;
	if(angleJupiterMoonGanymede >= 360) angleJupiterMoonGanymede = 0;

	angleJupiterMoonIo += 5;
	if(angleJupiterMoonIo >= 360) angleJupiterMoonIo = 0;

	angleJupiterMoonCallisto += 2;
	if(angleJupiterMoonCallisto >= 360) angleJupiterMoonCallisto = 0;

	angleSaturn += 3;
	if(angleSaturn >= 360) angleSaturn = 0;

	angleUranus += 2;
	if(angleUranus >= 360) angleUranus = 0;

	angleNeptune += 1;
	if(angleNeptune >= 360) angleNeptune = 0;

	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
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
	glutCreateWindow("Sistema Solar Muito Brabo");

	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Assign the functions used in events
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading

	// Setup idle function
	TimerFunction(33);

	// Let start glut loop
	glutMainLoop();

	return 0;
}
