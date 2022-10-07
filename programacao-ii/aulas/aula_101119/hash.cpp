#include "hash.h"

int enderecamentoEncadeado::hash(char chave[30])
{
	if(um[chave[0] % tfp].status != 'O')
		return chave[0] % tfp;
	else
		return hashOverflow(chave);
}

int enderecamentoEncadeado::hashOverflow(char chave[30])
{
	for(int i = tfp; i < tf; i++)
	{
		
	}
}

int enderecamentoEncadeado::inserir(char chave[30])
{
	int endereco = hash(chave);
	if(um[endereco].status != 'O')
	{
		um[endereco].status = 'O';
		um[endereco].chave[30] = chave[30];
		return 1;
	}
	else
	{
		return 1;
	}
	return 0;
}

int enderecamentoEncadeado::hashOverflow(int endereco, char chave[30])
{
	int primeiro = -1;
	for(int i = ('Z' % tfp) + 1; i < tf; i++)
	{
		if(um[i].status == 'O' && um[i].chave[0] == chave[0])
			primeiro = i;
	}
	for(int j = ('Z' % tfp) + 1; j < tf; j++)
	{
		if(um[j].status != 'O' && primeiro == -1)
		{
			um[j].status = 'O';
			um[j].chave[30] = chave[30];
			um[endereco].overflow = j;
			return 1;
		}
		else if(um[j].status != 'O' && primeiro != -1)
		{
			um[j].status = 'O';
			um[j].chave[30] = chave[30];
			um[j].overflow = um[endereco].overflow;
			um[endereco].overflow = j;
			return 1;
		}
	}
	return 0;
}