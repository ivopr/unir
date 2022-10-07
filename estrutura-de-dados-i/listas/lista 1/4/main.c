/*
	estrutura de dados I
	lista 1 - ex 4
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		int num, num1;
		
		// while true para repetir eternamente...
		while(1) {
			printf("divisao - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("insira dois numeros inteiros: ");
			scanf("%d %d", &num, &num1);
			
			// verifica se alguem apertou as teclas de saida e sai caso seja verdade
			if(feof(stdin)) {
				break;
			}
			
			// exibe os resultados
			printf("resultados\ninteiro: %d\ndecimal: %.2lf\n", num / num1, (double) num / num1);
			
			// verifica o SO e executa a pausa e limpeza
			#ifdef __linux__
				system("read -p 'pressione enter para continuas'");
				system("clear");
			#elif _WIN32
				system("pause");
				system("cls");
			#endif
		}
	}
