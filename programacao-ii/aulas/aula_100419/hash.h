#include <bits/stdc++.h>
#define tf 8

typedef struct
{
	char status;
	int chave;
} tabela;

class enderecamentoAberto
{
	tabela um[tf];
	enderecamentoAberto()
	{
		for(int i = 0; i < tf; i++)
		um[i].status = 'L';
	}
	int hash(int chave);
	int hashAuxiliar(int chave, int endereco);
	int tabelaCheia();
	int tabelaVazia();
	int busca(int chave);
	int inserir(int chave);
	int remover(int chave);
	void exibir();
};