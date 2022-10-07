#include "arquivo.h"

void pause() {
	setbuf(stdin, NULL);
	printf("Pressione [Enter] para continuar...");
	getchar();
}

int main() {
	aluno a[2], b[2];
	FILE *arq = fopen("alunos.txt", "w");
	if(arq == NULL) return 1;

	for(int i = 0; i < 2; i++) {
		printf("Aluno %d\n", i + 1);
		printf("Nome: ");
		scanf("%s", a[i].nome);
		printf("Endereco: ");
		scanf("%s", a[i].ender);
		printf("Curso: ");
		scanf("%s", a[i].curso);

		fprintf(arq, "%s\n%s\n%s\n", a[i].nome, a[i].ender, a[i].curso);
	}

	fclose(arq);

	FILE *arqr = fopen("alunos.txt", "r");

	for(int j = 0; j < 2; j++) {
		fscanf(arqr, "%s\n%s\n%s\n", b[j].nome, b[j].ender, b[j].curso);

		printf("Exibindo Aluno %d\n", j + 1);
		printf("Nome: %s\nEndereco: %s\nCurso: %s\n", b[j].nome, b[j].ender, b[j].curso);
	}

	pause();
	fclose(arqr);
}
