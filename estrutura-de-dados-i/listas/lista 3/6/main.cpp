/*
	estrutura de dados I
	lista 3 - ex 6
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <azrael.h>

using namespace std;

int main()
{
	string input;

	do
	{
		limpar();
		cout << "insira 0 para sair." << endl;
		cout << "qual palavra/frase deseja inverter: ";
		getline(cin, input);

			if(feof(stdin))
			{
				break;
			}
		for(int i = input.length() - 1; i >= 0; i--)
		{
			cout << input[i];
		}
		cout << endl;
		parars();
	} while(1);
}
