/*
	estrutura de dados I
	lista 3 - ex 4
	aluno: ivo vieira
	compilador: gcc 6.3.0
	sistema operacional: deepin
*/
#include <iostream>
#include <azrael.h>
#define tf 100
using namespace std;

class Matriz
{
	public:
    float matriz[tf][tf];
    void insere();
    void exibir();
    void somaimpar();
    void mediadoisquatro();
    void matrizmod();
    void exibirmod();
};

void Matriz::insere()
{
	cout << "eh, agora voce nao pode mais cancelar isso... pq sim..." << endl;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << "matriz[" << i << "][" << j << "]: ";
			cin >> matriz[i][j];
		}
	}
	cout << "insercao terminada" << endl;
	parar();
}


void Matriz::exibir()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << matriz[i][j] << "\t";
		}
		cout << endl;
	}
	parar();
}

void Matriz::somaimpar()
{
	float soma = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(j % 2 != 0)
			{
				soma += matriz[i][j];
			}
		}
	}
	cout << "a soma dos numeros nas colunas impares eh: " << soma << endl;
	parar();
}

void Matriz::mediadoisquatro()
{
	float soma = 0;
	for(int i = 0; i < 3; i++)
	{
		soma += matriz[i][2];
		soma += matriz[i][4];
	}
	cout << "a media de todos os elementos das colunas dois e quatro eh: " << soma / 12 << endl;
	parar();
}

void Matriz::matrizmod()
{
	for(int i = 0; i < 3; i++)
	{
		matriz[i][5] = matriz[i][0] + matriz[i][1];
	}
	cout << "alteracao realizada com sucesso" << endl;
		parar();
}

int main()
{
	int menu;
	Matriz m = Matriz();

	do
	{
		limpar();
		cout << "1 - inserir matriz" << endl << "2 - exibir matriz" << endl << "3 - soma de todos os elementos das colunas impares" << endl << "4 - media aritmetica da 2a e 4a coluna" << endl << "5 - substituir os valores da 6a coluna pela soma dos valores das colunas 1 e 2" << endl;
		cout << "menu> ";
		cin >> menu;

		switch(menu)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				m.insere();
				break;
			}
			case 2:
			{
				m.exibir();
				break;
			}
			case 3:
			{
				m.somaimpar();
				break;
			}
			case 4:
			{
				m.mediadoisquatro();
				break;
			}
			case 5:
			{
				m.matrizmod();
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
}
