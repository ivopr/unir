#include "fila.h"

int main()
{
  int menu;
  elemento v;
  Fila F;
  iniciarFila(&F);

  do
  {
    limpar();
    printf("1 - inserir\n");
    printf("2 - remover\n");
    printf("3 - tamanho\n");
    printf("4 - primeiro item da lista\n");
    printf("0 - sair\n");

    printf("menu> ");
    scanf("%d", &menu);

    switch(menu)
    {
      case 1:
      {
        limpar();
        printf("numero a inserir: ");
        scanf("%d", &v.chave);
        if(inserir(&F, v))
          printf("numero inserido!\n");
        else
          printf("lista cheia! numero nao inserido!\n");
        parar();
      break;
      }

      case 2:
      {
        limpar();
        if(remover(&F))
          printf("primeiro item da fila removido!\n");
        else
          printf("lista vazia! nao foi possivel remover o primeiro item!\n");
        parar();
      break;
      }

      case 3:
      {
        limpar();
        if(!filaVazia(&F))
          printf("o tamanho da lista eh: %d\n", tamanho(&F));
        else
          printf("lista vazia! nao ha itens para contar\n");
        parar();
      break;
      }

      case 4:
      {
        limpar();
        if(!filaVazia(&F))
          printf("o primeiro item da lista eh: %d\n", comecoDaFila(&F).chave);
        else
          printf("lista vazia! nao ha primeiro item!\n");
        parar();
      break;
      }
    }
  } while(menu != 0);
}
