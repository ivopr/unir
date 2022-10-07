/*
	estrutura de dados I
	lista 1 - ex 9
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		double g1, g2, g3;
		
		printf("divisao de premio - ao pressionar enter o programa se encerrara\n");
		
		// calcula e armazena quanto cada ganhador irá receber
		g1 = 780.000 * 0.46;
		g2 = 780.000 * 0.32;
		g3 = 780.000 - (g1 + g2);
		
		// exibe os resultados
		printf("primeiro: R$ %.3lf,00\nsegundo: R$ %.3lf,00\nterceiro: R$ %.3lf,00\n", g1, g2, g3);
		
		// verifica o SO e pausa para leitura.
		#ifdef __linux__
			system("read -p 'pressione enter para continuar'");
		#elif _WIN32
			system("pause");
		#endif
	}
