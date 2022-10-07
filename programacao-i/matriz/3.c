#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void inserematriz(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("linha %.2d coluna %.2d: ", i, j);
        scanf("%d", &matriz[i][j]);
      }//for linha
    }//for coluna
  }//função

  void exibematriz(int matriz[tf][tf], int tll, int tlc) {
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        printf("%.3d ", matriz[i][j]);
      } //for coluna
      printf("\n");
    } //for linha
  } //função

  void inserevetor(double vetor[tf], int tll) {
    for(int i = 0; i < tll; i++) {
      printf("Qual o preço do produto %d? ", i);
      scanf("%lf", &vetor[i]);
    }//for indice
  }//função

  void exibevetor(double vetor[tf], int tll) {
    for(int i = 0; i < tll; i++) {
      printf("Produto %d: R$ %.2lf\n", i, vetor[i]);
    }//for indice
  }//função

  void fechamesa(int matriz[tf][tf], int tll, int tlc, double vetor[tf], int mesa) {
    double preco, soma = 0;
    for(int j = 0; j < tll; j++) {
      preco = matriz[j][mesa] * vetor[j];
      printf("Produto %d: R$ %.2lf\n", j, preco);
      soma += preco;
    }//for linha
    printf("TOTAL: R$ %.2lf\n", soma);
  }//função

  void fechabar(int matriz[tf][tf], int tll, int tlc, double vetor[tf]) {
    double soma = 0;
    for(int i = 0; i < tll; i++) {
      for(int j = 0; j < tlc; j++) {
        soma += matriz[i][j] * vetor[i];
      }//for coluna
    }//for linha
    printf("TOTAL: R$ %.2lf\n", soma);
  }//função

  void vendas(int matriz[tf][tf], int tll, int tlc) {
    int vetor1[tf];
    printf("TOTAL DE VENDAS\n");
    for(int i = 0; i < tll; i++) {
      vetor1[i] = 0;
      for(int j = 0; j < tlc; j ++) {
        vetor1[i] += matriz[i][j];
      }//for coluna
      printf("Produto %d: %d\n", i, vetor1[i]);
    }//for linha
  }//função

  int main() {
    int menu = 999, matriz[tf][tf], tll, tlc, mesa;
    double vetor[tf];

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir valores na matriz consumo.\n");
      printf("2 - Exibe matriz de consumo.\n");
      printf("3 - Inserir vetor de preços.\n");
      printf("4 - Exibe vetor de preços.\n");
      printf("5 - Fechar e exibir uma mesa.\n");
      printf("6 - Fechar dia.\n");
      printf("7 - Produtos vendidos.\n");
      printf("0 - Sair.\n");
      printf("\nOque desejas fazer, jovem padawan? ");
      scanf("%d", &menu);
      switch (menu) {
        case 1:
          printf("Quantos produtos? ");
          scanf("%d", &tll);
          printf("Quantas mesas? ");
          scanf("%d", &tlc);
          inserematriz(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 2:
          exibematriz(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 3:
          inserevetor(vetor, tll);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 4:
          exibevetor(vetor, tll);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 5:
          printf("Qual mesa fechar? ");
          scanf("%d", &mesa);
          fechamesa(matriz, tll, tlc, vetor, mesa);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 6:
          fechabar(matriz, tll, tlc, vetor);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;;
        case 7:
          vendas(matriz, tll, tlc);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
      }//switch
    }//while
  return 0;
  }//main
