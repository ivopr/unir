#include "listaEncadeada.cpp"

int main()
{
  int menu;
  lista um;
  elemento c;

  do
  {
    limpar();
    printf("1 - iniciar listas\n");
    printf("2 - exibir\n");
    printf("3 - inserir no inicio\n");
    printf("4 - inserir no fim\n");
    printf("5 - inserir ordenado\n");
    printf("6 - remover\n");
    printf("0 - sair\n");

    printf("menu> ");
    scanf("%d", &menu);

    switch(menu)
    {
      case 1:
      {
        iniciar(&um);
      break;
      }

      case 2:
      {
        exibir(&um);
        parar();
      break;
      }

      case 3:
      {
        limpar();
        printf("numero a ser inserido: ");
        scanf("%d", &c.chave);
        inserirInicio(&um, c);
      break;
      }

      case 4:
      {
        limpar();
        printf("numero a ser inserido: ");
        scanf("%d", &c.chave);
        inserirFim(&um, c);
      break;
      }

      case 5:
      {
        limpar();
        printf("numero a ser inserido: ");
        scanf("%d", &c.chave);
        inserirOrdenado(&um, c);
      break;
      }

      case 6:
      {
        limpar();
        printf("numero a ser removido: ");
        scanf("%d", &c.chave);
        remover(&um, c.chave);
      break;
      }
    }
  } while (menu != 0);
  return 0;
}