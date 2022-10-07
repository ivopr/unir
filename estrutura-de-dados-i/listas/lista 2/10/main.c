/*
	estrutura de dados I
	lista 2 - ex 10
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <stdio.h>
#include <stdlib.h>

	int main() {
		int repetir = 1, num, fat;
		
		while(repetir == 1) {
			printf("fatorial\n");
			printf("insira um numero: ");
			scanf("%d", &num);
			
			fat = num;
			
			for(int i = 1; i < num; i++) {
				fat *= num - i;
			}
			
			printf("o fatorial de %d eh %d\n", num, fat);
			
			printf("\ndeseja repetir (1 - sim / 2 - nao)? ");
			scanf("%d", &repetir);
			
			if(repetir == 1) {
				#ifdef __linux__
					system("clear");
				#elif _WIN32
					system("cls");
				#endif
			}
		}
	}
