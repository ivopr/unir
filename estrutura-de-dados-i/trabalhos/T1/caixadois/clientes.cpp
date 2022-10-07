#include "stdafx.h"

/* DEPÓSITO */
bool deposito(lista, cc* destino, float valor)
{
	if (valor < 0) return false;
	t nova;
	nova.codigo = gerarCodigoTransacao(cliente);
	snprintf(nova.destino, sizeof(nova.destino), "%s", destino->numero);
	snprintf(nova.origem, sizeof(nova.origem), "%s", "NULL");
	nova.tipo = 'D';
	nova.valor = valor;
	if (push(NULL, &destino->topo, NULL, destino->transacao, nova) == true)
	{
		destino->saldo += valor;
		return true;
	}
	return false;
} // DEPÓSITO

  /* SAQUE */
bool saque(lista, cc* origem, float valor)
{
	if (valor < 0) return false;
	if (origem->saldo < valor) return false;
	t nova;
	nova.codigo = gerarCodigoTransacao(cliente);
	snprintf(nova.origem, sizeof(nova.origem), "%s", origem->numero);
	snprintf(nova.destino, sizeof(nova.destino), "%s", "NULL");
	nova.tipo = 'S';
	nova.valor = valor;
	if (push(&origem->topo, NULL, origem->transacao, NULL, nova) == true)
	{
		origem->saldo -= valor;
		return true;
	}
	return false;
} // SAQUE

  /* TRANSFERÊNCIA */
bool transferencia(lista, cc* origem, cc* destino, float valor)
{
	if (valor < 0) return false;
	if (origem->saldo < valor) return false;
	t nova;
	nova.codigo = gerarCodigoTransacao(cliente);
	snprintf(nova.origem, sizeof(nova.origem), "%s", origem->numero);
	snprintf(nova.destino, sizeof(nova.destino), "%s", destino->numero);
	nova.tipo = 'T';
	nova.valor = valor;
	if (push(&origem->topo, &destino->topo, origem->transacao, destino->transacao, nova) == true)
	{
		origem->saldo -= valor;
		destino->saldo += valor;
		return true;
	}
	return false;
} // TRANSFERÊNCIA

  /* GERA UMA CONTA CORRENTE NOVA */
cc gerarContaCliente(lista)
{
	cc nova;
	time_t t;
	do
	{
		srand((unsigned int)time(&t));
		for (int i = 0; i < 4; i++)
			nova.numero[i] = 0x30 | rand() % 9;
		nova.numero[4] = '\0';
	} while (contaExiste(cliente, nova.numero) == true);
	return nova;
} // GERAR CONTA CORRENTE

  /* VERIFICA SE EXISTE UMA CONTA CORRENTE COM O CODIGO FORNECIDO */
bool contaExiste(lista, char* numero)
{
	for (int i = 0; i < MAX; i++)
		if (strcmp(cliente[i].conta.numero, numero) == 0)
			return true;
	return false;
} // VERIFICAR EXISTENCIA DE CONTA CORRENTE

  /* CRIA, ADICIONA E ORDENA UM CLIENTE */
bool adicionarCliente(lista)
{
	c novo;
	float valor;
	if (posLivre(cliente) == -1)
		return false;
	novo.codigo = gerarCodigoCliente(cliente);
	printf("nome: ");
	cleanbuffer;
	fgets(novo.nome, 50, stdin);
	printf("telefone: ");
	cleanbuffer;
	fgets(novo.telefone, 20, stdin);
	novo.conta = gerarContaCliente(cliente);
	printf("primeiro deposito (acima de R$50 para efetivar a conta, abaixo de R$0 para cancelar a operação):\n");
	printf("R$");
	scanf_s("%f", &valor);
	while (valor < 50)
	{
		printf("o valor inserido eh menor que R$50. tente novamente:\nR$");
		scanf_s("%f", &valor);
		if (valor < 0)
			break;
	}
	if (posLivre(cliente) == -1)
		return false;
	if (deposito(cliente, &novo.conta, valor) == true)
	{
		cliente[posLivre(cliente)] = novo;
		quickSort(cliente, 0, posLivre(cliente) - 1);
		return true;
	}
	return false;
} // ADIÇÃO DE CLIENTE

  /* GERA ALEATÓRIAMENTE UM CÓDIGO DE CLIENTE E O RETORNA */
int gerarCodigoCliente(lista)
{
	int codigo;
	time_t t;
	do
	{
		srand((unsigned int)time(&t));
		codigo = 100 + rand() % 100;
	} while (clienteExiste(cliente, codigo) == true);
	return codigo;
} // GERAÇÃO DE CÓDIGO DE CLIENTE

  /* VERIFICA SE HÁ ESPAÇOS VAZIOS NA LISTA. RETORNA -1 SE A LISTA ESTIVER CHEIA, CASO CONTRARIO RETORNA O PRIMEIRO INDICE LIVRE */
