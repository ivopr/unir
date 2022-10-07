#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char filename[20], c;

	printf("Qual o nome do arquivo a ser lido? ");
	scanf("%s", filename);

	FILE *f = fopen(strcat(filename, ".txt"), "r");

	fseek(f, -11, SEEK_END);

	while((c = fgetc(f)) != EOF)
		printf("%c", c);

	fclose(f);
	exit(0);
}
