#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
	int vertice;
	struct No* prox;
} no;

typedef struct
{
	no** L;
	int N;
} listaAdj;

int criarGrafo(listaAdj* g, int vertices);
int grafoVazio(listaAdj* g);
int verticeValido(listaAdj* g, int v);
int inserirAresta(listaAdj* g, int v1, int v2);
int removerAresta(listaAdj* g, int v1, int v2);
int checaAresta(listaAdj* g, int v1, int v2);
int verticesAdj(listaAdj* g, int v);
void criarGrafoVazio(listaAdj* g);
void verticesAdjacentes(listaAdj* g, int v);
void exibeGrafo(listaAdj* g);
void destruirGrafo(listaAdj* g);