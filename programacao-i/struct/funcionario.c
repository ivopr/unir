#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 128

  typedef struct {
    char nome[tf], idade[tf], sexo[tf], cpf[tf], nasc[tf], setor[tf], cargo[tf], salario[tf];
    int tl;
  } empresa;

  void inserir(empresa funcionarios[tf]) {
    system("cls");
    printf("quantidade funcionarios: ");
    scanf("%d", &funcionarios->tl);
    system("cls");
    for(int i = 0; i < funcionarios->tl; i++) {
      printf("nome: ");
      fflush(stdin);
      fgets(funcionarios[i].nome, tf, stdin);
      printf("idade: ");
      fflush(stdin);
      fgets(funcionarios[i].idade, tf, stdin);
      printf("sexo: ");
      fflush(stdin);
      fgets(funcionarios[i].sexo, tf, stdin);
      printf("cpf: ");
      fflush(stdin);
      fgets(funcionarios[i].cpf, tf, stdin);
      printf("nascimento: ");
      fflush(stdin);
      fgets(funcionarios[i].nasc, tf, stdin);
      printf("setor: ");
      fflush(stdin);
      fgets(funcionarios[i].setor, tf, stdin);
      printf("cargo: ");
      fflush(stdin);
      fgets(funcionarios[i].cargo, tf, stdin);
      printf("salario: ");
      fflush(stdin);
      fgets(funcionarios[i].salario, tf, stdin);
      system("pause");
      system("cls");
    }//for
  }//função

  void exibir(empresa funcionarios[tf]) {
    for(int i = 0; i < funcionarios->tl; i++) {
      system("cls");
      printf("FUNCIONARIO %.3d\n", i);
      printf("nome: %s", funcionarios[i].nome);
      printf("idade: %s", funcionarios[i].idade);
      printf("sexo: %s", funcionarios[i].sexo);
      printf("nascimento: %s", funcionarios[i].nasc);
      printf("cpf: %s", funcionarios[i].cpf);
      printf("setor: %s", funcionarios[i].setor);
      printf("cargo: %s", funcionarios[i].cargo);
      printf("salario: %s", funcionarios[i].salario);
      system("pause");
      system("cls");
    }//for
  }//função

  int main() {
    empresa funcionarios[tf];
    int menu = 999;

    while(menu != 0) {
      printf("1 - inserir funcionarios\n");
      printf("2 - exibir funcionarios\n");
      printf("0 - sair\n");
      printf("\nmenu: ");
      scanf("%d", &menu);

      switch(menu) {
        case 1:
          inserir(funcionarios);
        break;
        case 2:
          exibir(funcionarios);
        break;
      }//switch
    }//while
  }//principal
