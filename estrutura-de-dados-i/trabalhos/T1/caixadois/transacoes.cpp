#include "stdafx.h"

/* EMPILHA UMA TRANSA��O NA LISTA DO(S) CLIENTE(S) */
bool push(int* topoOrig, int* topoDest, t origem[MAX], t destino[MAX], t nova)
{
	if (nova.tipo == 'D')
	{
		*topoDest = *topoDest + 1;
		destino[*topoDest] = nova;
		return true;
	}
	else if (nova.tipo == 'S')
	{
		*topoOrig = *topoOrig + 1;
		origem[*topoOrig] = nova;
		return true;
	}
	else
	{
		*topoDest = *topoDest + 1;
		destino[*topoDest] = nova;
		*topoOrig = *topoOrig + 1;
		origem[*topoOrig] = nova;
		return true;
	}
	return false;
} // PUSH

  /* GERA UM C�DIGO ALEAT�RIO DE TRANSA��O */
int gerarCodigoTransacao(lista)
{
	int codigo;
	time_t t;
	do
	{
		srand((unsigned int)time(&t));
		codigo = rand() % 5000 + 10000;
	} while (transacaoExiste(cliente, codigo) == true);
	return codigo;
} // NOVA TRANSA��O

  /* VERIFICA SE O C�DIGO J� � UTILIZADO EM OUTRA TRANSA��O */
bool transacaoExiste(lista, int codigo)
{
	for (int i = 0; i < MAX; i++)
		if (cliente[i].conta.transacao[i].codigo == codigo)
			return true;
	return false;
} // VERIFICA CODIGO

  /* EXIBE TODAS AS LISTAS DE TRANSA��O DOS CLIENTES */
void exibeTodasTransacoes(lista)
{
	for (int i = 0; i < MAX; i++)
	{
		if (cliente[i].codigo != 0)
		{
			printf("\ntransacoes cc: %s cliente: %s", cliente[i].conta.numero, cliente[i].nome);
			for (int j = cliente[i].conta.topo; j >= 0; j--)
			{
				if (cliente[i].conta.transacao[j].codigo != 0)
				{
					printf("transacao %d\n", j + 1);
					printf("codigo: %d\n", cliente[i].conta.transacao[j].codigo);
					if (strcmp(cliente[i].conta.transacao[j].origem, "NULL") != 0)
						printf("origem: %s\n", cliente[i].conta.transacao[j].origem);
					if (strcmp(cliente[i].conta.transacao[j].destino, "NULL") != 0)
						printf("destino: %s\n", cliente[i].conta.transacao[j].destino);
					printf("tipo: %c\n", cliente[i].conta.transacao[j].tipo);
					printf("valor: R$%.3f\n", cliente[i].conta.transacao[j].valor);
				}
			}
		}
	}
} // EXIBE TODAS AS TRANSA��ES

  /* EXIBE A LISTA DE TRANSA��O DE UM CLIENTE ESPEC�FICO */
void exibeTransacaoCliente(cc conta)
{
	int i;
	for (i = conta.topo; i >= 0; i--)
	{
		if (conta.transacao[i].codigo != 0)
		{
			printf("transacao %d\n", i + 1);
			printf("codigo: %d\n", conta.transacao[i].codigo);
			if (strcmp(conta.transacao[i].origem, "NULL") != 0)
				printf("origem: %s\n", conta.transacao[i].origem);
			if (strcmp(conta.transacao[i].destino, "NULL") != 0)
				printf("destino: %s\n", conta.transacao[i].destino);
			printf("tipo: %c\n", conta.transacao[i].tipo);
			printf("valor: R$%.3f\n", conta.transacao[i].valor);
		}
	}
} // EXIBE TRANSA��ES DE UM CLIENTE