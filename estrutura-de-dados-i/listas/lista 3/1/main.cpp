/*
	estrutuda de dados I
	lista 3 - ex 1
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <stdlib.h>
#include <azrael.h>
#define tf 100
using namespace std;

class Main
{
	public:
		int vetor[tf], tl, np;
		void insere();
		void primo();
};

void Main::insere()
{
	cout << "digite 47417 para finalizar." << endl;
	for(int i = 0; i < tf; i++)
	{
		cout << "insira o numero da posicao " << i << ": ";
		cin >> vetor[i];
		if(vetor[i] == 47417)
		{
			break;
		}
		tl = i;
	}
	cout << "insercao de valores terminada." << endl;
	parar();
}

void Main::primo()
{
	cout << "numeros primos que estao no vetor: " << endl;
	for(int i = 0; i <= tl; i++)
	{
		for(int j = 2; j <= vetor[i] / 2; j++)
		{
			if(vetor[i] % j == 0)
			{
				np = 1;
				break;
			}
		}
		if(vetor[i] > 1)
		{
			if(np == 0) {
				cout << vetor[i] << " ";
			} else {
				np = 0;
			}
		}
	}
	cout << endl;
	parar();
}

int main()
{
	int menu;
	Main m = Main();
	m.tl = 0, m.np = 0;

	do
	{
		limpar();
		cout << "1 - inserir numeros no vetor." << endl;
		cout << "2 - exibir quais desses sao primos." << endl;
		cout << "0 - sair." << endl;

		cout << "menu: ";
		cin >> menu;

		switch(menu)
		{
			case 0:
			{
				return 0;
			}
			case 1:
			{
				m.insere();
				break;
			}
			case 2:
			{
				m.primo();
				break;
			}
			default:
			{
				cout << "essa opcao nao existe no menu... tenta de novo ai campeao..." << endl;
					parar();
				break;
			}
		}
	} while(menu != 0);
	return 0;
}
