#include <stdio.h>
#include <stdlib.h>
  void read(int num[10]) {
    int i;
    for(i = 0; i < 10; i++) {
      printf("Insira o valor de num[%d]: ", i);
      scanf("%d", &num[i]);
      system("clear");
    }
  }
  int pos(int num[10]) {
    int pos = 0, i;
    for(i = 0; i < 10; i++) {
      if(num[i] > 0)
        pos++;
    }
  return pos;
  }
  int neg(int num[10]) {
    int neg = 0, i;
    for(i = 0; i < 10; i++) {
      if(num[i] < 0)
        neg++;
    }
  return neg;
  }
  int null(int num[10]) {
    int null = 0, i;
    for(i = 0; i < 10; i++) {
      if(num[i] == 0)
        null++;
    }
    return null;
  }

  int odd(int num[10]) {
    int i, odd = 0;
    for(i = 0; i < 10; i++) {
      if(num[i] % 2 == 0)
        odd++;
    }
  return odd;
  }
  int even(int num[10]) {
    int i, even = 0;
    for(i = 0; i < 10; i++) {
      if(num[i] % 2 != 0)
        even++;
    }
  return even;
  }


  int main() {
    int num[10];
    read(num);
    printf("A quantidade de números positivos no vetor é: %d\n", pos(num));
    printf("A quantidade de números negativos no vetor é: %d\n", neg(num));
    printf("A quantidade de números nulos no vetor é: %d\n", null(num));
    printf("A quantidade de números pares no vetor é: %d\n", even(num));
    printf("A quantidade de números impares no vetor é: %d\n", odd(num));
  return 0;
  }
