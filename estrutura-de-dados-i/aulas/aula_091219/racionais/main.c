#include "racional.c"

int main()
{
	int menu, num, den;
	racional R1, R2, r;

	do
	{
		limpar();
		printf("Operacoes com racionais\n");
		printf("1 - define\n");
		printf("2 - soma de racionais\n");
		printf("3 - multiplicacao de racionais\n");
		printf("4 - verifica se os racionais sao iguais\n");
		printf("0 - sair\n");

		printf("menu> ");
		scanf("%d", &menu);
		switch(menu)
		{
			/*
				insere dois numeros racionais
			*/
			case 1:
			{ // define
				limpar();
				printf("insira um numerador de R1: ");
				scanf("%d", &num);
				printf("insira um denominador de R1: ");
				scanf("%d", &den);

				// chama a função
				R1 = define(num, den);

				printf("insira um numerador de R2: ");
				scanf("%d", &num);
				printf("insira um denominador de R2: ");
				scanf("%d", &den);

				// chama a função
				R2 = define(num, den);

				printf("numeradores e denominadores definidos\n");
				parar();
			break;
			}

			/*
				soma os dois racionais inseridos
			*/
			case 2:
			{ // soma
				limpar();
				r = soma(R1, R2);
				printf("soma entre %d/%d e %d/%d: %d/%d\n", R1.num, R1.den, R2.num, R2.den, r.num, r.den);
				parar();
			break;
			}

			/*
				multiplica os dois racionais inseridos
			*/
			case 3:
			{ // multiplicação
				limpar();
				r = multiplica(R1, R2);
				printf("multiplicacao entre %d/%d e %d/%d: %d/%d\n", R1.num, R1.den, R2.num, R2.den, r.num, r.den);
				parar();
			break;
			}
			
			/*
				chama a função que verifica se os racionais são iguais
			*/
			case 4:
			{
				limpar();
				if(testaIgualdade(R1, R2))
					printf("os numeros racionais sao iguais\n");
				else
					printf("os numeros racionais nao sao iguais\n");
				parar();
			break;
			}

			case 0:
			{ // sair
			break;
			}

			default:
			{
				limpar();
				printf("nao ha essa funcao no menu...\n");
			break;
			}
		}
	} while(menu != 0);
	return 0;
}