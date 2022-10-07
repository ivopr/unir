#include <bits/stdc++.h>
#define tf 52
#define tfp 26

typedef struct
{
	char status;
	int overflow;
	char chave[30];
} tabela;

class enderecamentoEncadeado
{
	public:
	tabela um[tf];
	enderecamentoEncadeado()
	{
		for(int i = 0; i < tf; i++)
		{
			um[i].status = 'L';
			um[i].overflow = -1;
		}
	}

	int hash(char chave[30]);
	int hashOverflow(char chave[30]);
	int inserir(char chave[30]);
	int buscaNome(char chave[30]);
	int buscaLetra(char chave);
	int removerNome(char chave[30]);
};
