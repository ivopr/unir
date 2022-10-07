//system("read -n1 -r -p 'Press any key to continue...' key");
//system("clear");
#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void insere(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("linha %.2d coluna %.2d: ", i, j);
        scanf("%d", &matriz[i][j]);
      } //for coluna
    } //for linha
  } //função

  void exibe(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("%.3d ", matriz[i][j]);
      }//for coluna
      printf("\n");
    }//for linha
  }//função

  void soma(int matriz[tf][tf], int vetor[tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      vetor[i] = 0;
    } //for zera vetor
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        vetor[i] += matriz[i][j];
      } //for coluna
      printf("Soma dos valores da linha %d: %d\n", i + 1, vetor[i]);
    } //for linha
  } //função
  int main() {
    int menu = 999, matriz[tf][tf], vetor[tf], tll, tlc;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir valores na matriz.\n");
      printf("2 - Mostrar matriz.\n");
      printf("3 - Soma das linhas.\n");
      printf("0 - Sair.\n");
      printf("\nOque desejas fazer, jovem padawan? ");
      scanf("%d", &menu);
      switch (menu) {
        case 1:
          printf("Quantas linhas na matriz? ");
          scanf("%d", &tll);
          printf("E quantas colunas? ");
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
          soma(matriz, vetor, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
      } //switch
    } //while
  return 0;
  } //main
