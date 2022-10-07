#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int chave;
} dado;

typedef struct NO
{
	dado info;
	struct NO *prox;
} no;

typedef struct
{
	no *head;
} lista;

void iniciar(lista *L);
void exibir(lista *L);
void copia(lista *L, lista *L1);
void inverter(lista *L, lista *L1);
void intercala(lista *L, lista *L1, lista *L2);
void contElem(lista *L, lista *L1);
void exibirCont(lista *L);
int removerTudo(lista *L);
int inserirInicio(lista *L, dado c);
int inserirApos(lista *L, no *k, dado c);
int inserirOrdenado(lista *L, dado c);
int remover(lista *L, dado c);
int listaVazia(lista *L);
int ordenadoCrescente(lista *L);
int ordenadoDecrescente(lista *L);
int removerIndice(lista *L, int k);
int copiaNaoRepetidos(lista *L, lista *b);
int contarMaior(lista *L);
int contarMenor(lista *L);
no *busca(lista *L, dado c);