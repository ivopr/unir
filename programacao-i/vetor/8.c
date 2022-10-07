#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void insere(int vetor[tf], int tl) {
    printf("INSERIR DADOS\n");
    for(int i = 0; i < tl; i++) {
      printf("indice %d: ", i);
      scanf("%d", &vetor[i]);
    } //for
  } //function read()

  void exibe(int vetor[tf], int tl) {
    printf("EXIBIR VETOR\n");
    for(int i = 0; i < tl; i++) {
      printf("indice %d: %d.\n", i, vetor[i]);
    } //for
  } //function show()

  void busca(int vetor[tf], int tl, int num) {
    int pos = -1;
    for(int i = 0; i < tl; i++) {
      if(vetor[i] == num) {
        printf("numero %d foi encontrado no indice %d.\n", num, i);
        pos = 0;
      } //if
    } //for
    if(pos == -1)
      printf("numero %d nao existe no vetor.\n", num);
  } //function search()

  int buscaint(int vetor[tf], int tl, int num) {
    int pos = -1;
    for(int i = 0; i < tl; i++) {
      if(vetor[i] == num) {
        pos = 0;
      } //if
    } //for
    return pos;
  } //function search()

  void intersec(int vetor[tf], int vetor1[tf], int tl, int tl1) {
    int posicao, num;
    for(int i = 0; i < tl; i++) {
      num = vetor[i];
      posicao = buscaint(vetor1, tl1, num);
      if(posicao != -1) {
        printf("%.2d ", num);
      }//if
    }//for
    printf("\n");
  } //função

  void dif(int vetor[tf], int vetor1[tf], int tl, int tl1) {
    for(int i = 0, j = 0; i < tl, j < tl1; i++, j++) {
      int dif = vetor[i] - vetor1[j];
      printf("indice %d e indice1 %d: %d.\n", i, j, dif);
    } //for
  } //função

  void uni(int vetor[tf], int vetor1[], int tl, int tl1) {
    for(int i = 0; i < tl; i++) {
      printf("%d ", vetor[i]);
    } //for
    for(int j = 0; j < tl1; j++) {
      printf("%d ", vetor1[j]);
    } //for
    printf("\n");
  } //uni

  int main() {
    //entry numero da ação no menu
    //us tamanho usado do array
    //ps tamanho que o array pode ter
    int menu = 999, vetor[tf], vetor1[tf], tl, tl1, num;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir dados no vetor.\n");
      printf("2 - Inserir dados no vetor1.\n");
      printf("3 - Exibe vetor.\n");
      printf("4 - Exibe vetor1.\n");
      printf("5 - Busca no vetor.\n");
      printf("6 - Busca no vetor1.\n");
      printf("7 - Interseccao.\n");
      printf("8 - Diferenca.\n");
      printf("9 - Uniao.\n");
      printf("0 - Sair.\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          printf("Qual o tamanho do vetor: ");
          scanf("%d", &tl);
          insere(vetor, tl);
          system("clear");
        break;
        case 2:
          printf("Qual o tamanho do vetor1: ");
          scanf("%d", &tl1);
          insere(vetor1, tl1);
          system("clear");
        break;
        case 3:
          exibe(vetor, tl);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 4:
          exibe(vetor1, tl1);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 5:
          printf("numero para buscar no vetor: ");
          scanf("%d", &num);
          busca(vetor, tl, num);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 6:
          printf("numero para buscar no vetor1: ");
          scanf("%d", &num);
          busca(vetor1, tl1, num);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 7:
          intersec(vetor, vetor1, tl, tl1);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 8:
          dif(vetor, vetor1, tl, tl1);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 9:
          uni(vetor, vetor1, tl, tl1);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
      } //switch
    } //while
  } //main
