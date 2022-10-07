#include "main.h"

/* inicia a lista */
void inicia(lista *a)
{
	a->n = 0;
}

/* exibe a lista */
void exibir(lista *a)
{
	if(listaVazia(a))
		printf("nao ha elementos na lista\n");
	else
	{
		for(int i = 0; i < a->n; i++)
			printf("lista[%.2d]: %.2d\t", i, a->v[i].chave);
		printf("\n");
	}
}

/* retorna true se a lista estiver vazia, false caso contrário */
int listaVazia(const lista *a)
{
	return a->n == 0;
}

/* retorna true se a lista estiver cheia, false caso contrário */
int listaCheia(const lista *a)
{
	return a->n == tf;
}

/* insere o elemento no indice 0 */
int inserirInicio(lista *a, elemento c)
{
	if(listaCheia(a)) return 0;
	for(int i = a->n; i > 0; i--)
		a->v[i].chave = a->v[i - 1].chave;
	a->v[0].chave = c.chave;
	a->n++;
	return 1;
}

/* insere o elemnto no ultimo indice */
int inserirFim(lista *a, elemento c)
{
	if(listaCheia(a)) return 0;
	a->v[a->n].chave = c.chave;
	a->n++;
	return 1;
}

/* insere um elemento na ordem que ele deve estar */
int inserirOrdenado(lista *a, elemento c)
{
	int j, i;
  if(listaCheia(a)) return 0;
  if(listaVazia(a)) return inserirInicio(a, c);
  	while (i < a->n && a->v[i].chave < c.chave)
      i++;
    if(i == a->n)
      return inserirFim(a, c);
    for(j = a->n; j > i; j--)
      a->v[j].chave = a->v[j - 1].chave;
    a->v[i].chave = c.chave;
  return 1;
}

/* remove um número da lista */
int remover(lista *a, elemento c)
{
	int k;
	if(listaVazia(a)) return 0;

	// busca
	for(int i = 0; i < a->n && a->v[i].chave != c.chave; i++)
		k = i;

	if(k == a->n) return 0;

	for(int j = k; j < a->n - 1; j++)
		a->v[j].chave = a->v[j + 1].chave;
	a->n--;
	return 1;
}

/* remove todos os elementos da lista */
void removeTudo(lista *a)
{
	a->n = 0;
}

/* busca binaria */

int buscaBinaria(lista *a, elemento c)
{
	int pos, fim = a->n - 1, inicio = 0, meio = (inicio + fim) / 2;

	while(inicio < a->n && c.chave != a->v[meio].chave)
	{
		if(c.chave < a->v[meio].chave)
			fim = meio - 1;
		else
			inicio = meio + 1;
		
		meio = (inicio + fim) / 2;
	}
	if(c.chave == a->v[meio].chave)
		pos = meio;
	else
		pos = -1;
	return pos;
}

void ordena(lista *a)
{
  int aux;
	for(int i = a->n - 1; i > 0; i--)
  {
		for(int j = 0; j < i; j++)
    {
			if(a->v[j].chave > a->v[j + 1].chave)
      {
				aux = a->v[j].chave;
				a->v[j].chave = a->v[j + 1].chave;
				a->v[j + 1].chave = aux;
			}
		}
	}
}

/*
	LETRA A
*/
int ordenadoCrescente(lista *a)
{
	for(int i = 0; i < a->n - 1; i++)
	{
		if(a->v[i].chave > a->v[i + 1].chave)
			return 0;
	}
	return 1;
}

int ordenadoDecrescente(lista *a)
{
	for(int i = 0; i < a->n - 1; i++)
	{
		if(a->v[i].chave < a->v[i + 1].chave)
			return 0;
	}
	return 1;
}
/*
	FIM LETRA A
*/

/*
	LETRA B
*/
void copia(lista *a, lista *b)
{
	for(int i = 0; i < a->n; i++)
		b->v[i].chave = a->v[i].chave;
	b->n = a->n;
}

/*
	FIM LETRA B
*/

/*
	LETRA C
*/
int removerIndice(lista *a, int k)
{
	if(listaVazia(a)) return 0;

	if(k == a->n) return 0;

	for(int j = k; j < a->n - 1; j++)
		a->v[j].chave = a->v[j + 1].chave;
	a->n--;
	return 1;
}

int copiaNaoRepetidos(lista *a, lista *b)
{
	
	if(listaVazia(a)) return 0;
	copia(a, b);
	for(int i = 0; i < b->n; i++)
	{
		for(int j = i + 1; j < b->n; j++)
		{
			if(b->v[i].chave == b->v[j].chave)
				removerIndice(b, j);
		}
	}
	return 1;
}
/*
	FIM LETRA C
*/

/*
	LETRA D
*/
void inverter(lista *a, lista *b)
{
	for(int i = a->n - 1; i >= 0; i--)
	{
		for(int j = 0; j < a->n; j++)
			b->v[j].chave = a->v[i].chave;
	}
}
/*
	FIM LETRA D
*/

/*
	LETRA E
*/
void intercala(lista *a, lista *b, lista *c)
{
	int i = 0, j = 0;
	c->n = 0;
	ordena(a);
	copia(a, b);
	while(i < a->n)
	{
		if(j < b->n)
		{
			if(a->v[i].chave < b->v[j].chave)
			{
				c->v[c->n].chave = a->v[i].chave;
				i++;
			}
			else
			{
				c->v[c->n].chave = b->v[j].chave;
				j++;
			}
		}
		else
		{
			c->v[c->n].chave = a->v[i].chave;
			i++;
		}
		c->n++;
	}
}
/*
	FIM LETRA E
*/

/*
	LETRA F
*/
void contElem(lista *a, lista *b)
{
	for(int i = 0; i < a->n; i++)
	{
		copiaNaoRepetidos(a, b);
		b->v[i].count = 1;
		for(int j = i + 1; j < a->n; j++)
		{
			if(a->v[i].chave == a->v[j].chave)
				b->v[i].count++;
		}
		a->v[i].count = b->v[i].count;
	}
}

void exibirCont(lista *a)
{
	if(listaVazia(a))
		printf("nao ha elementos na lista\n");
	else
	{
		for(int i = 0; i < a->n; i++)
			printf("lista[%.2d]: %.2d, repeticoes: %d\t", i, a->v[i].chave, a->v[i].count);
		printf("\n");
	}
}

/*
	FIM LETRA F
*/

/*
	LETRA G
*/
int contarMaior(lista *a)
{
	int maior = 0, maiorpos;
	lista b;
	contElem(a, &b);
	for(int i = 0; i < b.n; i++)
	{
		if(maior < b.v[i].count)
		{
			maior = b.v[i].count;
			maiorpos = i;
		}
	}
	return maiorpos;
}

int contarMenor(lista *a)
{
	int menor = 99, menorpos;
	lista b;
	contElem(a, &b);
	for(int i = 0; i < b.n; i++)
	{
		if(menor > b.v[i].count)
		{
			menor = b.v[i].count;
			menorpos = i;
		}
	}
	return menorpos;
}
/*
	FIM LETRA G
*/
/* parar */
void parar()
{
	printf("pressione qualquer tecla para continuar...\n");
	fflush(stdin);
	getchar();
}

/* limpar a tela */
void limpar()
{
	for(int i = 0; i < 100; i++)
		printf("\n");
}