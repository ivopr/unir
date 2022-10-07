#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char filename[50];
	int numeros[10];

	printf("deseja salar em que arquivo: ");
	scanf("%s", filename);

	FILE *f = fopen(strcat(filename, ".txt"), "w");
	if(!f) return 1;

	for(int i = 0; i < 10; i++) {
		printf("insira um numero (%d/10): ", i + 1);
		scanf("%d", &numeros[i]);

		fprintf(f, "%.3d ", numeros[i]);
	}
	fprintf(f, "\n");
	fclose(f);
	exit(0);
}
