/*
	estrutura de dados I
	lista 3 - ex 5
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <stdlib.h>
#include <azrael.h>
#define tf 100
using namespace std;

int main()
{
	int grau, matriz[tf][tf];

	do
	{
		limpar();
			cout << "insira 0 para sair." << endl;
			cout << "qual o grau desejado: ";
			cin >> grau;

		for(int i = 1; i <= grau; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				if(i == j)
				{
					matriz[i][j] = 1;
				}
					else
				{
					matriz[i][j] = 0;
				}
				if(matriz[i][j] == 0)
				{
					matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - 1];
				}
				cout << matriz[i][j] << "	";
			}
			cout << endl;
		}
		parar();
	} while(grau != 0);
}
