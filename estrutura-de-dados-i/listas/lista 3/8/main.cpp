/*
	estrutura de dados I
	lista 3 - ex 8
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <azrael.h>
using namespace std;

typedef struct
{
	string nome;
	int idade;
} vetor;

int main()
{
	int menor = 100, maior = 0, jovem = 0, velho = 0;
	vetor pessoas[10];

	for(int i = 0; i < 10; i++)
	{
		cout << "insira o primeiro nome: ";
		cin >> pessoas[i].nome;
		cout << "insira a idade de " << pessoas[i].nome << ": ";
		cin >> pessoas[i].idade;

		if(pessoas[i].idade < 0)
		{
			break;
		}
			else if(pessoas[i].idade < menor)
		{
			menor = pessoas[i].idade;
			jovem = i;
		}
			else if(pessoas[i].idade > maior)
		{
			maior = pessoas[i].idade;
			velho = i;
		}
	}

	cout << "mais jovem" << endl;
	cout << "nome: " << pessoas[jovem].nome << endl << "idade: " << pessoas[jovem].idade << endl;
	cout << "mais velho(a)" << endl;
	cout << "nome: " << pessoas[velho].nome << endl << "idade: " << pessoas[velho].idade << endl;
		parar();
	return 0;
}
