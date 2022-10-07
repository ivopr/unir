/*
	estrutura de dados I
	lista 3 - ex 3
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <stdlib.h>
#include <azrael.h>
#define tf 4
using namespace std;

class Matrizes
{
	public:
		int matriz[tf][tf], matriz1[tf][tf], matriz2[tf][tf];
		void inserir();
		void exibir();
};

void Matrizes::inserir()
{
	int insere;
	do
	{
		limpar();
		cout << "inserir matrizes" << endl;
		cout << "1 - matriz A." << endl << "2 - matriz B." << endl << "0 - voltar ao menu principal" << endl;
		cout << "escolha: ";
		cin >> insere;

		switch(insere)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
			cout << "insira 47417 para cancelar." << endl;
				for(int i = 0; i < tf; i++)
				{
					for(int j = 0; j < tf; j++)
					{
						cout << "matrizA[" << i << "][" << j << "]: ";
						cin >> matriz[i][j];
						if(matriz[i][j] == 47417)
						{
							break;
						}
					}
				}
					parar();
				break;
			}
			case 2:
			{
			cout << "insira 47417 para cancelar." << endl;
				for(int i = 0; i < tf; i++)
				{
					for(int j = 0; j < tf; j++)
					{
						cout << "matrizB[" << i << "][" << j << "]: ";
						cin >> matriz1[i][j];
						if(matriz[i][j] == 47417)
						{
							break;
						}
					}
				}
					parar();
				break;
			}
		}
	} while(insere != 0);
}

void Matrizes::exibir()
{
	int exibe;
	do {
		limpar();
		cout << "exibe as matrizes" << endl;
		cout << "1 - matriz A" << endl << "2 - matriz B" << endl << "3 - matriz C" << endl << "0 - voltar ao menu principal" << endl;
		cout << "escolha: ";
		cin >> exibe;

		switch(exibe)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				for(int i = 0; i < tf; i++)
				{
					for(int j = 0; j < tf; j++)
					{
						cout << matriz[i][j] << "\t";
					}
				}
				cout << endl;
					parar();
				break;
			}
			case 2:
			{
				for(int i = 0; i < tf; i++)
				{
					for(int j = 0; j < tf; j++)
					{
						cout << matriz1[i][j] << "\t";
					}
				}
				cout << endl;
					parar();
				break;
			}
			case 3: {
				for(int i = 0; i < tf; i++)
				{
					for(int j = 0; j < tf; j++)
					{
						if(matriz[i][j] > matriz1[i][j])
						{
							matriz2[i][j] = matriz[i][j];
						} else
						{
							matriz2[i][j] = matriz1[i][j];
						}

						cout << matriz2[i][j] << "\t";
					}
				}
				cout << endl;
					parar();
				break;
			}
			default: {
				cout << "essa opcao nao existe no menu." << endl;
					parar();
				break;
			}
		}
	} while(exibe != 0);
}


int main()
{
	Matrizes m = Matrizes();
	int menu;

	do
	{
		limpar();
		cout << "1 - inserir matrizes." << endl << "2 - exibir matrizes." << endl << "0 - sair." << endl;
		cout << "menu: ";
		cin >> menu;

		switch(menu)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				m.inserir();
				break;
			}
			case 2:
			{
				m.exibir();
				break;
			}
			default:
			{
				cout << "essa opcao nao existe no menu..." << endl;
					parar();
				break;
			}
		}
	} while(menu != 0);
	return 0;
}
