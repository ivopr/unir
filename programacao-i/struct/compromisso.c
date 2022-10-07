#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 100

  typedef struct {
    int hora, minuto, segundo;
  } horario;

  typedef struct {
    int dia, mes, ano;
  } data;

  typedef struct {
    data d;
    horario h;
    char desc[tf];
    int tl;
  } compromisso;

  void inserir(compromisso comp[tf]) {
    printf("quantos compromissos? ");
    scanf("%d", &comp->tl);
    for(int i = 0; i < comp->tl; i++) {
      system("cls");
      printf("COMPROMISSO %.3d\n", i);
      printf("descrição: ");
      fflush(stdin);
      fgets(comp[i].desc, tf, stdin);
      printf("data: ");
      scanf("%d %d %d", &comp[i].d.dia, &comp[i].d.mes, &comp[i].d.ano);
      printf("horario: ");
      scanf("%d %d %d", &comp[i].h.hora, &comp[i].h.minuto, &comp[i].h.segundo);
      system("cls");
    }//for
  }//função

  void exibir(compromisso comp[tf]) {
    for(int i = 0; i < comp->tl; i++) {
      system("cls");
      printf("COMPROMISSO %.3d\n", i);
      printf("descrição: %s", comp[i].desc);
      printf("data: %.2d/%.2d/%d\n", comp[i].d.dia, comp[i].d.mes, comp[i].d.ano);
      printf("hora: %.2d:%.2d:%.2d\n", comp[i].h.hora, comp[i].h.minuto, comp[i].h.segundo);
      system("pause");
      system("cls");
    }//for
  }//função

  int main() {
    int menu = 999;
    compromisso comp[tf];

    while (menu != 0) {
      printf("1 - Adicionar compromisso\n");
      printf("2 - Exibir compromissos\n");
      printf("0 - Sair\n");

      printf("\nMENU: ");
      scanf("%d", &menu);

      switch (menu) {
        case 1:
          inserir(comp);
        break;
        case 2:
          exibir(comp);
        break;
      }//switch
    }//while
  }//principal
