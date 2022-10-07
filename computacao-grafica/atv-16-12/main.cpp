#include <GL/freeglut.h>
#include <cstdio>

int timebase = 0;
int currenttime = 0;
int frame = 0;
int id;

GLfloat xRotated = 0.0, yRotated = 0.0, zRotated = 0.0;
GLfloat xScale = 0.5f, yScale = 0.5f, zScale = 0.5f;
GLfloat xTranslate = 0.0f, yTranslate = 0.0f;

const GLdouble size = 1;

void display() {
	glMatrixMode(GL_MODELVIEW);

	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);

	// clear the identity matrix.
	glLoadIdentity();

	// Red color used to draw.
	glColor3f(1.0f, 0.0f, 0.0f);

	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(xTranslate, yTranslate, -3.0f);

	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0f, 0.0f, 0.0f);

	// rotation about Y axis
	glRotatef(yRotated, 0.0f, 1.0f, 0.0f);

	// rotation about Z axis
	glRotatef(zRotated, 0.0f, 0.0f, 1.0f);

	// scaling transformation
	glScalef(xScale, yScale, zScale);

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

	// swap buffers called because we are using double buffering
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

void idleFunc() {
	yRotated += 0.05;
	display();
}

void keyboardFunc(unsigned char key, int x, int y) {
	if (key == 27) {
		glutDestroyWindow(id);
		exit(0);
	}

	switch(key) {
		// RETORNA O OBJETO AO ESTADO INICIAL
		case 'O':
		case 'o': {
			xRotated = yRotated = zRotated = 0.0;
			//xScale = yScale = zScale = 0.5f;
			//xTranslate = yTranslate = 0.0f;
			display();
			break;
		}
		// X, Y e Z adicionam 0.5º de ângulo, no eixo respectivo a tecla
		case 'X':
		case 'x': {
			xRotated += 0.5;
			display();
			break;
		}
		case 'Y':
		case 'y': {
			yRotated += 0.5;
			display();
			break;
		}
		case 'Z':
		case 'z': {
			zRotated += 0.5;
			display();
			break;
		}
		case 'M':
		case 'm': {
			// SE JÁ TIVER ANDADO MAIS QUE 2 CASAS, VOLTA PRA 0
			if (xTranslate > 2.0f) {
				xTranslate = 0.0f;
			// CASO CONTRÁRIO, ANDA ELE EM 1 DÉCIMO DE CASA
			} else {
				xTranslate += 0.1f;
			}
			display();
			break;
		}
		case 'N':
		case 'n': {
			// SE JÁ TIVER ANDADO MAIS QUE 2 CASAS, VOLTA PRA 0
			if (xTranslate < -2.0f) {
				xTranslate = 0.0f;
			// CASO CONTRÁRIO, ANDA ELE EM 1 DÉCIMO DE CASA
			} else {
				xTranslate -= 0.1f;
			}
			display();
			break;
		}
		case 'V':
		case 'v': {
			// SE JÁ TIVER ANDADO MAIS QUE 2 CASAS, VOLTA PRA 0
			if (yTranslate < -2.0f) {
				yTranslate = 0.0f;
			// CASO CONTRÁRIO, ANDA ELE EM 1 DÉCIMO DE CASA
			} else {
				yTranslate -= 0.1f;
			}
			display();
			break;
		}
		case 'B':
		case 'b': {
			// SE JÁ TIVER ANDADO MAIS QUE 2 CASAS, VOLTA PRA 0
			if (yTranslate > 2.0f) {
				yTranslate = 0.0f;
			// CASO CONTRÁRIO, ANDA ELE EM 1 DÉCIMO DE CASA
			} else {
				yTranslate += 0.1f;
			}
			display();
			break;
		}
		default: {
			printf("Acao nao reconhecida");
		}
	}
}

void mouseFunc(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		// BOTÃO ESQUERDO ESCALA X
		if (button == GLUT_LEFT_BUTTON) {
			if (xScale > 2.0f) {
				xScale = 0.5f;
			} else {
				xScale += 0.1;
			}
			display();
		}
		// SE NÃO FOR O BOTÃO ESQUERDO, E FOR O DIREITO, ESCALA Y
		else if (button == GLUT_RIGHT_BUTTON) {
			if (yScale > 2.0f) {
				yScale = 0.5f;
			} else {
				yScale += 0.1;
			}
			display();
		}
		// SE NÃO FOR NENHUM DOS DOIS, ESCALA Z, PQ É O BOTÃO DO MEIO
		else {
			if (zScale > 2.0f) {
				zScale = 0.5f;
			} else {
				zScale += 0.1;
			}
			display();
		}
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
	id = glutCreateWindow("Pote Muito Brabo");

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

	// Setup mouse interaction
	glutMouseFunc(mouseFunc);

	// Let start glut loop
	glutMainLoop();

	return 0;
}