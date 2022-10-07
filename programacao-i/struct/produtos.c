#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 100

  typedef struct {
    int codigo, tl, qtd;
    char nome[tf];
    double preco;
  } produtos;

  void inserir(produtos prd[tf]) {
    printf("quantos produtos? ");
    scanf("%d", &prd->tl);
    for(int i = 0; i < prd->tl; i++) {
      printf("codigo: ");
      scanf("%d", &prd[i].codigo);
      printf("nome: ");
      fflush(stdin);
      fgets(prd[i].nome, tf, stdin);
      printf("quantidade: ");
      scanf("%d", &prd[i].qtd);
      printf("preco: ");
      scanf("%lf", &prd[i].preco);
      printf("\n");
    }//for i
  }//função inserir

  void exibir(produtos prd[tf]) {
    for(int i = 0; i < prd->tl; i++) {
      printf("codigo: %d\n", prd[i].codigo);
      printf("nome: %s", prd[i].nome);
      printf("quantidade: %d\n", prd[i].qtd);
      printf("preco: %.2lf\n\n", prd[i].preco);
    }//for i
  }//função exibir

  void vender(produtos prd[tf]) {
    int qtdv, prod, ex = -1;
    printf("qual produto deseja vender? ");
    scanf("%d", &prod);
    for(int i = 0; i < prd->tl; i++) {
      if(prd[i].codigo == prod) {
        printf("codigo: %d\n", prd[i].codigo);
        printf("nome: %s", prd[i].nome);
        printf("quantidade: %d\n", prd[i].qtd);
        printf("preco: %.2lf\n", prd[i].preco);
        ex = 0;
        printf("quantos produtos deseja vender? ");
        scanf("%d", &qtdv);

        if(prd[i].qtd >= qtdv) {
          prd[i].qtd -= qtdv;
          printf("VENDA REALIZADA!\n");
        } else {
          printf("NAO HA PRODUTOS O SUFICIENTE PARA ESTA VENDA.\n");
        } //if qtd
      }//if nome
    }//for i
    if(ex == -1) {
      printf("O PRODUTO SELECIONADO NAO EXISTE.\n");
    }
  }//função vender

  int main() {
    produtos prd[tf];
    int menu = 999;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir\n");
      printf("2 - Exibir\n");
      printf("3 - Vender\n");
      printf("0 - Sair\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);

      switch (menu) {
        case 1:
          inserir(prd);
          system("pause");
          system("cls");
        break;
        case 2:
          exibir(prd);
          system("pause");
          system("cls");
        break;
        case 3:
          vender(prd);
          system("pause");
          system("cls");
        break;
      }//switch
    }//while
  }//função principal
