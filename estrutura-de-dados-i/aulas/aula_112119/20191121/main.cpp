#include "arvere.h"
#include <iostream>

int main()
{
	system("title 20191121.exe");
	int menu;
	arvere a;
	do
	{
		std::cout	<< "1 - inserir" << std::endl
					<< "2 - remover" << std::endl
					<< "3 - busca" << std::endl
					<< "menu> ";
		std::cin >> menu;

		switch (menu)
		{
			case 1:
			{
				int chave;
				std::cout << "insira um numero: ";
				std::cin >> chave;
				if (a.inserir(chave))
					std::cout << "SUCESSO: numero inserido." << std::endl;
				else
					std::cout << "ERRO: nao foi possivel inserir. numero repetido." << std::endl;
				break;
			}

			case 2:
			{
				int chave;
				std::cout << "insira um numero: ";
				std::cin >> chave;
				if (a.remover(chave))
					std::cout << "SUCESSO: numero removido." << std::endl;
				else
					std::cout << "ERRO: nao foi possivel remover. numero nao existe na arvore." << std::endl;
				break;
			}

			case 3:
			{
				int chave;
				std::cout << "insira um numero: ";
				std::cin >> chave;
				raiz* r = a.busca(chave);
				std::cout << r->info.chave << std::endl;
				break;
			}
		}
	} while (menu != 0);
}