#include "stdafx.h"

/* EMPILHA UMA TRANSAÇÃO NA LISTA DO(S) CLIENTE(S) */
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

  /* GERA UM CÓDIGO ALEATÓRIO DE TRANSAÇÃO */
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
} // NOVA TRANSAÇÃO

  /* VERIFICA SE O CÓDIGO JÁ É UTILIZADO EM OUTRA TRANSAÇÃO */
bool transacaoExiste(lista, int codigo)
{
	for (int i = 0; i < MAX; i++)
		if (cliente[i].conta.transacao[i].codigo == codigo)
			return true;
	return false;
} // VERIFICA CODIGO

  /* EXIBE TODAS AS LISTAS DE TRANSAÇÃO DOS CLIENTES */
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
} // EXIBE TODAS AS TRANSAÇÕES

  /* EXIBE A LISTA DE TRANSAÇÃO DE UM CLIENTE ESPECÍFICO */
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
} // EXIBE TRANSAÇÕES DE UM CLIENTE