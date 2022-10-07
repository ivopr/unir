#include "grafo.h"

int criarGrafo(listaAdj* g, int vertices)
{
	g->N = vertices;
	g->L = (no**)malloc(g->N * sizeof(no*));
	if (g->L == NULL)
		return 0;
	for (int i = 0; i < g->N; i++)
		g->L[i] = NULL;
	return 1;
}

int grafoVazio(listaAdj* g)
{
	return !g->N;
}

int verticeValido(listaAdj* g, int v)
{
	if (v >= g->N || v < 0)
		return 0;
	return 1;
}

int inserirAresta(listaAdj* g, int v1, int v2)
{
	if (checaAresta(g, v1, v2)) return 0;
	no* p = (no*)malloc(sizeof(no));
	if (p == NULL) return 0;
	p->vertice = v2;
	p->prox = g->L[v1];
	g->L[v1] = p;


	p = (no*)malloc(sizeof(no));
	if (p == NULL) return 0;
	p->vertice = v1;
	p->prox = g->L[v2];
	g->L[v2] = p;

	return 1;
}

int removerAresta(listaAdj* g, int v1, int v2)
{
	if (!checaAresta(g, v1, v2)) return 0;

	/**
	 * v1 -> v2
	 */
	no* p = g->L[v1];
	no* q = NULL;
	while (p && p->vertice != v2)
	{
		q = p;
		p = p->prox;
	}

	if (q == NULL)
		g->L[v1]->prox = p->prox;
	else
		q->prox = p->prox;
	free(p);

	/**
	 * v2 -> v1
	 */
	p = g->L[v2];
	q = NULL;
	while (p && p->vertice != v1)
	{
		q = p;
		p = p->prox;
	}

	if (q == NULL)
		g->L[v2]->prox = p->prox;
	else
		q->prox = p->prox;
	free(p);

	return 1;
}

int checaAresta(listaAdj* g, int v1, int v2)
{
	if (grafoVazio(g)) return 0;
	if (!verticeValido(g, v1) || !verticeValido(g, v2)) return 0;
	if (g->L[v1] == NULL) return 0;
	no* p = g->L[v1];
	while (p && p->vertice != v2)
		p = p->prox;
	if (p == NULL) return 0;
	return 1;
}

int verticesAdj(listaAdj* g, int v)
{
	int cont = 0;
	no* p = g->L[v];
	while (p)
	{
		cont++;
		p = p->prox;
	}
	return 0;
}


void criarGrafoVazio(listaAdj* g)
{
	g->N = 0;
}

void verticesAdjacentes(listaAdj* g, int v)
{
	no* p = g->L[v];
	while (p)
	{
		printf("%d, ", p->vertice);
		p = p->prox;
	}
}

void exibeGrafo(listaAdj* g)
{
	no* p;
	if (grafoVazio(g))
		printf("Grafo vazio.\n");
	else 
	{
		for (int i = 0; i < g->N; i++)
		{
			printf("\n%d -> ", i);
			p = g->L[i];
			while (p)
			{
				printf("%d, ", p->vertice);
				p = p->prox;
			}
		}
	}

}

void destruirGrafo(listaAdj* g)
{
	no* p, * q;
	if (grafoVazio(g)) return;
	for (int i = 0; i < g->N; i++)
	{
		p = g->L[i];
		while (p)
		{
			q = p;
			p = p->prox;
			free(q);
		}
	}
}
