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
		
		// repetir at� o usu�rio cansar.
		while(1) {
			printf("numero antecessor e sucessor.\npressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// � um scanf...
			printf("insira um numero inteiro: ");
			scanf("%d", &num);
			
			// verifica se o usu�rio optou pelo fim do programa (EOF), e o finaliza.
			if(feof(stdin)) {
				break;
			}
			
			// exibe o n�mero antecessor e sucessor do n�mero inserido pelo usu�rio.
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
