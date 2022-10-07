#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void insere(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("Insira o valor da Matriz[%d][%d]: ", i, j);
        scanf("%d", &matriz[i][j]);
      } //for j
    } //for i
  } //função
  void passagem(int matriz[tf][tf], int tll, int tlc, int vetor[tf]) {
    int soma = 0;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        soma += matriz[i][j];
      } //for j
      vetor[i] = soma;
      soma = 0;
    } //for i
  } //função
  void exibir(int vetor[tf], int tll) {
    for(int i = 0; i < tll; i++) {
      printf("Soma da linha %d: %d\n", i + 1, vetor[i]);
    } //for i
  } //função
  int main() {
    int menu = 999, matriz[tf][tf], tll, tlc, vetor[tf];

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir dados na matriz.\n");
      printf("2 - Somar linhas e inserir num vetor.\n");
      printf("3 - Exibir vetor resultante.\n");
      printf("0 - Sair.\n");
      printf("\nO que você deseja fazer? ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          printf("Quantas linhas terá a matriz? ");
          scanf("%d", &tll);
          printf("E quantas colunas? ");
          scanf("%d", &tlc);
          insere(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 2:
          passagem(matriz, tll, tlc, vetor);
          printf("Soma realizada e valores inseridos no vetor.\n");
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 3:
          exibir(vetor, tll);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
      } //switch
    } //while
  return 0;
  } //main
