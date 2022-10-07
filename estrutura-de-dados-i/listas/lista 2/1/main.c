/*
	estrutura de dados I
	lista 2 - ex 1
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	int main()
	{
		char caractere;
		
		// while true
		while(1)
		{
			limpar();
			printf("caractere de pontuacao - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
		
			// entrada de dados			
			printf("insira um caractere: ");
			scanf("%c", &caractere);
		
			// verifica o eof e finaliza o programa se necess�rio
			if(feof(stdin))
				break;
			
			// exibe resultado
			if(caractere == '.' || caractere == ',' || caractere == ';' || caractere == '!' || caractere == '?')
				printf("caractere de pontuacao.\n");
			else
				printf("nao eh caractere de pontuacao.\n");
			parar();
		}
	}
