/*
	estrutura de dados I
	lista 2 - ex 2
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	int main()
	{
		int ax, bx, cx, delta;
		double x1, x2;
		
		// while true
		while(1)
		{
			limpar();
			printf("equacao do segundo grau - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("entre com Ax, Bx e Cx respectivamente: ");
			scanf("%d %d %d", &ax, &bx, &cx);
			
			// verifica eof, caso encontre, encerra o programa
			if(feof(stdin))
				break;
			
			// exibe resultados
			// calcula delta
			delta = pow(bx, 2) - 4 * (ax * cx);
			
			// verifica o valor do delta e executa a opera��o correta
			if(delta > 0)
			{
				x1 = (-bx + sqrt(delta)) / (2 * ax);
				x2 = (-bx - sqrt(delta)) / (2 * ax);
				printf("x1: %.2lf\nx2: %.2lf\n", x1, x2);
			}
			else if(delta == 0)
			{
				x1 = (-bx + sqrt(delta)) / (2 * ax);
				printf("x: %2.lf\n", x1);
			}
			else
			{
				printf("delta negativo, nao ha raiz real.\n");
			}
			
		parar();
		}
	}
