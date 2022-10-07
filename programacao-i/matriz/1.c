//system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
//system("clear");
#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void insere(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("linha %.2d coluna %.2d ", i, j);
        scanf("%d", &matriz[i][j]);
      } //for coluna
    } //for linha
  } //função
  void exibe(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("%.3d ", matriz[i][j]);
      } //for coluna
      printf("\n");
    } //for linha
  } //função
  void diag(int matriz[tf][tf], int tll, int tlc) {
    int principal = 0, secundaria = 0;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        if(i == j) {
          principal += matriz[i][j];
        } //if princ
        if(i + j == tlc - 1) {
          secundaria += matriz[i][j];
        } //if secund
      } //for coluna
    } //for linha
    printf("Soma dos valores da diagonal principal: %d\n", principal);
    printf("Soma dos valores da matriz secundaria: %d\n", secundaria);
  } //função
  int main() {
    int menu = 999, matriz[tf][tf], tll, tlc;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir valores na matriz.\n");
      printf("2 - Mostrar matriz.\n");
      printf("3 - Soma das diagonais.\n");
      printf("0 - Sair.\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch (menu) {
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
          diag(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
      } //switch
    } //while
  return 0;
  } //main
