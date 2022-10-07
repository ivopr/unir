#include "hash.h"

int enderecamentoAberto::tabelaCheia()
{
	for(int i = 0; i < tf; i++)
	{
		if(um[i].status != 'O')
		{
			return 0;
		}
	}
	return 1;
}

int enderecamentoAberto::tabelaVazia()
{
	for(int i = 0; i < tf; i++)
	{
		if(um[i].status != 'L')
		{
			return 0;
		}
	}
	return 1;
}

int enderecamentoAberto::busca(int chave)
{

}

int enderecamentoAberto::hash(int chave)
{
	int endereco = 0;
	endereco = chave % tf;
	if(um[endereco].status == 'O')
		endereco = hashAuxiliar(chave, endereco);
	return endereco;
}

int enderecamentoAberto::hashAuxiliar(int chave, int endereco)
{
	int i;
	for(i = endereco; i < tf; i++)
	{
		if(um[i].status != 'O')
			endereco = i;
	}
	if(i == tf)
	{
		for(int j = 0; j < endereco; j++)
		{
			if(um[j].status != 'O')
				endereco = i;
		}
	}
	return endereco;
}

int enderecamentoAberto::inserir(int chave)
{
	if(tabelaCheia()) return 0;
	int endereco = hash(chave);
	um[endereco].status = 'O';
	um[endereco].chave = chave;
	return 1;
}

int enderecamentoAberto::remover(int chave)
{
	if(tabelaVazia()) return 0;
	int endereco = busca(chave);
	um[endereco].status = 'R';
	return 1;
}

void enderecamentoAberto::exibir()
{

}

void limpar()
{

}