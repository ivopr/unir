#pragma once
constexpr int MAX = 50;
constexpr auto db = "database.dat";
#define cleanbuffer fseek(stdin, 0, SEEK_END);

typedef struct
{
	int codigo, qtdAtual, qtdMin;
	char desc[MAX];
}p;

typedef struct
{
	int chave, posDado;
}parTab;

class lolja
{
	public:
		int tlIndice;
		p produto[MAX];
		parTab indice[MAX];
		lolja();
		int buscaBinaria(int codigo);
		int particao(int inicio, int fim);
		p leMaterial();
		void consulta(int codigo);
		void exibeProduto(p prod);
		void exibeIndice();
		void exibeOrdenado();
		void exibeDesordenado();
		void iniciaIndice();
		void inserirProduto();
		void quickSort(int inicio, int fim);
		void troca(parTab* m, parTab* m1);
};