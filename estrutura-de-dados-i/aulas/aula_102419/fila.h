#include <stdio.h>
#define MAX 5

typedef struct
{
  int chave;
} elemento;

typedef struct
{
  elemento M[MAX];
  int inicio, fim;
} Fila;

void iniciarFila(Fila *F);
int filaVazia(Fila *F);
int filaCheia(Fila *F);
int inserir(Fila *F, elemento v);
int remover(Fila *F);
int tamanho(Fila *F);
elemento comecoDaFila(Fila *F);
void parar();
void limpar();
