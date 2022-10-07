#include "arquivo.h"

void pause(void) {
	setbuf(stdin, NULL);
	printf("Pressione [Enter] para continuar...");
	getchar();
}

void getQtd(FILE *arq, char qtd[4]) {
	fgets(qtd, 4, arq);
	qtd[3] = '\0';
}

int main() {
	aluno a[20];
	FILE *arq = fopen("saida.txt", "r");
	FILE *arq1 = fopen("saida1.txt", "w");

	if(arq == NULL) return 1;
	if(arq1 == NULL) return 2;

	int i = 0;
	char qtd[4];

	do {
		getQtd(arq, qtd);
		fgets(a[i].nome, atoi(qtd) + 1, arq);

		getQtd(arq, qtd);
		fgets(a[i].ender, atoi(qtd) + 1, arq);

		getQtd(arq, qtd);
		fgets(a[i].curso, atoi(qtd) + 1, arq);

		fprintf(arq1, "%s|%s|%s|\n", a[i].nome, a[i].ender, a[i].curso);
		if(fgetc(arq) != EOF)
			fseek(arq, -1, SEEK_CUR);
		i++;
	} while(!feof(arq));

	printf("Arquivo saida1.txt gerado.\n");
	fclose(arq);
	fclose(arq1);
	pause();
	exit(0);
}
