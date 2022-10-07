#include <stdio.h>
#include <stdlib.h>
#define tf 100
  void insere(int prd[], int qtd[], int tl) {
    for(int i = 0; i < tl; i++) {
      printf("ID Produto: ");
      scanf("%d", &prd[i]);
      printf("Quantas pecas do produto %d estao disponiveis? ", prd[i]);
      scanf("%d", &qtd[i]);
    } //for
  } //function
  void exibe(int prd[], int qtd[], int tl) {
    printf("PRODUTO     QUANTIDADE\n");
    for(int i = 0; i < tl; i ++) {
      printf("   %d             %d   \n", prd[i], qtd[i]);
    } //for
  } //function
  void busca(int prd[], int qtd[], int tl, int id) {
    int check = 0;
    for(int i = 0; i < tl; i++) {
      if(prd[i] == id) {
        printf("PRODUTO: %d\n", prd[i]);
        printf("EM ESTOQUE: %d\n", qtd[i]);
        check = 1;
      } //if
    } //for
    if(check == 0) {
      printf("O PRODUTO PROCURADO NAO ESTA REGISTRADO.\n");
    } //if
  } //function
  void estoque(int prd[], int qtd[], int tl) {
    int cont = 0;
    for(int i = 0; i < tl; i++) {
      if(qtd[i] == 0) {
        printf("PRODUTO %d NAO ESTA MAIS EM ESTOQUE. FAVOR RENOVAR.\n", prd[i]);
        cont++;
      } //if
    } //for
    if(cont == 0) {
      printf("NAO HA FALTA DE PRODUTOS.\n");
    } //if
  } //function
  void venda(int prd[], int qtd[], int tl, int id, int qt) {
    for(int i = 0; i < tl; i++) {
      if(prd[i] == id) {
        if(qtd[i] >= qt) {
          qtd[i] -= qt;
          printf("FORAM VENDIDAS %d UNIDADES DO PRODUTO %d.\n", qt, prd[i]);
          printf("RESTAM %d UNIDADES DO PRODUTO %d EM ESTOQUE.\n", qtd[i], prd[i]);
        } else {
          printf("NAO HA PRODUTOS O SUFICIENTE PARA EFETUAR ESTA VENDA.\n");
        } //if
      } //if
    } //for
  } //function
  int main() {
    int menu = 999, prd[tf], qtd[tf], tl, id, qt;

    while(menu != 0) {
      printf("MENU\n");
      printf("1 - Inserir produtos.\n");
      printf("2 - Mostrar todo o inventario.\n");
      printf("3 - Procurar por um item especifico.\n");
      printf("4 - Procurar produtos que nao estao disponiveis (0 itens no inventario).\n");
      printf("5 - Realizar venda.\n");
      printf("0 - Sair.\n");
      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch (menu) {
        case 1:
          printf("Quantos produtos serao adicionados? ");
          scanf("%d", &tl);
          insere(prd, qtd, tl);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 2:
          exibe(prd, qtd, tl);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 3:
          printf("BUSCA ESPECIFICA\n");
          printf("ID do produto: ");
          scanf("%d", &id);
          busca(prd, qtd, tl, id);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 4:
          printf("PRODUTOS EM FALTA\n");
          estoque(prd, qtd, tl);
          system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
          system("clear");
        break;
        case 5:
        printf("ID do produto: ");
        scanf("%d", &id);
        printf("Quantidade vendida: ");
        scanf("%d", &qt);
        venda(prd, qtd, tl, id, qt);
        system("read -n1 -r -p 'Pressione qualquer tecla para continuar...' key");
        system("clear");
        break;
      } //switch
    } //while
  } //main
