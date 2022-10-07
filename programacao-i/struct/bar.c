#include <stdio.h>
#include <stdlib.h>
#define tf 100

  //define struct bar
  typedef struct {
    int mesas[tf][tf], tll, tlc;
    double precos[tf], diario[tf];
  } bar;

  //função para inserção de dados na matriz de mesas
  bar mesas(bar *b) {
    system("cls");
    printf("Quantas mesas? ");  scanf("%d", &b->tlc);
    printf("Quantos produtos? ");  scanf("%d", &b->tll);
    system("cls");
    for(int i = 0; i < b->tlc; i++) {
      for(int j = 0; j < b->tll; j++) {
        printf("mesa %d produto %d: ", i, j);
        scanf("%d", &b->mesas[j][i]);
      }//produto
      system("pause");
      system("cls");
    }//mesa
  }//função

  //função para inserção de dados no vetor de preços
  bar precos(bar *b) {
    for(int i = 0; i < b->tll; i++) {
      printf("produto %d: ", i);
      scanf("%lf", &b->precos[i]);
    }//preço
    system("pause");
    system("cls");
  }//função

  //função para exibir a matriz de mesas e o vetor de preços
  bar exibe(bar b) {
    for(int i = 0; i < b.tll; i++) {
      for(int j = 0; j < b.tlc; j++) {
        printf("%.3d ", b.mesas[i][j]);
      }//produto
      printf("\n");
    }//mesa
    printf("\n");
    for(int i = 0; i < b.tll; i++) {
      printf("produto %.2d: R$ %.2lf\n", i, b.precos[i]);
    }//preço
    system("pause");
    system("cls");
  }//função

  //função para fechar a conta de uma mesa
  //não precisa de ponteiro, pois não passará nenhum valor pro struct
  bar conta(bar b) {
    double subtotal = 0, desconto, total;
    int mesa;
    system("cls");
    printf("mesa a ser calculada: ");
    scanf("%d", &mesa);
    system("cls");
    printf("mesa %d\n", mesa);
    for(int i = 0; i < b.tll; i++) {
      subtotal += (b.mesas[i][mesa] * b.precos[i]);
      printf("produto %d: R$ %.2lf\n", i, b.mesas[i][mesa] * b.precos[i]);
    }//produto
    printf("subtotal: R$ %.2lf\n", subtotal);
    printf("desconto (porcentagem): ");  scanf("%lf", &desconto);
    total = subtotal - ((desconto / 100) * subtotal);
    printf("total: R$ %.2lf\n", total);
    b.diario[mesa] = total;
    system("pause");
    system("cls");
  }//função

  //função para fechar a conta de todas as mesas
  //também não precisa de ponteiro, pois, como ja falado, não será inserido nada no struct
  bar fechar(bar b) {
    system("cls");
    double dia = 0;
    for(int i = 0; i < b.tll; i++) {
      for(int j = 0; j < b.tlc; j++) {
        dia += b.mesas[i][j] * b.precos[i];
      }//coluna
    }//linha
    printf("total: R$ %.2lf\n", dia);
    printf("ESTE TOTAL NAO SE ENCONTRA COM OS DEVIDOS DESCONTOS.\n");
    system("pause");
    system("cls");
  }//função

  int main() {
    int menu = 999;
    bar b;
    while(menu != 0) {
      printf("1 - criar tabela de mesas.\n");
      printf("2 - criar tabela de precos do dia.\n");
      printf("3 - exibir tabelas.\n");
      printf("4 - fechar mesa.\n");
      printf("5 - fechar bar.\n");
      printf("0 - sair.\n");
      printf("\no que deseja fazer? ");
      scanf("%d", &menu);

      switch(menu) {
        case 1:
          mesas(&b);
        break;
        case 2:
          precos(&b);
        break;
        case 3:
          exibe(b);
        break;
        case 4:
          conta(b);
        break;
        case 5:
          fechar(b);
        break;
      }//switch
    }//while
    return 0;
  }//main
