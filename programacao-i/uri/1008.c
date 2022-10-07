#include <stdio.h>
	int main() {
		int num, horas;
		double salh, salf;
		scanf("%d %d %lf", &num, &horas, &salh);
		salf = (salh * horas);
		printf("NUMBER = %d\nSALARY = U$ %.2lf\n", num, salf);
  return 0;
	}
