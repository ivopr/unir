#include "grafo.h"

int criarGrafo(matrizAdj* g, int vertices)
{
	g->N = vertices;
	g->M = (int**)malloc(g->N * sizeof(int*));
	if (g->M == NULL)
		return 0;
	for (int i = 0; i < g->N; i++)
	{
		g->M[i] = (int*)malloc(g->N * sizeof(int));
		if (g->M[i] == NULL)
			return 0;
	}
	for (int i = 0; i < g->N; i++)
		for (int j = 0; j < g->N; j++)
			g->M[i][j] = 0;
	return 1;
}

int criarGrafoVazio(matrizAdj* g)
{
	g->N = 0;
	return 1;
}

int grafoVazio(matrizAdj* g)
{
	if (g->N == 0)
		return 1;
	return 0;
}

int inserirAresta(matrizAdj* g, int v1, int v2)
{
	if (v1 > g->N || v2 > g->N || v1 < 0 || v2 < 0)
		return 0;
	if (checaAresta(g, v1, v2))
		return 0;
	g->M[v1][v2] = 1;
	g->M[v2][v1] = 1;
	return 1;
}

int removerAresta(matrizAdj* g, int v1, int v2)
{
	if (grafoVazio(g))
		return 0;
	if (v1 > g->N || v2 > g->N || v1 < 0 || v2 < 0)
		return 0;
	if (!checaAresta(g, v1, v2))
		return 0;
	g->M[v1][v2] = 0;
	g->M[v2][v1] = 0;
	return 1;
}

int checaAresta(matrizAdj* g, int v1, int v2)
{
	return g->M[v1][v2];
}

void verticesAdjacentes(matrizAdj* g, int v)
{
	if (grafoVazio(g))
		return;
	if (v < 0 || v > g->N)
		return;
	for (int i = 0; i < g->N; i++)
		if (g->M[v][i] == 1)
			printf("v%d, ", i);
}

int verticesAdj(matrizAdj* g, int v)
{
	if (grafoVazio(g))
		return 0;
	int cont = 0;
	if (v < 0 || v > g->N)
		return 0;
	for (int i = 0; i < g->N; i++)
		if (g->M[v][i] == 1)
			cont++;
	return cont;
}

void exibeGrafo(matrizAdj* g)
{
	if (grafoVazio(g))
		return;
	for (int i = 0; i < g->N; i++)
	{
		printf("\n");
		for (int j = 0; j < g->N; j++)
			printf("%d\t", g->M[i][j]);
	}
}

void destruirGrafo(matrizAdj* g)
{
	if (grafoVazio(g))
		return;
	for (int i = 0; i < g->N; i++)
	{
		free(g->M[i]);
	}
	free(g->M);
}
