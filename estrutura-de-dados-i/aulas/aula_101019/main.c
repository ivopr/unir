#include "listaDinamicaEncadeada.c"

int main()
{
	int menu = 999;
	lista um;
	dado num;

	while(menu != 0){
		printf("1 - Iniciar\n");
		printf("2 - Exibir\n");
		printf("3 - Inserir ordenado\n");
		printf("4 - Remover\n");
        printf("5 - Destruir\n");
		printf("6 - buscar\n");
		printf("0 - Sair\n");
		printf("menu: ");
		scanf("%d", &menu);

		switch (menu)
		{
			case 1:
			{
				iniciar(&um);
				system("cls");
			break;
			}

			case 2:
			{
				exibir(&um);
				system("pause");
				system("cls");
				break;
			}

			case 3:
			{
				printf("Qual numero deseja inserir: ");
				scanf("%d",&num.chave);
				inserirOrdenado(&um, num);
				printf("Inserido!");
				system("pause");
				system("cls");
				break;
			}

			case 4:
			{
				printf("Qual numero deseja remover: ");
				scanf("%d", &num.chave);
				remover(&um, num);
				printf("Removido");
				system("pause");
				system("cls");
				break;
			}

			case 5:
			{
				destruir(&um);
				printf("Destruido");
				system("pause");
				system("cls");
				break;
			}

			case 6:
			{
				printf("numero a buscar: ");
				scanf("%d", &num.chave);
				if(busca(&um, num))
					printf("o numero buscado foi encontrado na lista\n");
				else
					printf("o numero buscado nao foi encontrado na lista\n");
				system("pause");
				system("cls");
			break;
			}
		}
	}
	return 0;
}