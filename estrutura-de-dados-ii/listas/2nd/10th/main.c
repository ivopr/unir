#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char filename[50], c;

	printf("Nome do arquivo a ser lido: ");
	scanf("%s", filename);

	FILE *f = fopen(strcat(filename, ".txt"), "r");
	if(!f) return 1;

	while((c = fgetc(f)) != EOF) {;
		if(c == '\n')
			printf("\n");
		else
			printf("%c", c);
	}
	printf("\n");

	exit(0);
}
