#include "Pilha.cpp"

int main()
{
	pilha p;
	tipo_elem c;
	int op;
	define(&p);
	do
	{
		printf("1 - Insere no topo da pilha.\n");
		printf("2 - Verifica se a pilha esta vazia.\n");
		printf("3 - Esvazia a pilha.\n");
		printf("4 - Verifica o elemento que esta no topo.\n");
		printf("5 - Remove e exibe o elemento no topo da pilha.\n");
		printf("6 - Sair.\n");
		printf("Escolha uma opcao: ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
			{
				printf("\n Entre com o elemento que deseja inserir: ");
				scanf("%d", &c.info);
				if(Push(c, &p)){
					printf("\n Inserido com sucesso.");
				}
					else{
						printf("\n Erro, pilha cheia.");
					}
			break;
			}

			case 2:
			{
				if(Vazia(&p)){
					printf("\n Pilha vazia.");
				}
					else{
						printf("\n Pilha nao vazia.");
					}
			break;
			}

			case 3:
			{
				Esvaziar(&p);
				printf("\n Pilha esvaziada.");
			break;
			}

			case 4:
			{
				if(Vazia(&p))
				{
					printf("\n Pilha vazia.");
				}
				else
				{
					printf("Topo: %d", Top(&p).info);
				}
			break;
			}

			case 5:
			{
				if(Vazia(&p))
				{
					printf("pilha vazia\n");
				}
				else
				{
					Pop(&p);
					printf("topo: %d\n", Top(&p).info);
				}
			break;
			}
		}
	} while(op != 0);
	return 0;
}
