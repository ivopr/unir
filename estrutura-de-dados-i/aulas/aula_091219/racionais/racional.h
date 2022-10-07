#include <bits/stdc++.h>
#define MAX 999
#define tf 10

/*
	OPERAÇÕES COM RACIONAIS
*/
typedef struct
{
	int num, den;
} racional;


// gera um número racional a partir de dois inteiros, sendo o segundo não nulo
racional define(int N, int D);

// soma dois números racionais R1 e R2 e retorna o resultado
racional soma(racional R1, racional R2);

// multiplica dois números racionais R1 e R2 e retorna o resultado
racional multiplica(racional R1, racional R2);

/*
	verifica se 2 números racionais R1 e R2 possuem numeradores e denominadores iguais.
	retorna 1 nesse caso e 0 caso contrário
*/
int testaIgualdade(racional R1, racional R2);

void parar()
{
	printf("pressione enter para continuar...");
	fflush(stdin);
	getchar();
}

void limpar()
{
	for(int i = 0; i < 100; i++)
		printf("\n");
}