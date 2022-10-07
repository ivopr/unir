#include <stdio.h>
#include <stdlib.h>
#define tf 15
  void insere(int vetor[], int tl) {
    for(int i =0; i < tl; i++) {
      printf("vetor[%d]: ", i);
      scanf("%d", &vetor[i]);
    } //for
  } //função
  void mostra(int vetor[], int tl) {
    for(int i = 0; i < tl; i++) {
      printf("vetor[%d]: %d\n", i, vetor[i]);
    } //for
  } //função
  void media(int vetor[], int tl) {
    double soma = 0, media;
    for(int i = 0; i < tl; i++) {
      soma += vetor[i];
    } //for
    media = soma / tl;
    printf("Média: %.2lf\n", media);
  } //função
  int main() {
    int menu = 999, vetor[tf], tl;

    while(menu != 0) {
      printf("MENU\n1 - Insere dados no vetor.\n2 - Mostra vetor.\n3 - Calcula e exibe média.\n0 - Sair.\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);

      switch(menu) {
        case 1:
          printf("INSERE DADOS NO VETOR.\n");
          printf("Qual o tamanho do vetor? ");
          scanf("%d", &tl);
          insere(vetor, tl);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        break;
        case 2:
          printf("EXIBE VETOR.\n");
          mostra(vetor, tl);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        break;
        case 3:
          printf("CALCULA E EXIBE MÉDIA.\n");
          media(vetor, tl);
          system("read -n1 -r -p 'Press any key to continue...' key");
          system("clear");
        break;
      } //switch
    } //while
  return 0;
  } //main
