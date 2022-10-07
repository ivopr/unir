#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void insere(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("Insira o valor da linha %d coluna %d: ", i, j);
        scanf("%d", &matriz[i][j]);
      } //for j
    } //for i
  } //função
  void exibe(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
      } //for j
    } //for i
  } //função
  void valores(int matriz[tf][tf], int tll, int tlc) {
    int soma = 0;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        if(i > j) {
          soma += matriz[i][j];
        } //if
      } //for j
      printf("Soma linha %d: %d\n", i, soma);
    } //for i
  } //função
  int main() {
    int menu = 999, matriz[tf][tf], vetor[tf], tll, tlc, linha, linha1;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir dados na matriz.\n");
      printf("2 - Mostrar matriz.\n");
      printf("3 - Soma linhas até a diagonal principal.\n");
      printf("0 - Sair.\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          printf("Quantas linhas? ");
          scanf("%d", &tll);
          printf("Quantas colunas? ");
          scanf("%d", &tlc);
          insere(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 2:
          exibe(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 3:
          valores(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
      } //switch
    } //while
  return 0;
} //main
