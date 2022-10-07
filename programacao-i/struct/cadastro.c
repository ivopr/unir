#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 100

  typedef struct {
    char rua[tf], bairro[tf], cidade[tf], estado[tf], cep[tf];
  } end;

  typedef struct {
    char nome[tf], telefone[tf], sexo[tf];
    end endereco;
    double salario;
    int idade, tl;
  } cadastro;

  void cadastrar(cadastro pessoa[tf]) {
    printf("quantos cadastros serão realizados? ");
    scanf("%d", &pessoa->tl);
    for(int i = 0; i < pessoa->tl; i++) {
      printf("nome: ");
      fflush(stdin);
      fgets(pessoa[i].nome, tf, stdin);
      printf("telefone: ");
      fflush(stdin);
      fgets(pessoa[i].telefone, tf, stdin);
      printf("sexo: ");
      fflush(stdin);
      fgets(pessoa[i].sexo, tf, stdin);
      printf("salario: ");
      scanf("%lf", &pessoa[i].salario);
      printf("idade: ");
      scanf("%d", &pessoa[i].idade);
      printf("rua: ");
      fflush(stdin);
      fgets(pessoa[i].endereco.rua, tf, stdin);
      printf("bairro: ");
      fflush(stdin);
      fgets(pessoa[i].endereco.bairro, tf, stdin);
      printf("cidade: ");
      fflush(stdin);
      fgets(pessoa[i].endereco.cidade, tf, stdin);
      printf("estado: ");
      fflush(stdin);
      fgets(pessoa[i].endereco.estado, tf, stdin);
      printf("CEP: ");
      fflush(stdin);
      fgets(pessoa[i].endereco.cep, tf, stdin);
    }//for
  }//função cadastrar

  void exibir(cadastro pessoa[tf]) {
    for(int i = 0; i < pessoa->tl; i++) {
      system("cls");
      printf("CADASTRO %.3d\n", i);
      printf("nome: %s", pessoa[i].nome);
      printf("sexo: %s", pessoa[i].sexo);
      printf("idade: %d\n", pessoa[i].idade);
      printf("salario: %.2lf\n", pessoa[i].salario);
      printf("telefone: %s", pessoa[i].telefone);
      printf("rua: %s", pessoa[i].endereco.rua);
      printf("bairro: %s", pessoa[i].endereco.bairro);
      printf("cidade: %s", pessoa[i].endereco.cidade);
      printf("estado: %s", pessoa[i].endereco.estado);
      printf("cep: %s", pessoa[i].endereco.cep);
      system("pause");
      system("cls");
    }//for
  }//função exibir

  int main() {
    int menu = 999;
    cadastro pessoa[tf];

    while(menu != 0) {
      printf("1 - Cadastrar pessoas\n");
      printf("2 - Exibir pessoas\n");
      printf("3 - Sair\n");

      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);

      switch (menu) {
        case 1:
          cadastrar(pessoa);
          system("pause");
          system("cls");
        break;
        case 2:
          exibir(pessoa);
        break;
      }
    }//while
  }//principal
