#include <stdio.h>
#include <stdlib.h>
#define tf 100
  //cria uma struct para armazenamento de dados
  typedef struct {
    int matriz[tf][tf];
  } matriz;  // define o nome da struct, que nesse caso é 'matriz'

  //função para inserir dados na matriz
  //note que o tipo da função não é void, nem int e nem float ou afins, é o nome da struct
  matriz insere(int tll, int tlc) {
    matriz m;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("linha %d coluna %d? ", i, j);
        scanf("%d", &m.matriz[i][j]);
      }//for coluna
    }//for linha
  }//função

  //função para exibir a matriz
  //assim como na anterior, para ele usar o struct o tipo da função é o nome do struct
  matriz exibe(int tll, int tlc) {
    matriz m;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("%.3d ", m.matriz[i][j]);
      }//for coluna
      printf("\n");
    }//for linha
  }//função

  //função para calcular a soma de cada coluna da matriz
  //assim como na anterior, para ele usar o struct o tipo da função é o nome do struct
  matriz coluna(int tll, int tlc) {
    matriz m;
    int soma = 0;
    for(int i = 0; i < tlc; i++) {
      for(int j = 0; j < tll; j ++) {
        soma += m.matriz[j][i];
      }//for linha
      printf("coluna %d: %d\n", i, soma);
      soma = 0;
    }//for coluna
  }//função

  //função para calcular a soma de cada linha da matriz
  //assim como na anterior, para ele usar o struct o tipo da função é o nome do struct
  matriz linha(int tll, int tlc) {
    matriz m;
    int soma = 0;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        soma += m.matriz[i][j];
      }//for coluna
      printf("linha %d: %d\n", i, soma);
      soma = 0;
    }//for linha
  }//função

  //inicia a função principal do programa
  int main() {
    int menu = 999, tll, tlc;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir dados na matriz.\n");
      printf("2 - Exibir matriz.\n");
      printf("3 - Somar cada linha da matriz.\n");
      printf("4 - Somar cada coluna da matriz.\n");
      printf("0 - Sair.\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          printf("Quantas linhas? "); scanf("%d", &tll);
          printf("Quantas colunas? "); scanf("%d", &tlc);
          insere(tll, tlc);
          system("pause");
          system("cls");
        break;
        case 2:
          exibe(tll, tlc);
          system("pause");
          system("cls");
        break;
        case 3:
          linha(tll, tlc);
          system("pause");
          system("cls");
        break;
        case 4:
          coluna(tll, tlc);
          system("pause");
          system("cls");
        break;
      }//switch
    }//while
    return 0;
  }//main
