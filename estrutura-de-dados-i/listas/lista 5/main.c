/*
	ESTRUTURA DE DADOS I
	Lista 5
	Alunos: Ivo Vieira e Murilo Fuza
	compilador: tdm-gcc
	sistema operacional: windows
*/
#include "lista.c"

int main()
{
	int menu, listaSelec, maior, menor;
	lista um, dois, tres;
	elemento c;

	do
	{
		limpar();
		printf("1 - inciar listas\n");
		printf("2 - exibir lista\n");
		printf("3 - inserir elemento no primeiro indice\n");
		printf("4 - inserir elemento no ultimo indice\n");
		printf("5 - inserir um numero de forma ordenada\n");
		printf("6 - remover um numero\n");
		printf("7 - invoca thanos e destroi a lista\n");
		printf("8 - buscar um numero\n");
		printf("9 - verifica se a lista esta ordenada\n");
		printf("10 - copiar lista 1 na lista 2\n");
		printf("11 - copiar lista 1 na lista 2 sem repeticoes\n");
		printf("12 - intercalar lista 1 e lista 2 na lista 3 de forma ordenada\n");
		printf("13 - contar e exibir quantas vezes um elemento se repete na lista 1\n");
		printf("14 - contar e exibir elementos que se repetem o maior e o menor numero de vezes na lista 1\n");
		printf("0 - sair\n");

		printf("menu> ");
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
			{
				inicia(&um);
				inicia(&dois);
				inicia(&tres);
				printf("listas iniciadas...\n");
				parar();
			break;
			}

			case 2:
			{
				limpar();
				printf("exibir lista\nqual lista deseja ver? ");
				scanf("%d", &listaSelec);

				if(listaSelec == 1)
					exibir(&um);
				else if(listaSelec == 2)
					exibir(&dois);
				else if(listaSelec == 3)
					exibir(&tres);
				else
					printf("a lista solicitada nao existe nesse programa\n");
				parar();
			break;
			}

			case 3:
			{
				limpar();
				printf("inserir elemento no primeiro indice\nqual lista sera feita a insercao? (1, 2 ou 3): ");
				scanf("%d", &listaSelec);
				printf("qual o numero a ser inserido: ");
				scanf("%d", &c.chave);

				if(listaSelec == 1)
				{
					if(inserirInicio(&um, c))
						printf("inserido com sucesso no primeiro indice da lista 1\n");
					else
						printf("nao foi possivel inserir o numero na lista 1...\n");
				} 
				else if(listaSelec == 2)
				{
					if(inserirInicio(&dois, c))
						printf("inserido com sucesso no primeiro indice da lista 2\n");
					else
						printf("nao foi possivel inserir o numero na lista 2...\n");
				}
				else if(listaSelec == 3)
				{
					if(inserirInicio(&tres, c))
						printf("inserido com sucesso no primeiro indice da lista 3\n");
					else
						printf("nao foi possivel inserir o numero na lista 3...\n");
				}
				else
					printf("a lista selecionada nao existe\n");
				parar();
			break;
			}

			case 4:
			{
				limpar();
				printf("inserir elemento no ultimo indice\nqual lista sera feita a insercao? (1, 2 ou 3): ");
				scanf("%d", &listaSelec);
				printf("qual o numero a ser inserido: ");
				scanf("%d", &c.chave);

				if(listaSelec == 1)
				{
					if(inserirFim(&um, c))
						printf("inserido com sucesso no ultimo indice da lista 1\n");
					else
						printf("nao foi possivel inserir o numero na lista 1...\n");
				} 
				else if(listaSelec == 2)
				{
					if(inserirFim(&dois, c))
						printf("inserido com sucesso no ultimo indice da lista 2\n");
					else
						printf("nao foi possivel inserir o numero na lista 2...\n");
				}
				else if(listaSelec == 3)
				{
					if(inserirFim(&tres, c))
						printf("inserido com sucesso no ultimo indice da lista 3\n");
					else
						printf("nao foi possivel inserir o numero na lista 3...\n");
				}
				else
					printf("a lista selecionada nao existe\n");
				parar();
			break;
			}
			
			case 5:
			{
				limpar();
				printf("inserir elemento de forma ordenada\nqual lista sera feita a insercao? (1, 2 ou 3): ");
				scanf("%d", &listaSelec);
				printf("qual o numero a ser inserido: ");
				scanf("%d", &c.chave);

				if(listaSelec == 1)
				{
					if(inserirOrdenado(&um, c))
						printf("inserido com sucesso na lista 1\n");
					else
						printf("nao foi possivel inserir o numero na lista 1...\n");
				} 
				else if(listaSelec == 2)
				{
					if(inserirOrdenado(&dois, c))
						printf("inserido com sucesso na lista 2\n");
					else
						printf("nao foi possivel inserir o numero na lista 2...\n");
				}
				else if(listaSelec == 3)
				{
					if(inserirOrdenado(&tres, c))
						printf("inserido com sucesso na lista 3\n");
					else
						printf("nao foi possivel inserir o numero na lista 3...\n");
				}
				else
					printf("a lista selecionada nao existe\n");
				parar();
			break;
			}

			case 6:
			{
				limpar();
				printf("remover elemento\nqual lista sera feita a remocao? (1, 2 ou 3): ");
				scanf("%d", &listaSelec);
				printf("qual o numero a ser removido: ");
				scanf("%d", &c.chave);

				if(listaSelec == 1)
				{
					if(remover(&um, c))
						printf("removido com sucesso na lista 1\n");
					else
						printf("nao foi possivel remover o numero na lista 1. talvez ele nao exista...\n");
				} 
				else if(listaSelec == 2)
				{
					if(remover(&dois, c))
						printf("removido com sucesso na lista 2\n");
					else
						printf("nao foi possivel remover o numero na lista 2. talvez ele nao exista...\n");
				}
				else if(listaSelec == 3)
				{
					if(remover(&tres, c))
						printf("removido com sucesso na lista 3\n");
					else
						printf("nao foi possivel remover o numero na lista 3. talvez ele nao exista...\n");
				}
				else
					printf("a lista selecionada nao existe\n");
				parar();
			break;
			}

			case 7:
			{
				limpar();
				removeTudo(&um);
				removeTudo(&dois);
				removeTudo(&tres);
				printf("listas deletadas.\n");
				parar();
			break;
			}

			case 8:
			{
				limpar();
				int pos;
				printf("buscar elemento\nqual lista deseja buscar elemento? (1, 2 ou 3): ");
				scanf("%d", &listaSelec);
				printf("numero a ser buscado: ");
				scanf("%d", &c.chave);
				
				if(listaSelec == 1)
				{
					ordena(&um);
					pos = buscaBinaria(&um, c);
				}
				else if(listaSelec == 2)
				{
					ordena(&dois);
					pos = buscaBinaria(&dois, c);
				}
				else if(listaSelec == 3)
				{
					ordena(&tres);
					pos = buscaBinaria(&tres, c);
				}

				if(pos != -1)
					printf("o numero foi encontrado na posicao %d da lista %d\n", pos, listaSelec);
				else
					printf("o numero nao existe na lista %d\n", listaSelec);
				parar();
			break;
			}

			case 9:
			{
				limpar();
				printf("verifica ordenacao\nqual lista verificar a ordenacao? (1, 2 ou 3): ");
				scanf("%d", &listaSelec);

				if(listaSelec == 1)
				{
				if(ordenadoCrescente(&um))
					printf("a lista 1 esta ordenada crescentemente\n");
				else if(ordenadoDecrescente(&um))
					printf("a lista 1 esta ordenada decrescentemente\n");
				else
					printf("a lista 1 nao esta ordenada\n");
				}
				else if(listaSelec == 2)
				{
				if(ordenadoCrescente(&dois))
					printf("a lista 2 esta ordenada crescentemente\n");
				else if(ordenadoDecrescente(&dois))
					printf("a lista 2 esta ordenada decrescentemente\n");
				else
					printf("a lista 2 nao esta ordenada\n");
				}
				else if(listaSelec == 3)
				{
				if(ordenadoCrescente(&tres))
					printf("a lista 3 esta ordenada crescentemente\n");
				else if(ordenadoDecrescente(&tres))
					printf("a lista 3 esta ordenada decrescentemente\n");
				else
					printf("a lista 3 nao esta ordenada\n");
				}
				parar();
			break;
			}

			case 10:
			{
				limpar();
				copia(&um, &dois);
				printf("feita uma copia da lista 1 na lista 2\n");
				parar();
			break;
			}

			case 11:
			{
				limpar();
				copiaNaoRepetidos(&um, &dois);
				printf("feita uma copia da lista 1 na lista 2 sem repeticoes\n");
				parar();
			break;
			}

			case 12:
			{
				limpar();
				intercala(&um, &dois, &tres);
				printf("listas 1 e 2 intercaladas na lista 3\n");
				parar();
			break;
			}

			case 13:
			{
				limpar();
				printf("contar elementos da lista 1\n");

				contElem(&um, &dois);
				exibirCont(&dois);
				parar();
			break;
			}

			case 14:
			{
				limpar();
				maior = contarMaior(&um);
				menor = contarMenor(&um);
				
				printf("numero que se repete mais vezes eh %d e se repete %d vezes\n", um.v[maior].chave, um.v[maior].count);
				printf("numero que se repete menos vezes eh %d e se repete %d vezes\n", um.v[menor].chave, um.v[menor].count);
				parar();
			break;
			}
		}
	} while (menu != 0);
	removeTudo(&um);
	removeTudo(&dois);
	removeTudo(&tres);
	return 0;
}