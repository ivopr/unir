/*
	estrutura de dados I
	lista 1 - ex 7
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	int main() {
		double l;
		
		// while true
		while(1) {
			printf("area do quadrado - pressione CTRL+D (linux) ou CTRL+z (windows) para sair.\n");
			
			// entrada de dados
			printf("tamanho do lado: ");
			scanf("%lf", &l);
			
			// verifica o eof e finaliza se necess�rio
			if(feof(stdin)) {
				break;
			}
			
			// exibe resultados
			printf("area: %.2lf\n", pow(l, 2));
			
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
