/*
	estrutura de dados I
	lista 2 - ex 5
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	int main()
	{
		double altura, peso, media;
		
		// while true
		while(1)
		{
			limpar();
			printf("imc - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
		
			// entrada de dados			
			printf("insira o peso (ex. 50 | 50.5): ");
			scanf("%lf", &peso);
			printf("insira a altura (ex. 1.68): ");
			scanf("%lf", &altura);
		
			// verifica o eof e finaliza o programa se necessário
			if(feof(stdin))
				break;
			
			// exibe resultado
			media = peso / (altura * altura);
			if(media <= 18.5)
				printf("imc: %.2lf\nabaixo do peso.\n", media);
			else if(media <= 25.0)
				printf("imc: %.2lf\nsaudavel.\n", media);
			else if(media <= 30.0)
				printf("imc: %.2lf\npeso em excesso.\n", media);
			else if(media <= 35.0)
				printf("imc: %.2lf\nobesidade grau 1.\n", media);
			else if(media <= 40.0)
				printf("imc: %.2lf\nobesidade grau 2 (severa).\n", media);
			else
				printf("imc: %.2lf\nobesidade grau 3 (morbida).\n", media);
			
			parar();
		}
	}
