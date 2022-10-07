#include <stdio.h>
#include <stdlib.h>
  void read(int num[5]) {
    for(int i = 0; i < 5; i++) {
      printf("Insira o valor do vetor[%d]: ", i);
      scanf("%d", &num[i]);
      system("clear");
    }
  }

  int show(int num[5]) {
    for(int i = 0; i < 5; i++) {
      printf("num[%d] = %d\n", i, num[i]);
    }
  }

  double media(int num[5]) {
    double plus;
    for(int i = 0; i < 5; i++) {
      plus += num[i];
    }
    double media = plus / 5;
    return media;
  }

  int showup(int num[5], double media) {
    for(int i = 0; i < 5; i++) {
      if(num[i] > media)
        printf("O vetor[%d] é igual à %d, que é maior que é maior que %.lf\n", i, num[i], media);
    }
  }

  int main() {
    int num[5];
    read(num);
    show(num);
    printf("Média: %.lf\n", media(num));
    showup(num, media(num));
  return 0;
  }
