/*
	estrutura de dados I
	lista 2 - ex 4
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	int main()
	{
		double nota, nota1, peso, peso1, media;
		
		// while true
		while(1)
		{
			limpar();
			printf("media ponderada - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
		
			// entrada de dados			
			printf("insira a nota 1: ");
			scanf("%lf", &nota);
			printf("insira a nota 2: ");
			scanf("%lf", &nota1);
			printf("insira o peso da nota 1: ");
			scanf("%lf", &peso);
			printf("insira o peso da nota 2: ");
			scanf("%lf", &peso1);
		
			// verifica o eof e finaliza o programa se necessário
			if(feof(stdin))
				break;
			
			// exibe resultado
			media = (nota * peso + nota1 * peso1) / (peso + peso1);
			if(media >= 6.0)
				printf("media: %.2lf\naluno aprovado.\n", media);
			else if(media >= 3.0)
				printf("media: %.2lf\naluno de recuperacao.\n", media);
			else
				printf("media: %.2lf\naluno reprovado.\n", media);
			
			parar();
		}
	}
