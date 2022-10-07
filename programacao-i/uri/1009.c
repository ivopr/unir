#include <stdio.h>
  int main() {
    char nome;
    double sfixo, vendas, sfinal;
    scanf("%s", &nome);
    scanf("%lf", &sfixo);
    scanf("%lf", &vendas);sfinal = sfixo + (vendas * 0.15);
    printf("TOTAL = R$ %.2lf\n", sfinal);
  return 0;
  }
