#include <stdio.h>
#include <stdlib.h>
#define tf 100
  //cria um struct para armazenar os dois vetores
  typedef struct {
    int vetor[tf], vetor1[tf], tl, tl1;
  } vetor; //define o nome do struct como 'vetor'

  //função para ler os vetores
  //o tipo da função é o nome do struct
  //vetor *v indica que *v é um ponteiro e é do tipo vetor, que foi definido anteriormente
  vetor insere(vetor *v) {
    printf("tamanho do vetor: ");  scanf("%d", &v->tl);
    printf("tamanho do vetor1: ");  scanf("%d", &v->tl1);
    for(int i = 0; i < v->tl; i++) {
      printf("indice %d: ", i);
      scanf("%d", &v->vetor[i]);
    }//for vetor
    for(int i = 0; i < v->tl1; i++) {
      printf("indice1 %d: ", i);
      scanf("%d", &v->vetor1[i]);
    }//for vetor1
  }//função

  //função para exibir os dois vetores
  vetor exibe(vetor v) {
    for(int i = 0; i < v.tl; i++) {
      printf("indice %d: %d\n", i, v.vetor[i]);
    }//indice
    for(int i = 0; i < v.tl1; i++) {
      printf("indice1 %d: %d\n", i, v.vetor1[i]);
    }//indice1
  }//função

  int main() {
    int menu = 999;
    vetor v;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir dados no vetor e vetor1.\n");
      printf("2 - Exibir dados do vetor e vetor1.\n");
      printf("0 - Sair.\n");
      printf("\nOpção: ");  scanf("%d", &menu);
      switch(menu) {
        case 1:
          insere(&v);
          system("pause");
          system("cls");
        break;
        case 2:
          exibe(v);
          system("pause");
          system("cls");
        break;
      }//switch
    }//while
  }//main
