/* Template
* Programa que apresenta as transformações aplicadas a uma primitiva
* Objetivo : Demonstrar a utilização de transformação de objetos
* Referência do Código: OpenGL Programming Guide - RedBook
*/
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat escala;
GLfloat translada;
GLfloat rotaciona;

void display(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Limpa o Buffer de Pixels */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Estabelece a cor da primitiva */
	glColor3f(1.0f, 0.0f, 1.0f);

	/* Efetua a operação de translação */


	/* Efetua a operação de escala em Y */


	/* Efetua a operação de rotação em Z */


	/* desenha um simples retângulo ou outro objeto*/
	glutSolidTeapot(1);

	/* Inicia o processo de desenho através dos
	dados bufferizados
	*/
	glFlush();
}

void init(void) {
	/* Seleciona a cor de fundo para limpeza da tela */
	glClearColor(1.0, 1.0, 1.0, 1.0);

	/* inicializa os valores de visualização */
	glMatrixMode(GL_PROJECTION);

	/* Faz com que a matriz corrente seja inicializada com a matriz identidade
	(nenhuma transformação é acumulada)
	*/
	glLoadIdentity();
	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
Função responsável pelo controle do teclado. Dependendo da tecla pressionada :
R,S,T, irá efetuar respectivamente as operações de
Rotação, Escala e Translação
*/
void teclado(unsigned char tecla, int x, int y) {
	switch (tecla) {
		case 'S':
		case 's':// Incrementa o valor do parâmetro de escala

		break;
		case 'T':
		case 't':// Incrementa o valor do parâmetro de translacao

		break;
		case 'R':
		case 'r':// Incrementa o valor do ângulo de rotação

		break;
		case 'O':
		case 'o': // Volta na imagem inicial

		break;
	}

	glutPostRedisplay();
}

/*
Funcão principal do programa.
*/
int main(int argc, char** argv) {
	glutInit (&argc, argv);
	/*
	Estabelece o modo de exibição a ser utilizado pela janela a ser
	neste caso utiliza-se de um buffer simples, ou seja, a apresentação
	execução
	Define o modo de cores como RGBA
	*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	/*
	Determina o tamanho em pixels da
	janela a ser criada
	*/
	glutInitWindowSize(400, 400);

	/*
	Estabelece a posição inicial para criação da
	janela
	*/
	glutInitWindowPosition(
		(glutGet(GLUT_SCREEN_WIDTH) - 400) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 400) / 2
	);

	/*
	Cria uma janela com base nos parâmetros especificados
	nas funções glutInitWindowSize e glutInitWindowPosition
	com o nome de título especificado em seu argumento
	*/
	glutCreateWindow("OpenGL TG");

	/*
	Habilita a captura dos eventos de teclado
	*/
	glutKeyboardFunc(teclado);

	/*
	Especifica os parâmetros inicias para as variáveis
	de estado do OpenGL
	*/
	init();

	// Associa a função display como uma função de callback
	glutDisplayFunc(display);

	/*
	Inicia a execução do programa OpenGL.
	O programa irá executar num loop infinito devendo
	o desenvolvedor especificar as condições de saída do mesmo
	através de interrupções no próprio programa ou através
	de comandos de mouse ou teclado como funções de callback
	*/
	glutMainLoop();
	return 0;
}
