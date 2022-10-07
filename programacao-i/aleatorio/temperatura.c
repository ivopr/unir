#include <stdio.h>
#include <stdlib.h>
  int main() {
    double espessura, temperatura;
    printf("qual a espessura da placa? (0 para encerrar) ");
    scanf("%lf", &espessura);

    if(espessura <= 38,11) {
      temperatura = 915;
    }
    else if(espessura <= 50) {
      temperatura = 917;
    } else if(espessura <= 70) {
      temperatura = 920;
    }
    else {
      temperatura = 925;
    }

    while(espessura != 0) {
      printf("ESPESSURA: %.3lfmm\n", espessura);
      printf("TEMPERATURA: ~%.3lf° C\n", temperatura);

      printf("qual a espessura da placa? (0 para encerrar) ");
      scanf("%lf", &espessura);
    }//while
  }//main
