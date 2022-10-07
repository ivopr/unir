#include <ed.h>

/*
	FUNÇÃO RECURSIVA
	é uma função que se auto usa a si mesma...
*/
unsigned long long int fatorial(int n)
{
	// se o numero digitado for 0, ele retorna 1 que consequentemente acaba a função
	if(n == 0)
		return 1;
	// caso contrario, ele calcula o fatorial do numero chamando a função até n se tornar 0 e acabar a função
	return (n * fatorial(n - 1));
}

int main()
{
	int num;
	
	do
	{
		limpar();

		/*
			leitura normal da variável num, já que é um número inteiro qualquer...
		*/
		printf("insira um numero: ");
		scanf("%d", &num);

		/*
			%llu é o formatador para long-long-unsigned
		*/
		printf("o fatorial de %d eh %llu\n", num, fatorial(num));
		
		parar();
	} while(num != 0);
}