#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int chave, posDado;
}parTab;

typedef struct
{
	int numero, minimo, estoque;
	char espec[50];

}material;

class indexado
{
	public:
		parTab tabela[50];
		int tl;
		indexado();
		void criaTabela();
		void inserir();
		void relatorioOrdenado();
		void relatorioDesordenado();
		void consulta();
		int buscaBinaria(int num);
};