int posLivre(lista)
{
	for (int i = 0; i < MAX; i++)
		if (cliente[i].codigo == 0)
			return i;
	return -1;
} // RETORNA INDICE LIVRE

  /* VERIFICA SE HÁ UM CLIENTE COM O CÓDIGO FORNECIDO NA LISTA */
bool clienteExiste(lista, int codigo)
{
	for (int i = 0; i < MAX; i++)
		if (cliente[i].codigo == codigo)
			return true;
	return false;
} // VERIFICA CLIENTE EXISTE

  /* REMOVE UM CLIENTE E ORDENA A LISTA */
bool removerCliente(lista, int codigo)
{
	c novo;
	for (int i = 0; i < MAX; i++)
	{
		if (cliente[i].codigo == codigo)
		{
			if (i == 0)
			{
				cliente[i] = novo;
				return true;
			}
			else
			{
				int j = i;
				do
				{
					cliente[j] = cliente[j + 1];
					j++;
				} while (cliente[j].codigo != 0);
				cliente[j] = novo;
				quickSort(cliente, 0, posLivre(cliente) - 1);
				return true;
			}
		}
	}

	return false;
} // REMOVER CLIENTE

  /* TROCA DOIS CLIENTES DE POSIÇÃO */
void troca(c* x, c* y)
{
	c aux = *x;
	*x = *y;
	*y = aux;
} // TROCA DE POSIÇÃO

  /* ORDENA UMA PARTE DA LISTA DE CLIENTES */
int particao(lista, int inicio, int fim)
{
	int pivo = cliente[fim].codigo;
	int i = inicio - 1;

	for (int j = inicio; j <= fim - 1; j++)
	{
		if (cliente[j].codigo < pivo)
		{
			i = i + 1;
			troca(&cliente[i], &cliente[j]);
		}
	}
	troca(&cliente[i + 1], &cliente[fim]);
	return i + 1;
} // PARTICIONAMENTO

  /* INVOCA A ORDENAÇÃO NAS DUAS PARTES DA TABELA */
void quickSort(lista, int inicio, int fim)
{
	if (inicio < fim)
	{
		int pivo = particao(cliente, inicio, fim);

		quickSort(cliente, inicio, pivo - 1);
		quickSort(cliente, pivo + 1, fim);
	}
} // ORDEM E PROGRESSO (??)

  /* RETORNA O ENDEREÇO DE UM CLIENTE */
c* retornaCliente(lista, int codigo)
{
	c* novo = new c;
	for (int i = 0; i < MAX; i++)
		if (cliente[i].codigo == codigo)
			return &cliente[i];
	return novo;
} // RETORNA CLIENTE

  /* ATUALIZA OS DADOS DE UM CLIENTE COM BASE NA ESCOLHA DELE */
void atualizarCliente(lista, c* base)
{
	char opcao;
	printf("o nome cadastrado do cliente eh: %s", base->nome);
	printf("pressione S para alterar. qualquer outra tecla para pular: ");
	cleanbuffer;
	scanf_s("%c", &opcao, (unsigned int)sizeof(char));
	if (opcao == 'S' || opcao == 's')
	{
		printf("insira o novo nome: ");
		cleanbuffer;
		fgets(base->nome, 50, stdin);
	}
	printf("o telefone cadastrado do cliente eh: %s", base->telefone);
	printf("pressione S para alterar. qualquer outra tecla para pular: ");
	cleanbuffer;
	scanf_s("%c", &opcao, (unsigned int)sizeof(char));
	if (opcao == 'S' || opcao == 's')
	{
		printf("insira o novo telefone: ");
		cleanbuffer;
		fgets(base->telefone, 20, stdin);
	}
} // ATUALIZAÇÃO DE DADOS

  /* IMPRIME NA TELA TODOS OS CLIENTES COM SUAS INFORMAÇÕES */
void exibeTodosClientes(lista)
{
	int i;
	printf("exibe todos os clientes\n");
	for (i = 0; i < MAX; i++)
	{
		if (cliente[i].codigo != 0)
		{
			printf("\ndados cliente\n");
			printf("codigo: %d\n", cliente[i].codigo);
			printf("nome: %s", cliente[i].nome);
			printf("telefone: %s", cliente[i].telefone);
			printf("dados conta corrente\n");
			printf("numero: %s\n", cliente[i].conta.numero);
			printf("saldo: R$%.3f\n", cliente[i].conta.saldo);
		}
		else
			break;
	}
	if (i == 0)
		printf("FALHA: nao ha clientes cadastrados\n");
} // EXIBIR LISTA DE CLIENTES

  /* "LIMPA" A TELA */
void limpar()
{
	for (int i = 0; i < 50; i++)
		printf("\n");
}

/* "PAUSA" O PROGRAMA */
void parar()
{
	printf("pressione qualquer tecla para continuar...");
	cleanbuffer;
	char a = getchar();
}

/* "PAUSA" O PROGRAMA EM CASOS ESPECIAIS, VULGO INSERÇÃO DE STRING */
void pararEsp()
{
	printf("pressione qualquer tecla para continuar...");
	char a = getchar();
}