/*
	estrutura de dados I
	lista 2 - ex 8
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	// fun��o para inser��o de dados no vetor de n�meros
	void insere(double num[100], int *tl)
	{
		printf("para finalizar a insercao digite 47417.\n");
		while(1)
		{
			limpar();
			printf("insira um numero [%d]: ", *tl);
			scanf("%lf", &num[*tl]);
			
			if(num[*tl] == 47417)
				break;

			*tl = *tl + 1;
		}
	}
	
	// calcula a soma de todos os valores inseridos
	double soma(double num[100], int tl)
	{
		double soma = 0;
		for(int i = 0; i < tl; i++)
			soma += num[i];
		
		return soma;
	}
	
	// calcula a media dos numeros utilizando o retorno do calculo da soma
	void medig(double num[100], int tl)
	{
		double media = soma(num, tl) / tl;
		printf("a media dos numeros digitados eh %.2lf\n", media);
		parar();
	}
	
	// verifica, guarda e exibe o maior numero inserido
	void maior(double num[100], int tl)
	{
		double maior = 0;
		for(int i = 0; i < tl; i ++)
			if(num[i] > maior) 
				maior = num[i];
	
		printf("o maior numero digitado eh %.2lf\n", maior);
		parar();
	}
	
	// verifica, guarda e exibe o menor numero exibido
	void menor(double num[100], int tl)
	{
		double menor = 999999;
		for(int i = 0; i < tl; i ++)
			if(num[i] < menor)
				menor = num[i];

		printf("o menor numero digitado eh %.2lf\n", menor);
		parar();
	}
	
	// transforma os numeros decimais em inteiros (1.9 = 1, 2.2 = 2), verifica se ele � par, se for, realiza a soma dele
	// adiciona +1 ao contador e ao final divide a soma / cont para obter a media dos n�meros pares inseridos.
	void medpar(double num[100], int tl)
	{
		double soma = 0, cont = 0;
		for(int i = 0; i < tl; i++)
		{
			if((int) num[i] % 2 == 0)
			{
				soma += num[i];
				cont++;
			}
		}
		printf("a media dos numeros pares eh %.2lf\n", soma / cont);
		parar();
	}
	
	int main()
	{
		int menu = 999, tl = 0;
		double num[100];
		
		// enquanto for diferente de 0 isso aqui repete eternamente pra sempre...
		while(menu != 0)
		{
			limpar();
			printf("1 - inserir numeros\n");
			printf("2 - soma dos numeros digitados\n");
			printf("3 - quantidade de numeros digitados\n");
			printf("4 - media dos numeros digitados\n");
			printf("5 - maior numero digitado\n");
			printf("6 - menor numero digitado\n");
			printf("7 - media dos numeros pares\n");
			printf("0 - sair\n");
			
			printf("\nmenu: ");
			scanf("%d", &menu);
			
			switch(menu)
			{
				case 1:
					insere(num, &tl);
				break;
				case 2:
					printf("a soma dos numeros inseridos eh: %.2lf\n", soma(num, tl));
				break;
				case 3:
					printf("o total de numeros inseridos eh: %d\n", tl);
				break;
				case 4:
					medig(num, tl);
				break;
				case 5:
					maior(num, tl);
				break;
				case 6:
					menor(num, tl);
				break;
				case 7:
					medpar(num, tl);
				break;
			}
			
			parar();
		}
	}
