#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 10

  typedef struct {
    char nome[30];
    int matricula, tl;
    double media;
  } alunos;

  void inserir(alunos turma[tf]) {
    printf("quantos alunos tem na turma? ");
    scanf("%d", &turma->tl);
    for(int i = 0; i < turma->tl; i++) {
      printf("nome: ");
      fflush(stdin);
      fgets(turma[i].nome, 30, stdin);
      printf("matricula: ");
      scanf("%d", &turma[i].matricula);
      printf("media: ");
      scanf("%lf", &turma[i].media);
      printf("\n");
    }//for i
  }//função insere

  void exibir(alunos turma[tf]) {
    for(int i = 0; i < turma->tl; i++) {
      printf("nome: %s", turma[i].nome);
      printf("matricula: %d\n", turma[i].matricula);
      printf("media: %.2lf\n\n", turma[i].media);
    }//for i
  }//função exibir

  void separar(alunos turma[tf], alunos aprovados[tf], alunos reprovados[tf]) {
    int tla = 0, tlr = 0;
    for(int i = 0; i < turma->tl; i++) {
      if(turma[i].media >= 6.0) {
        aprovados[tla] = turma[i];
        tla++;
      }//if
      else {
        reprovados[tlr] = turma[i];
        tlr++;
      }//else
    }//for i
    aprovados->tl = tla;
    reprovados->tl = tlr;
  }//função separar

  int main() {
    alunos turma[tf], aprovados[tf], reprovados[tf];
    int menu = 999;

    while(menu != 0) {
      printf("1 - Inserir alunos\n");
      printf("2 - Exibir alunos\n");
      printf("3 - Separar aprovados e reprovados\n");
      printf("4 - Exibir alunos aprovados\n");
      printf("5 - Exibir alunos reprovados\n");
      printf("0 - Sair\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);

      switch(menu) {
        case 1:
          inserir(turma);
          system("pause");
          system("cls");
        break;
        case 2:
          exibir(turma);
          system("pause");
          system("cls");
        break;
        case 3:
          separar(turma, aprovados, reprovados);
          system("pause");
          system("cls");
        break;
        case 4:
          exibir(aprovados);
          system("pause");
          system("cls");
        break;
        case 5:
          exibir(reprovados);
          system("pause");
          system("cls");
        break;
      }//switch
    }//while
  }//função principal
