/*
  estrutura de dados I
  lista 4 - ex 1
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include "estrutura.h"
#define tf 10

int main()
{
	int vetor[tf];

	printf("enderecos de memoria: \n");
	for (int i = 0; i < tf; i++)
		printf("vetor[%d]: %u\n", i, &vetor[i]);
  return 0;
}