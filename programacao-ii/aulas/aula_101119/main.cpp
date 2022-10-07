#include "hash.cpp"

int main()
{
	int menu;
	char chave[30];
	enderecamentoEncadeado classe = enderecamentoEncadeado();

	do
	{
		system("cls");
		std::cout	<< "1 - inserir nome" << std::endl
					<< "2 - exibir tudo" << std::endl
					<< "3 - buscar por nome" << std::endl
					<< "4 - buscar por letra" << std::endl
					<< "5 - excluir todos" << std::endl
					<< "0 - sair" << std::endl;
		std::cout 	<< "menu> ";
		std::cin >> menu;

		switch(menu)
		{
			/*
				caso da inserção
			*/
			case 1:
			{
				std::cout	<< "nome a ser inserido: ";
				std::cin 	>> chave[30];
				if(classe.inserir(chave))
					std::cout	<< "nome inserido com sucesso" << std::endl;
				system("pause");
			break;
			}

			/*
				caso da exibição
			*/
			case 2:
			{
				
			break;
			}

			/*
				caso da busca por nome
			*/
			case 3:
			{
			
			break;
			}

			/*
				caso da busca por letra
			*/
			case 4:
			{

			break;
			}

			/*
				caso da remoção
			*/
			case 5:
			{

			break;
			}
		} /* switch */
	} while (menu != 0);
	return 0;
} /* main */