/*
	estrutura de dados I
	lista 2 - ex 3
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <ed.h>

	int main()
	{
		int num;
		
		while(1)
		{
			limpar();
			printf("par ou impar? - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("insira um numero: ");
			scanf("%d", &num);
			
			// verifica eof e encerra o programa se necessário
			if(feof(stdin))
				break;
			
			// exibe resultados
			if(num % 2 == 0)
				printf("o numero %d eh par.\n", num);
			else
				printf("o numero %d eh impar.\n", num);
			
			parar();
		}
	}
