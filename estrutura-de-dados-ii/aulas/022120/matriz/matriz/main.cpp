#include "grafo.h"

int main()
{
	int menu = -1, v1, v2;
	matrizAdj g;
	grafoVazio(&g);
	system("TITLE Grafo - Matriz de Adjacencia");
	do
	{
		system("cls");
		printf("1	-	Criar Grafo\n"
			   "2	-	Inserir Aresta\n"
			   "3	-	Exibir Grafo\n"
			   "4	-	Remover Aresta\n"
			   "5	-	Grau do Vertice\n"
			   "6	-	Vertices Adjacentes\n"
			   "7	-	Destruir Grafo\n"
			   "8	-	Verifica Grafo Vazio\n"
			   "0	-	sair\n"
			   "menu> ");
		scanf_s("%d", &menu);
		switch (menu)
		{
			case 1:
			{
				printf("Insira o numero de vertices: ");
				scanf_s("%d", &v1);
				if (criarGrafo(&g, v1))
					printf("Vertices criados.\n");
				else
					printf("Nao foi possivel criar o grafo.\n");
				system("pause");
				break;
			}

			case 2:
			{
				printf("Quais os vertices: ");
				scanf_s("%d %d", &v1, &v2);
				if (inserirAresta(&g, v1, v2))
					printf("Aresta inserida.\n");
				else
					printf("Nao foi possivel inserir a aresta.\n");
				system("pause");
				break;
			}

			case 3:
			{
				exibeGrafo(&g);
				system("pause");
				break;
			}

			case 4:
			{
				printf("Quais os vertices: ");
				scanf_s("%d %d", &v1, &v2);
				if (removerAresta(&g, v1, v2))
					printf("Aresta inserida.\n");
				else
					printf("Nao foi possivel inserir a aresta.\n");
				system("pause");
				break;
			}

			case 5:
			{
				printf("Qual vertice: ");
				scanf_s("%d", &v1);
				v1 = verticesAdj(&g, v1);
				printf("O vertice tem grau %d\n", v1);
				system("pause");
				break;
			}

			case 6:
			{
				printf("Qual vertice: ");
				scanf_s("%d", &v1);
				verticesAdjacentes(&g, v1);
				system("pause");
				break;
			}

			case 7:
			{
				destruirGrafo(&g);
				break;
			}

			case 8:
			{
				if (grafoVazio(&g))
					printf("O grafo esta vazio.\n");
				else
					printf("O grafo nao esta vazio.\n");
				break;
			}
		}

	} while (menu != 0);
}