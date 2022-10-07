/*
	estrutura de dados I
	lista 1 - ex 8
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		int num, num1, aux;
		
		while(1) {
			printf("troca de valores - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("insira dois numeros inteiros: ");
			scanf("%d %d", &num, &num1);
			
			// verifica o eof e encerra o programa se necessário
			if(feof(stdin)) {
				break;
			}
			
			// exibe resultados
			printf("antes da troca\nA: %d\nB: %d\n", num, num1);
			aux = num;
			num = num1;
			num1 = aux;
			printf("depois da troca\nA: %d\nB: %d\n", num, num1);
			
			// verifica o SO, pausa e limpa
			#ifdef __linux__
				system("read -p 'pressione enter para continuar'");
				system("clear");
			#elif _WIN32
				system("pause");
				system("cls");
			#endif
		}
	}
