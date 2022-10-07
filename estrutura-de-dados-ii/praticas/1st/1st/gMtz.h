#pragma once
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class gMtz {
	int** mtz;
	int** mtzAux;
	int tpGrf;

	public:
		int ttlVrt;
		// verifica se a aresta v,v1 existe no grafo mtz
		bool arestaExiste (int, int);

		// verifica se a aresta é válida (prim)
		bool arestaValida(int, int, vector<bool>);

		// encerra a matriz
		bool encerraMtz();

		// insere aresta v,v1 no grafo mtz
		bool inserirAresta (int, int, int);

		// preenche o grafo com arestas
		bool popularMtz();

		// verifica se a matriz está vazia
		bool verificaMtzVazia();

		// construtor para fins de fazer esse negocio funcionar
		gMtz();

		// exibe a matriz de adjacência
		void exibirMtz();
		void exibirMtzAux();

		// exibe a distancia
		void exibirDist(vector<int>&);

		// busca em largura
		void bfs(int);

		// busca em profundidade
		void dfs(int);
		void dfsAux(int, vector<bool>&);

		// caminho minimo busca em profundidade
		void bfsCM(int, int);
		void adjacentes(vector<int>&, int);

		// caminho minimo dijkstra
		int minDist(vector<int>&, vector<bool>&);
		void dijkstraCM(int);
		void exibeCaminho(vector<int>&, int);
		void exibeDijkstra(vector<int>&, vector<int>&);

		// caminho minimo floyd
		void exibirMtz(int**);
		void FloydWCM();

		// cria grafo com ttlVrt vertices
		void iniciaMtz(int);

		// arvore geradora minima kruskal
		int encontraSet(vector<int>&, int);
		void kruskalAGM();
		void uniao(vector<int>&, int, int);

		// arvore geradora minima prim
		void primAGM();

		
};

