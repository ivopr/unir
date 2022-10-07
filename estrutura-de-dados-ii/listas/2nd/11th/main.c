#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char fileCopy[50], filePaste[50], c;

	printf("qual o arquivo a ser copiado? ");
	scanf("%s", fileCopy);

	printf("como se chamara o arquivo copia? ");
	scanf("%s", filePaste);

	FILE *copy = fopen(strcat(fileCopy, ".txt"), "r");
	FILE *paste = fopen(strcat(filePaste, ".txt"), "w");

	while((c = fgetc(copy)) != EOF) {
		fprintf(paste, "%c", c);
	}

	fclose(copy);
	fclose(paste);
	exit(0);
}
