/*
	estrutura de dados I
	lista 1 - ex 3
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		int num, num1;
		
		while(1) {
			printf("resto e quociente da divisao de dois inteiros.\npressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("insira dois numeros inteiros: ");
			scanf("%d %d", &num, &num1);
			
			// verifica se o usuário decidiu finalizar.
			if(feof(stdin)) {
				break;
			}
			
			// exibe os resultados
			printf("quociente: %d\nresto: %d\n", num / num1, num % num1);
			
			// verifica o SO e executa a pausa e limpeza.
			#ifdef __linux__
				system("read -p 'pressione enter para continuar.'");
				system("clear");
			#elif _WIN32
				system("pause");
				system("cls");
			#endif
		}
	}
