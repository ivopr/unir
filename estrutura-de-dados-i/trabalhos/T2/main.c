#include "arvore.h"

int main()
{
	system("title Georgy e Yevgeniy");
	no *raiz = NULL;
	int menu, valor;
	do
	{
		cls();
		printf("1	-	inserir\n");
		printf("2	-	exibir em ordem\n");
		printf("3	-	exibir pre ordem\n");
		printf("4	-	exibir pos ordem\n");
		printf("5	-	altura\n");
		printf("6	-	numero de nos\n");
		printf("7	-	nivel de um no\n");
		printf("8	-	buscar\n");
		printf("9	-	remover\n");
		printf("10	-	destruir\n");
		printf("0	-	sair\n");
		printf("menu> ");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1:
			{
				printf("valor a ser inserido: ");
				scanf("%d", &valor);
				raiz = inserir(raiz, valor);
			break;
			}
			
			case 2:
			{
				exibeInOrdem(raiz);
				printf("\n");
				pause();
			break;
			}
			
			case 3:
			{
				exibePosOrdem(raiz);
				printf("\n");
				pause();
			break;
			}
			
			case 4:
			{
				exibePreOrdem(raiz);
				printf("\n");
				pause();
			break;
			}
			
			case 5:
			{
				printf("a arvore tem altura: %d\n", 1 + altura(raiz));
				pause();
			break;
			}
			
			case 6:
			{
				printf("a arvore tem %d nos\n", contagemNos(raiz));
				pause();
			break;
			}
			
			case 7:
			{
				printf("valor do no a ser verificado: ");
				scanf("%d", &valor);
				printf("o no procurado esta no nivel %d\n", nivelNo(raiz, valor, 0));
				pause();
			break;
			}
			
			case 8:
			{
				printf("valor do no a ser buscado: ");
				scanf("%d", &valor);
				busca(raiz, valor);
				pause();
			break;
			}
			
			case 9:
			{
				printf("valor a ser removido: ");
				scanf("%d", &valor);
				raiz = remover(raiz, valor);
			break;
			}
			
			case 10:
			{
				destruir(raiz);
				printf("arvore destruida\n");
				raiz = NULL;
				pause();
			break;
			}
		} // switch
	}while(menu != 0);
	destruir(raiz);
}