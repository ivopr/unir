#include "fila.h"

void iniciarFila(Fila *F)
{
    F->inicio = F->fim = 0;
}

int filaVazia(Fila *F)
{
  if(F->inicio == F->fim)
    return 1;
  return 0;
}

int filaCheia(Fila *F)
{
    if((F->fim + 1) % MAX == F->inicio)
      return 1;
    return 0;
}

int inserir(Fila *F, elemento v)
{
  if(filaCheia(F)) return 0;
  F->fim = (F->fim + 1) % MAX;
  F->M[F->fim] = v;
  return 1;
}

int remover(Fila *F)
{
  if(filaVazia(F)) return 0;
  F->inicio = (F->inicio + 1) % MAX;
  return 1;
}

int tamanho(Fila *F)
{
  if(F->fim >= F->inicio) return F->fim - F->inicio;
  return MAX - F->inicio + F->fim;
}

elemento comecoDaFila(Fila *F)
{
  return F->M[(F->inicio + 1) % MAX];
}

void parar()
{
  printf("pressione enter para continuar...");
  fflush(stdin);
  getchar();
}

void limpar()
{
  for(int i = 0; i < 100; i++)
    printf("\n");
}