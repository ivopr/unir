#include <prog.h>

/*
	FUNÇÃO RECURSIVA
	é uma função que se auto usa a si mesma...
*/
unsigned long long int fatorial(int n)
{
	// se o numero digitado for 0, ele retorna 1 que consequentemente acaba a função
	if(n == 2)
		return 2;
	// caso contrario, ele calcula o fatorial do numero chamando a função até n se tornar 0 e acabar a função
	return (n * fatorial(n - 1));
}

int main()
{
	int num;
	do
	{
		limpar();
		cout << "insira um numero: ";
		cin >> num;
		cout << "o fatorial de " << num << " eh " << fatorial(num) << endl;
		parar();
	} while(num != -1);
	return 0;
}