#include <stdio.h>
  int main() {
		int id, qt, id1, qt1;
		double vl, vl1, vt, vt1, vf;
		scanf("%d %d %lf %d %d %lf", &id, &qt, &vl, &id1, &qt1, &vl1);
		vt = (qt * vl);
		vt1 = (qt1 * vl1);
		vf = (vt + vt1);
		printf("VALOR A PAGAR: R$ %.2lf\n", vf);
	return 0;
	}
