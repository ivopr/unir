#include <stdio.h>
#include <stdlib.h>
  void read(int vetor[5]) {
    for(int i = 0; i < 5; i++) {
      printf("Insira o valor de vetor[%d]: ", i);
      scanf("%d", &vetor[i]);
      system("clear");
    }
  }
  void plus(int num[5], int num1[5], int num2[5]) {
    for(int i = 0; i < 5; i++) {
      num2[i] = num[i] + num1[i];
    }
  }
  void show(int num2[5]) {
    for(int i = 0; i < 5; i++) {
      printf("O valor em num2[%d] é: %d\n", i, num2[i]);
    }
  }

  int main() {
    int num[5], num1[5], num2[5];
    read(num);
    read(num1);
    plus(num, num1, num2);
    show(num2);
  return 0;
  }
