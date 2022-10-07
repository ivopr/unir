/*
	estrutura de dados I
	lista 1 - ex 6
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/

#include <stdio.h>
#include <stdlib.h>

	int main() {
		double vhora, horas;
		
		// while true
		while(1) {
			printf("salario por horas trabalhadas - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair\n");
			
			// entrada de dados
			printf("valor por hora: ");
			scanf("%lf", &vhora);
			printf("horas trabalhadas: ");
			scanf("%lf", &horas);
			
			// verifica o EOF e encerra o programa se necessário
			if(feof(stdin)) {
				break;
			}
			
			// exibe resultados
			printf("salario sem adicional: %.2lf\nsalario: %.2lf\n", vhora * horas, (vhora * horas) + ((vhora * horas) * 0.10));
			
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
