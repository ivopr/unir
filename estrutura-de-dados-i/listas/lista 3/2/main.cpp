/*
	estrutuda de dados I
	lista 3 - ex 2
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <stdlib.h>
#include <azrael.h>
#define tf 100
using namespace std;

class Vetores
{
	public:
		int vetor[tf], vetor1[tf], vetor2[tf], tl, tl1;
		void inserir();
		void exibir();
};

void Vetores::inserir()
{
	int menu1;
	do
	{
		limpar();
		cout << "inserir vetores" << endl;
		cout << "1 - vetor A" << endl << "2 - vetor B" << endl << "0 - voltar ao menu principal" << endl;
		cout << "escolha: ";
		cin >> menu1;

		switch(menu1)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
			cout << "insira 47417 para finalizar" << endl;
				for(int i = 0; i < tf; i++)
				{
					cout << "vetorA[" << i << "]: ";
					cin >> vetor[i];
					if(vetor[i] == 47417)
					{
						break;
					}
					tl = i;
				}
				cout << "vetor A inserido com sucesso." << endl;
					parar();
				break;
			}
			case 2:
			{
			cout << "insira 47417 para finalizar" << endl;
				for(int i = 0; i < tf; i++)
				{
					cout << "vetorB[" << i << "]: ";
					cin >> vetor1[i];
					if(vetor1[i] == 47417)
					{
						break;
					}
					tl1 = i;
				}
				cout << "vetor B inserido com sucesso." << endl;
					parar();
				break;
			}
			default:
			{
				cout << "essa opcao nao existe no menu.. tenta de novo ai..." << endl;
					parar();
				break;
			}
		}
	} while(menu1 != 0);
	cout << "todos os valores foram inseridos. caso queira checar, utilize a opcao 2 do menu principal." << endl;
}

void Vetores::exibir()
{
	int menu2;
	do
	{
		limpar();
		cout << "opcoes: " << endl;
		cout << "1 - vetor A" << endl << "2 - vetor B" << endl << "3 - vetor C" << endl << "0 - voltar ao menu principal" << endl;
		cout << "visualizar: ";
		cin >> menu2;

		switch(menu2)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				limpar();
				for(int i = 0; i < tl; i++)
				{
					cout << "vetorA[" << i << "]: " << vetor[i] << endl;
				}
					parar();
				break;
			}
			case 2: {
				limpar();
				for(int i = 0; i < tl1; i++)
				{
					cout << "vetorB[" << i << "]: " << vetor1[i] << endl;
				}
					parar();
				break;
			}
			case 3:
			{
				limpar();
				if(tl > tl1)
				{
					cout << "AVISO: o vetor A eh maior que o Vetor B, logo os indices extras do vetor A serao ignorados." << endl;
				} else if(tl1 > tl)
				{
					cout << "AVISO: o vetor B eh maior que o vetor A, logo os indices extras do vetor B serao ignorados." << endl;
				}
				for(int i = 0; i < tl && i < tl1; i++)
				{
          vetor2[i] = vetor[i] + vetor1[i];
          cout << "vetorC[" << i << "]: " << vetor2[i] << endl;
				}
					parar();
				break;
			}
		}
	} while(menu2 != 0);
}

int main() {
	Vetores v = Vetores();
	v.tl = 0, v.tl1 = 0;
	int menu;

	do {
		limpar();
		cout << "1 - inserir vetores." << endl;
		cout << "2 - exibir vetores." << endl;
		cout << "0 - sair" << endl;

		cout << "menu: ";
		cin >> menu;

		switch(menu) {
			case 0: {
				return 0;
			}
			case 1: {
				v.inserir();
				break;
			}
			case 2: {
				v.exibir();
				break;
			}
			default: {
				cout << "essa opcao nao existe no menu... tenta de novo ai campeao..." << endl;
					parar();
				break;
			}
		}
	} while(menu != 0);
	return 0;
}
