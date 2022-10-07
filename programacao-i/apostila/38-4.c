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
  void transpor(int matriz[tf][tf], int tll, int tlc) {
    int matriz1[tf][tf];
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        matriz1[j][i] = matriz[i][j];
        printf("Linha %d coluna %d: %d\n", j, i, matriz1[j][i]);
      } //for j
    } //for i
  } //função
  int main() {
    int menu = 999, matriz[tf][tf], tll, tlc;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir dados na matriz.\n");
      printf("2 - Exibir a matriz transposta.\n");
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
          transpor(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
      } //switch
    } //while
  return 0;
} //main
