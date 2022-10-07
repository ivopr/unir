/*
	estrutura de dados I
	lista 1 - ex 2
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		int num;
		
		// repetir até o usuário cansar.
		while(1) {
			printf("numero antecessor e sucessor.\npressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// é um scanf...
			printf("insira um numero inteiro: ");
			scanf("%d", &num);
			
			// verifica se o usuário optou pelo fim do programa (EOF), e o finaliza.
			if(feof(stdin)) {
				break;
			}
			
			// exibe o número antecessor e sucessor do número inserido pelo usuário.
			printf("antecessor: %d\ninserido: %d\nsucessor: %d\n", num - 1, num, num + 1);
			
			// verifica o sistema operacional e executa os comandos apropriados de pausa e limpeza.
			#ifdef __linux__
				system("read -p 'pressione enter para continuar.'");
				system("clear");
			#elif _WIN32
				system("pause");
				system("cls");
			#endif
		}
	}
