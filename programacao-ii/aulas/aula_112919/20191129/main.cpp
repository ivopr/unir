#include "arq.h"
#include <iostream>

int main()
{
	int menu;
	lolja l;

	do
	{
		std::cout	<< "1 - inserir produto" << std::endl
					<< "2 - exibe ordenado" << std::endl
					<< "3 - exibe desordenado" << std::endl
					<< "4 - exibe indice" << std::endl
					<< "0 - sair" << std::endl
					<< "menu> " << std::endl;
		std::cin >> menu;

		switch (menu)
		{
			case 1:
			{
				l.inserirProduto();
				break;
			}

			case 2:
			{
				l.exibeOrdenado();
				break;
			}

			case 3:
			{
				l.exibeDesordenado();
				break;
			}

			case 4:
			{
				l.exibeIndice();
				break;
			}

			case 5:
			{
				int codigo;
				std::cout << "insira o codigo de produto a ser consultado: ";
				std::cin >> codigo;
				l.consulta(codigo);
				break;
			}
		}
	} while (menu != 0);
}