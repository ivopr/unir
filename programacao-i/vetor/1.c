#include <stdio.h>
  int main() {
    //Declarar variáveis.
    int vetor[5], cont = 0, soma = 0;
    //Repetição para entrada de dados do vetor, contagem de itens e soma.
    for(int i = 0; i < 5; i++) {
      scanf("%d", &vetor[i]);
      cont++;
      soma += vetor[i];
    }
    double media = soma / cont;
    for(int i = 0; i < 5; i++) {
      printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    for(int i = 0; i < 5; i++) {
      if(vetor[i] > media)
        printf("O vetor[%d] e igual a %d, que e maior que %.lf\n", i, vetor[i], media);
    }
    printf("Media = %.lf\n", media);
  return 0;
  }
