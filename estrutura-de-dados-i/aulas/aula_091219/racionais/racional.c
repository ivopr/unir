#include "racional.h"

// gera um número racional a partir de dois inteiros, sendo o segundo não nulo
racional define(int N, int D)
{
	racional r;
	r.num = N;
	r.den = D;
	return r;
}

// soma dois números racionais R1 e R2 e retorna o resultado
racional soma(racional R1, racional R2)
{
	racional r;
	r.num = R1.num * R2.den + R1.den * R2.num;
	r.den = R1.den * R2.den;
	return r;
}

// multiplica dois números racionais R1 e R2 e retorna o resultado
racional multiplica(racional R1, racional R2)
{
	racional r;
	r.num = R1.num * R2.num;
	r.den = R1.den * R2.den;
	return r;
}

// verifica se 2 números racionais R1 e R2 possuem numeradores e denominadores iguais.
// retorna 1 nesse caso e 0 caso contrário
int testaIgualdade(racional R1, racional R2)
{
	return (float) R1.num / R1.den == (float) R2.num / R2.den;
}