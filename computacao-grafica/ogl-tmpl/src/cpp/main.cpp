/* main.cpp
 * Programa simples que apresenta o desenho de um quadrado
 * Objetivo : Demonstrar funções de gerenciamento de
 * janelas e funções de callback
 * Referência do Código: OpenGL Programming Guide - RedBook
 */

// **********************************************************************
//		
//		Este programa foi criado a partir de um fonte obtido em 
//	    http://nehe.gamedev.net, na "Lesson 06"
//
// **********************************************************************

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "tga_load.h"

// Qtd máxima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 1

#define CUBE_TEXTURE 0

// vetor com os números das texturas
GLuint texture_id[MAX_NO_TEXTURES];

int xrot;
int yrot;
int zrot;
float ratio;
int bot, rotX_ini, rotY_ini, x_ini, y_ini;


// **********************************************************************
//  void initTexture(void)
//		Define a textura a ser usada 
// **********************************************************************
void initTexture() {
    // Habilita o uso de textura
    glEnable(GL_TEXTURE_2D);

    // Define a forma de armazenamento dos pixels na textura (1 = alihamento por byte)
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Define quantas texturas serão usadas no programa
    glGenTextures(MAX_NO_TEXTURES, texture_id);  // 1 = uma textura;
    // texture_id = vetor que guardas os números das texturas

    // Define o número da textura do cubo.
    texture_id[CUBE_TEXTURE] = 1001;

    // Define que tipo de textura será usada
    // GL_TEXTURE_2D ==> define que será usada uma textura 2D (bitmaps)
    // texture_id[CUBE_TEXTURE]  ==> define o número da textura
    glBindTexture(GL_TEXTURE_2D, texture_id[CUBE_TEXTURE]);

    // carrega a uma imagem TGA
    image_t temp_image;
    char *texture = "unir.tga";
    tgaLoad(texture, &temp_image, TGA_FREE | TGA_LOW_QUALITY);
}

// **********************************************************************
//  void init(void)
//		Inicializa os parâmetros globais de OpenGL
// **********************************************************************
void init() {
    glShadeModel(GL_SMOOTH);                            // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);                // Black Background
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_CULL_FACE);
}

// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape(int w, int h) {
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0) {
        h = 1;
    }

    ratio =  float(w) / float(h);
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the clipping volume
    gluPerspective(80, ratio, 1, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 30,
              0, 0, 10,
              0.0f, 1.0f, 0.0f);
}

// **********************************************************************
//  void display( void )
// **********************************************************************
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(GLfloat(xrot), 1.0, 0.0, 0.0);
    glRotatef(GLfloat(yrot), 0.0, 1.0, 0.0);
    glRotatef(GLfloat(zrot), 0.0, 0.0, 1.0);

    // define qual das texturas usar
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);

    glBegin(GL_QUADS);
    // Front Face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // Back Face
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Top Face
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    // Bottom Face
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    // Right face
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Left Face
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    glPopMatrix();
//	xrot+=0.3f;
//	yrot+=0.2f;
//	zrot+=0.4f;
    glutSwapBuffers();
//   glFlush();
}


void GerenciaMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        // Salva os par�metros atuais
        x_ini = x;
        y_ini = y;
        rotX_ini = xrot;
        rotY_ini = yrot;
        bot = button;
    } else bot = -1;
}

// Fun��o callback para eventos de movimento do mouse
#define SENS_ROT        5.0

void GerenciaMovim(int x, int y) {
    // Bot�o esquerdo ?
    if (bot == GLUT_LEFT_BUTTON) {
        // Calcula diferen�as
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        // E modifica �ngulos
        yrot = rotY_ini - deltax / SENS_ROT;
        xrot = rotX_ini - deltay / SENS_ROT;
    }
    glutPostRedisplay();
}

// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
// **********************************************************************
void keyboard(unsigned char key, int, int) {
    if (key == 27) {
        exit(0);
    }
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
// **********************************************************************
void arrow_keys(int a_keys, int, int) {
    switch (a_keys) {
        case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
            glutFullScreen(); // Go Into Full Screen Mode
            break;
        case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
            glutInitWindowSize(700, 500);
            break;
        default:
            break;
    }
}

// **********************************************************************
//  void main ( int argc, char** argv )
//
//
// **********************************************************************
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 500) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 500) / 2);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Computação Grafica - Teste com Texturas.");

    init();
    initTexture();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // Registra a fun��o callback para eventos de bot�es do mouse
    glutMouseFunc(GerenciaMouse);

    // Registra a fun��o callback para eventos de movimento do mouse
    glutMotionFunc(GerenciaMovim);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow_keys);
    //glutIdleFunc(display);
    glutMainLoop();
}