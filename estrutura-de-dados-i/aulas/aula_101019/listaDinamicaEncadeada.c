#include "listaDinamicaEncadeada.h"

void iniciar(lista *L)
{
	L->head = NULL;
}

int listaVazia(lista *L)
{
	return L->head == NULL;
}

int inserirInicio(lista *L, dado c)
{
	no *p;
	p = (no *)malloc(sizeof(no));
	if(p == NULL) return 0;
	p->info = c;
	p->prox = L->head;
	L->head = p;
	return 1;
}

int inserirApos(lista *L, no *k, dado c)
{
	no *p = (no *)malloc(sizeof(no));
	if(!p)
		return 0;
	else 
	{
		p->info = c;
		p->prox = k->prox;
		k->prox = p;		
	}
	return 1;
}

int inserirOrdenado(lista *L, dado c)
{
	no *p, *ant;
	if(listaVazia(L)) return inserirInicio(L, c);
	ant = NULL;
	p = L->head;
	while(p && p->info.chave < c.chave)
	{
		ant = p;
		p = p->prox;
	}
	if(ant == NULL)
		return inserirInicio(L, c);
	else
		return inserirApos(L, ant, c);
}

void destruir(lista *L)
{
	no *p = L->head;
	while(p)
	{
		L->head = p->prox;
		free(p);
		p = L->head;
	}
}

int remover(lista *L, dado c)
{
	no *p, *q;
	if(listaVazia(L)) return 0;
	p = L->head;
	q = NULL;
	while(p && p->info.chave < c.chave)
	{
		q = p;
		p = p->prox;
	}
	if(p == NULL)
		return 0;
	if(p->info.chave != c.chave)
		return 0;
	if(q == NULL)
	{
		L->head = p->prox;
	}
	else
	{
		q->prox = p->prox;
		free(p);
	}
	return 1;
}

int tamanho(lista *L)
{
	no *p;
	int cont = 0;
	p = L->head;
	while(p)
	{
		cont++;
		p = p->prox;
	}
	return cont;
}

no *busca(lista *L, dado c)
{
	no *p = L->head;
	while(p && p->info.chave < c.chave)
	{
		p = p->prox;
	}
	if(p == NULL)
		return p;
	if(p->info.chave == c.chave)
		return p;
	return NULL;
}

int tamanhoRecursivo(no *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + tamanhoRecursivo(p->prox);
}

int tamanhoRecursivoInit(lista *L)
{
	return tamanhoRecursivo(L->head);
}

int inserirRecursivoInit(lista *L, dado c)
{
	if(L->head == NULL)
	{
		inserirInicio(L, c);
		return 1;
	}
	no *p = L->head;
	no *q = NULL;
	return inserirRecursivo(L, p, q, &c);
}

int inserirRecursivo(lista *L, no *p, no *q, dado *c)
{
	if(p == NULL)
	{
		inserirApos(L, q, *c);
		return 1;
	}

	if(p->info.chave == c->chave)
	{
		if(q == NULL)
			inserirInicio(L, *c);
		else
		{
			inserirApos(L, q, *c);
		}
		return 1;
	}
	return inserirRecursivo(L, p->prox, p, c);
}

void exibir(lista *L)
{
	if(listaVazia(L)) return 0;
	no *p = L->head;
	while(p)
	{
		printf("%d\n", p->info.chave);
		p = p->prox;
	}
}