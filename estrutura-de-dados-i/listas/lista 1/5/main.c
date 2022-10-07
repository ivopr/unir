/*
	estrutura de dados I
	lista 1 - ex 5
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		int ano, idade;
		
		// while true
		while(1) {
			printf("ano de nascimento - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("ano atual: ");
			scanf("%d", &ano);
			printf("idade: ");
			scanf("%d", &idade);
			
			// verifica o EOF e encerra se verdadeiro
			if(feof(stdin)) {
				break;
			}
			
			// exibe resultados
			printf("ano de nascimento: %d\n", ano - idade);
			
			// verifica o SO, pausa e limpa a tela.
			#ifdef __linux__
				system("read -p 'pressione enter para continuar.'");
				system("clear");
			#elif _WIN32
				system("pause");
				system("cls");
			#endif
		}
	}
