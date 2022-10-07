#pragma once
#include <stdio.h>
#include <stdlib.h>
/**
 * Grafo não direcionado
 */
typedef struct
{
	int** M, N;
} matrizAdj;

int criarGrafo(matrizAdj* g, int vertices);
int criarGrafoVazio(matrizAdj* g);
int grafoVazio(matrizAdj* g);
int inserirAresta(matrizAdj* g, int v1, int v2);
int removerAresta(matrizAdj* g, int v1, int v2);
int checaAresta(matrizAdj* g, int v1, int v2);
int verticesAdj(matrizAdj* g, int v);
void verticesAdjacentes(matrizAdj* g, int v);
void exibeGrafo(matrizAdj* g);
void destruirGrafo(matrizAdj* g);
