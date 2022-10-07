#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 100

  typedef struct {
    int id, tl;
    char nome[tf];
    double media, nota, nota1, nota2;
  } nano;

  void insere(nano verge[tf]) {
    system("cls");
    printf("quantos alunos? ");
    scanf("%d", &verge->tl);
    printf("\a\a\a");

    system("cls");
    for(int i = 0; i < verge->tl; i++) {
      printf("aluno %d\n", i);
      printf("nome: ");
      fflush(stdin);
      fgets(verge[i].nome, tf, stdin);
      printf("matricula: ");
      scanf("%d", &verge[i].id);
      printf("notas (1, 2 e 3 respectivamente): ");
      scanf("%lf %lf %lf", &verge[i].nota, &verge[i].nota1, &verge[i].nota2);
      system("pause");
      system("cls");
    }
  }

  void insereespecial(nano verge[tf]) {
    system("cls");
    int indice;
    printf("em qual indice ira o novo aluno? ");
    scanf("%d", &indice);

    for(int i = verge->tl + 1; i > indice; i--) {
      verge[i] = verge[i - 1];
    }
    printf("nome: ");
    fflush(stdin);
    fgets(verge[indice].nome, tf, stdin);
    printf("matricula: ");
    scanf("%d", &verge[indice].id);
    printf("notas (1, 2 e 3 respectivamente): ");
    scanf("%lf %lf %lf", &verge[indice].nota, &verge[indice].nota1, &verge[indice].nota2);
    verge->tl = verge->tl + 1;
  }

  void exibe(nano verge[tf]) {
    system("cls");
    for(int i = 0; i < verge->tl; i++) {
      printf("%d\n", verge->tl);
      printf("nome: %s", verge[i].nome);
      printf("matricula: %d\n", verge[i].id);
      printf("nota: %.2lf\n", verge[i].nota);
      printf("nota1: %.2lf\n", verge[i].nota1);
      printf("nota2: %.2lf\n", verge[i].nota2);
      system("pause");
      system("cls");
    }
  }

  int main() {
    int menu = 999;
    nano verge[tf];

    while(menu != 0) {
      printf("1 - iniciar vetor\n");
      printf("2 - exibir\n");
      printf("3 - inserir especial\n");
      printf("0 - sair\n");

      printf("o que deseja fazer? ");
      scanf("%d", &menu);

      switch(menu) {
        case 1:
          insere(verge);
        break;
        case 2:
          exibe(verge);
        break;
        case 3:
          insereespecial(verge);
        break;
      }
    }
    return 0;
  }
