// caixadois.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	system("title caixa dois ponto exe");
	int menu;
	lista;
	do
	{
		limpar();
		printf("1 - cliente\n2 - transacao\n0 - sair\nmenu> ");
		scanf_s("%d", &menu);

		switch (menu)
		{
		case 1:
		{
			c* atual;
			int menu1, codigo;
			do
			{
				limpar();
				printf("1 - inserir novo cliente\n2 - consultar dados de um cliente\n3 - atualizar cadastro de um cliente\n4 - remover um cliente\n5 - imprimir lista de clientes\n0 - voltar\nmenu> ");
				scanf_s("%d", &menu1);

				switch (menu1)
				{
				case 1:
				{
					limpar();
					if (adicionarCliente(cliente))
						printf("SUCESSO: cliente adicionado\n");
					else
						printf("FALHA: nao foi possivel adicionar o cliente\n");
					parar();
					break;
				}

				case 2:
				{
					limpar();
					printf("insira o codigo do cliente: ");
					scanf_s("%d", &codigo);
					atual = retornaCliente(cliente, codigo);
					if (atual->codigo != 0)
					{
						printf("dados cliente\n");
						printf("codigo: %d\n", atual->codigo);
						printf("nome: %s", atual->nome);
						printf("telefone: %s", atual->telefone);
						printf("dados conta corrente\n");
						printf("numero: %s\n", atual->conta.numero);
						printf("saldo: %.3f\n", atual->conta.saldo);
						printf("------------\n transacoes \n------------\n");
						exibeTransacaoCliente(atual->conta);
					}
					else
						printf("FALHA: nao ha cliente com este codigo\n");
					parar();
					break;
				}

				case 3:
				{
					limpar();
					printf("insira o codigo do cliente: ");
					scanf_s("%d", &codigo);
					atualizarCliente(cliente, retornaCliente(cliente, codigo));
					printf("cliente atualizado!\n");
					parar();
					break;
				}

				case 4:
				{
					limpar();
					printf("insira o codigo do cliente: ");
					scanf_s("%d", &codigo);
					if (removerCliente(cliente, codigo))
						printf("SUCESSO: cliente removido\n");
					else
						printf("FALHA: nao ha cliente com este codigo\n");
					parar();
					break;
				}

				case 5:
				{
					limpar();
					exibeTodosClientes(cliente);
					parar();
					break;
				}
				}
			} while (menu1 != 0);
			break;
		}

		case 2:
		{
			int menu2, origem, destino;
			float valor;
			do
			{
				limpar();
				printf("1 - deposito\n2 - saque\n3 - transferencia\n4 - exibir lista de transacoes\n0 - voltar\nmenu> ");
				scanf_s("%d", &menu2);

				switch (menu2)
				{
				case 1:
				{
					limpar();
					printf("insira o codigo do cliente beneficiario: ");
					scanf_s("%d", &destino);
					if (clienteExiste(cliente, destino))
					{
						printf("valor a ser depositado: R$");
						scanf_s("%f", &valor);
						if (deposito(cliente, &retornaCliente(cliente, destino)->conta, valor))
							printf("SUCESSO: deposito concluido\n");
						else
							printf("FALHA: nao foi possivel concluir o deposito\n");
					}
					else
						printf("FALHA: nao ha cliente com esse codigo\n");
					parar();
					break;
				}

				case 2:
				{
					limpar();
					printf("insira o codigo do cliente sacado: ");
					scanf_s("%d", &origem);
					if (clienteExiste(cliente, origem))
					{
						printf("valor a ser sacado: R$");
						scanf_s("%f", &valor);
						if (saque(cliente, &retornaCliente(cliente, origem)->conta, valor))
							printf("SUCESSO: saque concluido\n");
						else
							printf("FALHA: nao foi possivel concluir o saque\n");
					}
					else
						printf("FALHA: nao ha cliente com esse codigo\n");
					parar();
					break;
				}

				case 3:
				{
					limpar();
					printf("insira o codigo do cliente sacado: ");
					scanf_s("%d", &origem);
					printf("insira o codigo do cliente beneficiario: ");
					scanf_s("%d", &destino);
					if (clienteExiste(cliente, destino) && clienteExiste(cliente, origem))
					{
						printf("valor a ser transferido: R$");
						scanf_s("%f", &valor);
						if (transferencia(cliente, &retornaCliente(cliente, origem)->conta, &retornaCliente(cliente, destino)->conta, valor))
							printf("SUCESSO: transferencia concluida\n");
						else
							printf("FALHA: nao foi possivel concluir a transferencia\n");
					}
					else
						printf("FALHA: um dos (ou os dois) codigos de cliente nao existem\n");
					parar();
					break;
				}

				case 4:
				{
					limpar();
					exibeTodasTransacoes(cliente);
					parar();
					break;
				}
				}
			} while (menu2 != 0);
			break;
		}
		}
	} while (menu != 0);
	return 0;
}

