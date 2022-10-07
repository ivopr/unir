#include "arvere.h"
#include <cstdlib>
#include <iostream>

arvere::arvere()
{
	arvore = NULL;
}

bool arvere::vazia()
{
	return !arvore;
}

void arvere::destruirAux(raiz* ar)
{
	if (ar != NULL)
	{
		destruirAux(ar->esq);
		destruirAux(ar->dir);
		free(ar);
	}
}

void arvere::destruir()
{
	destruirAux(arvore);
}

raiz* arvere::buscaAux(raiz* ar, int chave)
{
	if (ar == NULL)
		return NULL;
	if (ar->info.chave == chave)
		return ar;
	if (ar->info.chave > chave)
		return buscaAux(ar->esq, chave);
	return buscaAux(ar->dir, chave);
}

raiz* arvere::busca(int chave)
{
	if (vazia()) return NULL;
	return buscaAux(arvore, chave);
}

bool arvere::inserirAux(raiz* ar, int chave)
{
	if (ar == NULL)
	{
		raiz* p = (raiz*)malloc(sizeof(raiz));
		if (p == NULL) return false;
		p->info.chave = chave;
		p->esq = NULL;
		p->dir = NULL;
		ar = p;
		return true;
	}
	else if (ar->info.chave > chave)
		return inserirAux(ar->dir, chave);
	else
		return inserirAux(ar->esq, chave);
	return false;
}

bool arvere::inserir(int chave)
{
	if (busca(chave) != NULL) return false;
	if (inserirAux(arvore, chave))
		return true;
	return false;
}

raiz* buscaMenorDosMaiores(raiz* ar)
{
	while (ar != NULL)
		ar = ar->esq;
	return ar;
}

bool arvere::remover(int chave)
{
	raiz* ar = busca(chave);
	if (ar != NULL)
	{
		if (ar->esq == arvore->dir == NULL)
		{
			ar = NULL;
			return true;
		}
		else if (ar->dir == NULL)
		{
			ar = ar->esq;
			return true;
		}
		else if (ar->esq == NULL)
		{
			ar = ar->dir;
			return true;
		}
		else
		{
			raiz* menor = buscaMenorDosMaiores(ar->dir);
			ar = menor;
			return true;
		}
	}
	return false;
}