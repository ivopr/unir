/*
	estrutura de dados I
	lista 3 - ex 7
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
	string name;

	do
	{
		limpar();
		cout << "insira uma palavra/frase: ";
		getline(cin, name);

			if(feof(stdin))
			{
				break;
			}

		cout << "a frase/palavra inserida tem " << name.length() << " caracteres. (incluindo espacos, se for uma frase)" << endl;
		parars();
	} while(1);
}
