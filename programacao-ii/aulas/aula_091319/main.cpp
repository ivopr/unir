#include "prog.h"

int main() 
{
	Prog p = Prog();
	int menu = 999, i, t[2], num;
	do
	{
    	limpar();
		cout	<< "01 - criarVetor" << endl
				<< "02 - exibeVetor" << endl
				<< "03 - bubbleSortCrescente" << endl
				<< "04 - bubbleSortDecrescente" << endl
				<< "05 - insertionSortCrescente" << endl
				<< "06 - insertionSortDecrescente // nao funcional" << endl
				<< "07 - selectionSortCrescente" << endl
				<< "08 - selectionSortDecrescente // nao funcional" << endl
				<< "09 - quickSortCrescente" << endl
				<< "10 - quickSortDecrescente" << endl
				<< "11 - heapSortCrescente" << endl
				<< "12 - buscaLinear" << endl
				<< "13 - buscaSequencial" << endl
				<< "14 - buscaBinaria." << endl
				<< "0 - sair" << endl;
		cout << "menu> ";
		cin >> menu;

		switch(menu)
    	{
			/*
				CRIAR VETOR ALEATÓRIAMENTE
			*/
			case 1:
      		{
				p.criarVetor();
				cout << "vetor criado." << endl;
				parar();
			break;
			}

			/*
				EXIBIR VETOR
			*/
			case 2:
      		{
				p.exibirVetor();
				parar();
			break;
			}

			/*
				ORDENAÇÃO BOLHA
			*/
			case 3:
      		{
        		t[0] = clock();
				p.bubbleSortCrescente();
        		t[1] = clock();

				cout << "vetor ordenado crescentemente" << endl;
        		cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
          		parar();
			break;
			}

      		case 4:
      		{ // decrescente
        		t[0] = clock();
				p.bubbleSortDecrescente();
        		t[1] = clock();

				cout << "vetor ordenado decrescentemente" << endl;
        		cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
          		parar();
			break;
      		}

			/*
				ORDENAÇÃO POR INSERÇÃO
			*/
      		case 5:
      		{
        		t[0] = clock();
				p.insertionSortCrescente();
        		t[1] = clock();

				cout << "vetor ordenado crescentemente" << endl;
        		cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
          		parar();
			break;
      		}
			
			case 6:
			{ // decrescente
				t[0] = clock();
				p.insertionSortDecrescente();
				t[1] = clock();

				cout << "vetor ordenado decrescentemente" << endl;
				cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			/*
				ORDENAÇÃO POR SELEÇÃO
			*/
			case 7:
			{
				t[0] = clock();
				p.selectionSortCrescente();
				t[1] = clock();

				cout << "vetor ordenado crescentemente" << endl;
				cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			case 8:
			{ // decrescente
				t[0] = clock();
				p.selectionSortDecrescente();
				t[1] = clock();

				cout << "vetor ordenado crescentemente" << endl;
				cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			/*
				ORDENAÇÃO RÁPIDA (QUICK SORT)
			*/
			case 9:
			{
				t[0] = clock();
				p.quickSortCrescente(0, tf - 1);
				t[1] = clock();

				cout << "vetor ordenado crescentemente" << endl;
				cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			case 10:
			{ // decrescente
				t[0] = clock();
				p.quickSortDecrescente(0, tf - 1);
				t[1] = clock();

				cout << "vetor ordenado decrescentemente" << endl;
				cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			case 11:
			{ // decrescente
				t[0] = clock();
				p.heapSort();
				t[1] = clock();

				cout << "vetor ordenado decrescentemente" << endl;
				cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			/*
				BUSCA LINEAR (EXAUSTIVA)
			*/
			case 12:
      		{
        		cout << p.vetor[tf - 1] << "\t" << p.vetor[0] << endl;
	      		cout << "qual numero deseja buscar? ";
	      		cin >> num;

				t[0] = clock();
				i = p.buscaLinear(num);
				t[1] = clock();

				if(i != -1)
					cout << "o numero " << p.vetor[i] << " foi encontrado no indice " << i << endl;
        		else
					cout << "o numero pesquisado nao existe no vetor." << endl;

        		cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				parar();
			break;
			}

			/*
				BUSCA SEQUÊNCIAL
			*/
			case 13:
      		{
        		cout << p.vetor[tf - 1] << "\t" << p.vetor[0] << endl;
	      		cout << "qual numero deseja buscar? ";
	      		cin >> num;

       			t[0] = clock();
				i = p.buscaSequencial(num);
        		t[1] = clock();

				
        		cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;

				if(p.ordem != true)
        		{
					cout << "o vetor nao esta ordenado." << endl;
					parar();
				break;
				}

				if(i != -1)
					cout << "o numero " << p.vetor[i] << " foi encontrado no indice " << i << endl;
        		else
					cout << "o numero pesquisado nao foi encontrado." << endl;
				parar();
			break;
			}

			/*
				BUSCA BINÁRIA
			*/
			case 14:
      		{
        		cout << p.vetor[tf - 1] << "\t" << p.vetor[0] << endl;
	      		cout << "qual numero deseja buscar? ";
	      		cin >> num;

				t[0] = clock();
				i = p.buscaBinaria(num);
				t[1] = clock();

				
        		cout << "tempo gasto: " << t[1] - t[0] << "ms" << endl;
				if(p.ordem != true)
        		{
					cout << "o vetor nao esta ordenado" << endl;
            		parar();
				break;
				}
				if(i != -1)
					cout << "o numero " << p.vetor[i] << " foi encontrado no indice " << i << endl;
        		else
					cout << "o numero pesquisado nao foi encontrado" << endl;
					
          		parar();
			break;
			}
		}
	}while(menu != 0);
	return 0;
}
