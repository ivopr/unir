#pragma once
typedef struct
{
	int chave;
}elemento;

typedef struct no
{
	elemento info;
	no* esq;
	no* dir;
}raiz;

class arvere
{
	public:
		raiz* arvore;
		arvere();
		void destruir();
		void destruirAux(raiz* ar);
		bool vazia();
		bool inserirAux(raiz* ar, int chave);
		bool inserir(int chave);
		bool remover(int chave);
		void exibirPreOrdem();
		void exibirInOrdem();
		void exibirPosOrdem();
		void altura();
		raiz* busca(int chave);
		raiz* buscaAux(raiz* ar, int chave);
};
raiz* buscaMenorDosMaiores(raiz* arvore);