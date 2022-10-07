#include "arquivo.h"

void pause(void) {
	setbuf(stdin, NULL);
	printf("Pressione [Enter] para continuar...");
	getchar();
}

int countLines(FILE *arq) {
	int ch = 0, linhas = 0;

	linhas++;
	while((ch = fgetc(arq)) != EOF) {
		if(ch == '\n')
			linhas++;
	}
	fseek(arq, 0, SEEK_SET);
	return linhas;
}

int main() {
	aluno a[20];
	FILE *arq = fopen("saida1.txt", "r");
	FILE *arq1 = fopen("saida2.txt", "w");

	if(arq == NULL) return 1;
	if(arq1 == NULL) return 2;

	int i = 0, j = 0;
	char c;

	int linhas = countLines(arq);

	do {
		if(i < linhas - 1) {
			while((c = fgetc(arq)) != '|') {
				a[i].nome[j] = c;
				j++;
			}
			a[i].nome[j] = '\0';
			j = 0;

			while((c = fgetc(arq)) != '|') {
				a[i].ender[j] = c;
				j++;
			}
			a[i].ender[j] = '\0';
			j = 0;

			while((c = fgetc(arq)) != '|') {
				a[i].curso[j] = c;
				j++;
			}
			a[i].curso[j] = '\0';
			j = 0;

			fprintf(arq1, "Nome=%s|Endereco=%s|Curso=%s|\n", a[i].nome, a[i].ender, a[i].curso);
		}
		i++;
	} while(fgetc(arq) != EOF);

	printf("Arquivo saida2.txt gerado.\n");
	fclose(arq);
	fclose(arq1);
	pause();
	exit(0);
}
