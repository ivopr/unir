#include <stdio.h>
#include <stdlib.h>

struct no
{
	int info, altura;
	struct no *esq, *dir;
};

typedef struct no no;

no *inicializadorNo();
int maior(int, int);
int altura(no *);
no *novoNo(int);
no *rotacaoDir(no *);
no *rotacaoEsq(no *);
int balanceamento(no *);
no *inserir(no *, int );
void exibeInOrdem(no *);
void exibePosOrdem(no *);
void exibePreOrdem(no *);
int contagemNos(no *);
int nivelNo(no *, int, int);
void busca(no *, int );
void destruir(no *);
no *remover(no *, int);
no *menorValor(no *);

void cls();
void pause();