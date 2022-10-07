#include <stdio.h>
#define tf 100

typedef struct
{
	int chave, count;
} elemento;

typedef struct
{
	int n;
	elemento v[tf];
} lista;

void iniciar(lista *a);
void exibir(lista *a);
int removerTudo(lista *a);
int inserirInicio(lista *a, elemento c);
int inserirFim(lista *a, elemento c);
int inserirOrdenado(lista *a, elemento c);
int remover(lista *a, elemento c);
int listaVazia(const lista *a);
int listaCheia(const lista *a);
int ordenadoCrescente(lista *a);
int ordenadoDecrescente(lista *a);
void copia(lista *a, lista *b);
int removerIndice(lista *a, int k);
int copiaNaoRepetidos(lista *a, lista *b);
void inverter(lista *a, lista *b);
void intercala(lista *a, lista *b, lista *c);
void contElem(lista *a, lista *b);
void exibirCont(lista *a);
int contarMaior(lista *a);
int contarMenor(lista *a);

