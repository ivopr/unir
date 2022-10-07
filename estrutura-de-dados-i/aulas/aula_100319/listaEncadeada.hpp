#include <stdio.h>
#include <iostream>
#define MAX 100

typedef struct
{
  int chave;
} elemento;

typedef struct
{
  elemento info;
  int proximo;
} no;

typedef struct
{
  int inicio, inicioDisponivel;
  no vetor[MAX];
} lista;

void iniciar(lista *a);
void destruir(lista *a);
void exibir(lista *a);
void copia(lista *a, lista *b);
void inverter(lista *a, lista *b);
void intercala(lista *a, lista *b, lista *c);
void contElem(lista *a, lista *b);
void exibirCont(lista *a);
int inserirInicio(lista *a, elemento c);
int inserirFim(lista *a, elemento c);
int inserirApos(lista *a, int k, elemento c);
int inserirOrdenado(lista *a, elemento c);
int removerInicio(lista *a);
void removerApos(lista *a, int k);
int listaVazia(const lista *a);
int listaCheia(const lista *a);
int ordenadoCrescente(lista *a);
int ordenadoDecrescente(lista *a);
int removerIndice(lista *a, int k);
int copiaNaoRepetidos(lista *a, lista *b);
int contarMaior(lista *a);
int contarMenor(lista *a);