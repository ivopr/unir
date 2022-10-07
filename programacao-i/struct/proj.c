#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 50

  typedef struct {
    char desc[tf];
    int id, fornecedor, estoque, minimo, maximo, tl;
  } produto;

  void insere(produto vetor[tf]) {
    printf("quantos produtos estarao disponiveis? ");
    scanf("%d", &vetor->tl);
    system("cls");
    for(int i = 0; i < vetor->tl; i++) {
      printf("produto %d id: ", i);
      scanf("%d", &vetor[i].id);
      printf("produto %d descricao: ", i);
      fflush(stdin);
      fgets(vetor[i].desc, tf, stdin);
      printf("produto %d fornecedor: ", i);
      scanf("%d", &vetor[i].fornecedor);
      printf("produto %d em estoque: ", i);
      scanf("%d", &vetor[i].estoque);
      printf("produto %d quantidade minima: ", i);
      scanf("%d", &vetor[i].minimo);
      printf("produto %d quantidade maxima: ", i);
      scanf("%d", &vetor[i].maximo);
      system("pause");
      system("cls");
    }//for
  }//função

  void exibe(produto vetor[tf]) {
    for(int i = 0; i < vetor->tl; i++) {
      printf(" id: %.2d\n desc: %s fornecedor: %.2d\n estoque: %.2d\n minimo: %.2d\n maximo: %.2d\n", vetor[i].id, vetor[i].desc, vetor[i].fornecedor, vetor[i].estoque, vetor[i].minimo, vetor[i].maximo);
    }//for
    system("pause");
    system("cls");
  }//função

  void busca(produto vetor[tf]) {
    int busca, pos = -1;
    printf("qual id do produto para buscar? ");
    scanf("%d", &busca);
    for(int i = 0; i < vetor->tl; i++) {
      if(vetor[i].id == busca) {
        printf("codigo de produto %d encontrado no indice %d\n", busca, i);
        pos = 0;
      }//if
    }//for
    if(pos == -1) {
      printf("o codigo de produto %d é inexistente", busca);
    }//if
    system("pause");
    system("cls");
  }//função

  void abaixo(produto vetor[tf]) {
    for(int i = 0; i < vetor->tl; i++) {
      if(vetor[i].estoque < vetor[i].minimo) {
        printf("produto %d precisa ser comprado\n", vetor[i].id);
      }//if
    }//for
    system("pause");
    system("cls");
  }//função

  void acima(produto vetor[tf]) {
    for(int i = 0; i < vetor->tl; i++) {
      if(vetor[i].estoque > vetor[i].maximo) {
        printf("o produto %d tem mais unidades do que o necessario\n", vetor[i].id);
      }//if
    }//for
    system("pause");
    system("cls");
  }//função

  void remover(produto vetor[tf]) {
    int indice, tl = vetor->tl;
    printf("qual produto remover? (busque o indice antes na opcao 3) ");
    scanf("%d", &indice);
    for(int i = indice; i < tl; i++) {
      vetor[i] = vetor[i + 1];
    }//for
    tl--;
    vetor->tl = tl;1
    system("cls");
  }//função

  int main() {
    produto vetor[tf];
    int menu = 999;

    while(menu != 0) {
      printf("1 - inserir produtos\n");
      printf("2 - exibir produtos\n");
      printf("3 - buscar produtos\n");
      printf("4 - abaixo do minimo\n");
      printf("5 - acima do minimo\n");
      printf("6 - remover produto\n");
      printf("0 - sair\n");

      printf("selecione acao: ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          insere(vetor);
        break;
        case 2:
          exibe(vetor);
        break;
        case 3:
          busca(vetor);
        break;
        case 4:
          abaixo(vetor);
        break;
        case 5:
          acima(vetor);
        break;
        case 6:
          remover(vetor);
        break;
      }//switch
    }//enquanto
  }//principal
