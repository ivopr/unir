/*
	estrutura de dados I
	lista 2 - ex 6
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	int main()
	{
		int rnum, num, cont = 0;
		
		// while true
		while(1)
		{
			limpar();
			printf("adivinhar numero - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");

			// gera um n�mero aleat�rio.
			srand(time(NULL));
			rnum = rand() % 100;
			
			// enquanto o usu�rio n�o acertar a resposta...
			while(num != rnum)
			{
				printf("qual o numero aleatorio? ");
				scanf("%d", &num);
				
				// verifica eof e encerra o loop
				if(feof(stdin))
					break;
				
				// compara o n�mero inserido com o n�mero randomico, se for igual, o programa abandona esse la�o
				if(num == rnum)
					break;
				else if(num > rnum)
					printf("o numero %d eh maior que o sorteado.\n", num);
				else
					printf("o numero %d eh menor que o sorteado.\n", num);

				cont++;
			}
			
			// verifica o eof novamente para sair do programa, e n�o s� do loop
			if(feof(stdin))
				break;
				
			// exibe as mensagens de acerto.
			printf("parabens, o numero aleatorio era %d.\n", rnum);
			printf("voce precisou de %d chute(s) para acertar.\n", cont);
			
			// zera o contador
			cont = 0;
			
			parar();
		}
	}
