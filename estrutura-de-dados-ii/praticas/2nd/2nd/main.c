#include "arquivo.h"

void pause() {
	setbuf(stdin, NULL);
	printf("Pressione [Enter] para continuar...");
	getchar();
}

int main() {
	aluno a[20];
	FILE *arq = fopen("entrada.txt", "r");
	FILE *arq1 = fopen("saida.txt", "w");

	if(arq == NULL) return 1;
	if(arq1 == NULL) return 2;

	int i = 0;
	while(!feof(arq)) {
		fscanf(arq, "%s\n%s\n%s\n", a[i].nome, a[i].ender, a[i].curso);

		printf("Exibindo Aluno %d\n", i + 1);
		printf("Nome: %s\nEndereco: %s\nCurso: %s\n", a[i].nome, a[i].ender, a[i].curso);

		fprintf(arq1, "%.3d%s%.3d%s%.3d%s", strlen(a[i].nome), a[i].nome, strlen(a[i].ender), a[i].ender, strlen(a[i].curso), a[i].curso);
		i++;
	}

	fclose(arq1);
	fclose(arq);

	pause();
	exit(0);
}
