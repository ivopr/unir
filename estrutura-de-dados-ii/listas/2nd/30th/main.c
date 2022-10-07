#include "arquivo.h"

int main() {
	int op;

	do {
		printf("1 - criar arq reg variavel\n");
		printf("2 - ler arq reg variavel\n");
		printf("3 - criar arq reg fixo\n");
		printf("4 - ler arq reg fixo\n");
		printf("0 - sair\n");
		printf("menu> ");
		scanf("%d", &op);

		switch(op) {
			case 1: {
				escreveRegVar();
				break;
			}
			case 2: {
				leRegVar();
				break;
			}
			case 3: {
				escreveRegFix();
				break;
			}
			case 4: {
				leRegFix();
				break;
			}
		}
	} while(op != 0);
	return 0;
}
