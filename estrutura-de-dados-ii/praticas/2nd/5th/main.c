#include "arquivo.h"

void pause(void) {
	setbuf(stdin, NULL);
	printf("Pressione [Enter] para continuar...");
	getchar();
}

int main() {
	char nome[50];
	int ra = 0, numReg = 0;
	FILE *arq = fopen("turma.txt", "w");

	if(arq == NULL) exit(1);

	for(int i = 0; i < 30; i++) {
		printf("Lendo dados do aluno %d -- RA = -1 para cancelar a inserção de dados\n", i + 1);

		printf("RA: ");
		scanf("%d", &ra);

		if(ra == -1) break;

		printf("Nome: ");
		setbuf(stdin, NULL);
		fgets(nome, 50, stdin);
		nome[strlen(nome) - 1] = '\0';

		fprintf(arq, "%.3d|%s\n", ra, nome);
		numReg++;
	}

	fclose(arq);

	printf("RA a ser buscada: ");
	scanf("%d", &ra);

	FILE *arq1 = fopen("turma.txt", "r");

	if(arq1 == NULL) return 1;

	int raa, i = 0;

	do {
		fscanf(arq1, "%3d|%s\n", &raa, nome);
		i++;
	} while(raa != ra && i < numReg);

	fclose(arq1);

	if(raa == ra) {
		printf("O aluno com a RA %d está presente nos nossos registros e se chama %s.\n", raa, nome);
	} else
		printf("O aluno com a RA %d não existe nos nossos registros.\n", ra);
	printf("Arquivo com os dados dos alunos gerado.\n");

	pause();
	exit(0);
}
