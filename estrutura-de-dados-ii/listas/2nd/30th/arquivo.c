#include "arquivo.h"

void escreveRegVar() {
	aluno a[2];
	char filename[50];

	printf("nome do arquivo a ser escrito: ");
	scanf("%s", filename);

	FILE *arq = fopen(strcat(filename, ".txt"), "w");
	if(!arq) return;

	for(int i = 0; i < 2; i++) {
		printf("aluno %d\n", i + 1);
		printf("nome: ");
		scanf("%s", a[i].nome);

		printf("endereco: ");
		scanf("%s", a[i].ender);

		printf("RA: ");
		scanf("%s", a[i].ra);

		fprintf(arq, "%s|%s|%s|\n", a[i].nome, a[i].ender, a[i].ra);
	}
	fclose(arq);
}

void leRegVar() {
	char filename[50], c;

	printf("nome do arquivo a ser lido: ");
	scanf("%s", filename);

	FILE *arq = fopen(strcat(filename, ".txt"), "r");
	if(!arq) return;

	int i = 0;
	while((c = fgetc(arq)) != EOF) {
		printf("aluno %d\n", i + 1);
		printf("nome: ");
		while(c != '|') {
			printf("%c", c);
			c = fgetc(arq);
		}

		c = fgetc(arq);
		printf("\nendereco: ");
		while(c != '|') {
			printf("%c", c);
			c = fgetc(arq);
		}

		c = fgetc(arq);
		printf("\nRA: ");
		while(c != '|') {
			printf("%c", c);
			c = fgetc(arq);
		}

		printf("\n\n");
		fgetc(arq);
		i++;
	}
	fclose(arq);
}

void escreveRegFix() {
	aluno a[2];
	char filename[50], buffer[101] = "";

	printf("nome do arquivo a ser escrito: ");
	scanf("%s", filename);

	FILE *arq = fopen(strcat(filename, ".txt"), "w");
	if(!arq) return;

	for(int i = 0; i < 2; i++) {
		printf("aluno %d\n", i + 1);
		printf("nome: ");
		scanf("%s", a[i].nome);

		printf("endereco: ");
		scanf("%s", a[i].ender);

		printf("RA: ");
		scanf("%s", a[i].ra);

		strcat(buffer, a[i].nome);
		strcat(buffer, "|");
		strcat(buffer, a[i].ender);
		strcat(buffer, "|");
		strcat(buffer, a[i].ra);
		strcat(buffer, "|");

		if(strlen(buffer) < 100) {
			for(int i = strlen(buffer); i < 100; i++) {
				buffer[i] = '-';
			}
			buffer[100] = '\0';
			fprintf(arq, "%s\n", buffer);
		}

		strcpy(buffer, "");
	}
	fclose(arq);
}

void leRegFix() {
	char filename[50], c;

	printf("nome do arquivo a ser lido: ");
	scanf("%s", filename);

	FILE *arq = fopen(strcat(filename, ".txt"), "r");
	if(!arq) return;

	int i = 0;
	while((c = fgetc(arq)) != EOF) {
		printf("aluno %d\n", i + 1);
		printf("nome: ");
		while(c != '|') {
			printf("%c", c);
			c = fgetc(arq);
		}

		c = fgetc(arq);
		printf("\nendereco: ");
		while(c != '|') {
			printf("%c", c);
			c = fgetc(arq);
		}

		c = fgetc(arq);
		printf("\nRA: ");
		while(c != '|') {
			printf("%c", c);
			c = fgetc(arq);
		}

		printf("\n\n");

		while((c = fgetc(arq)) == '-');
		i++;
	}
	fclose(arq);
}
