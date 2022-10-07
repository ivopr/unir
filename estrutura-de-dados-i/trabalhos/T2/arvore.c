#include <arvore.h>

int altura(no *base)
{
	if(base == NULL)
		return 0;
	return base->altura;
}

int maior(int a, int b)
{
	return (a > b) ? a : b;
}

no *novoNo(int valor)
{
	no *novo = malloc(sizeof(no));
	novo->info = valor;
	novo->esq = novo->dir = NULL;
	novo->altura = 1;
	return novo;
}

no *rotacaoDir(no *base)
{
	no *a = base->esq;
	no *b = a->dir;
	a->dir = base;
	base->esq = b;
	base->altura = maior(altura(base->esq), altura(base->dir)) + 1;
	a->altura = maior(altura(a->esq), altura(a->dir)) + 1;
	return a;
}

no *rotacaoEsq(no *base)
{
	no *a = base->dir;
	no *b = a->esq;
	a->dir = base;
	base->dir = b;
	base->altura = maior(altura(base->esq), altura(base->dir)) + 1;
	a->altura = maior(altura(a->esq), altura(a->dir)) + 1;
	return a;
}

int balanceamento(no *base)
{
	if(base == NULL)
		return 0;
	return altura(base->esq) - altura(base->dir);
}

no *inserir(no *base, int valor)
{
	if(base == NULL)
		return novoNo(valor);
		
	if(valor < base->info)
		base->esq = inserir(base->esq, valor);
	else if(valor > base->info)
		base->dir = inserir(base->dir, valor);
	else
		return base;
		
	base->altura = 1 + maior(altura(base->esq), altura(base->dir));
	int fb = balanceamento(base);
	
	if(fb > 1 && valor < base->esq->info)
		return rotacaoDir(base);
		
	if(fb < -1 && valor > base->dir->info)
		return rotacaoEsq(base);
		
	if(fb > 1 && valor > base->esq->info)
	{
		base->esq = rotacaoEsq(base->esq);
		return rotacaoDir(base);
	}
	
	if(fb < -1 && valor < base->dir->info)
	{
		base->dir = rotacaoDir(base->dir);
		return rotacaoEsq(base);
	}
	
	return base;
}

void exibeInOrdem(no *base)
{
	if(base != NULL)
	{
		exibeInOrdem(base->esq);
		printf("%d\t", base->info);
		exibeInOrdem(base->dir);
	}
}

void exibePosOrdem(no *base)
{
	if(base != NULL)
	{
		exibePosOrdem(base->esq);
		exibePosOrdem(base->dir);
		printf("%d\t", base->info);
	}
}

void exibePreOrdem(no *base)
{
	if(base != NULL)
	{
		printf("%d\t", base->info);
		exibePreOrdem(base->esq);
		exibePreOrdem(base->dir);
	}
}

int contagemNos(no *base)
{
	if(base == NULL)
		return 0;
	int cont = 1;
	cont += contagemNos(base->esq);
	cont += contagemNos(base->dir);
	return cont;
}

int nivelNo(no *base, int valor, int nivel)
{
	if(base == NULL)
		return 0;
	if(base->info == valor)
		return nivel;
	return nivelNo(base->esq, valor, nivel + 1) | nivelNo(base->dir, valor, nivel + 1);
}

void busca(no *base, int valor)
{
	if(base != NULL)
	{
		if(base->info == valor)
			printf("no encontrado!\nendereco: %p\nvalor: %d\nendereco esq: %p\nendereco dir: %p\n", base, base->info, base->esq, base->dir);
		else
		{
			busca(base->esq, valor);
			busca(base->dir, valor);
		}
	}
}

void destruir(no *base)
{
	if(base != NULL)
	{
		destruir(base->esq);
		destruir(base->dir);
		free(base);
	}
}

no *remover(no *base, int valor)
{
	if(base == NULL)
		return base;
	if(valor < base->info)
		base->esq = remover(base->esq, valor);
	else if(valor > base->info)
		base->dir = remover(base->dir, valor);
	else
	{
		if(base->esq == NULL || base->dir == NULL)
		{
			no *temp;
			if(base->esq)
				temp = base->esq;
			else
				temp = base->dir;
			
			if(temp == NULL)
			{
				temp = base;
				base = NULL;
			}
			else
				base = temp;
			free(temp);
		}
		else
		{
			no *temp = menorValor(base->dir);
			base->info = temp->info;
			base->dir = remover(base->dir, temp->info);
		}
	}
	if(base == NULL)
		return base;
	base->altura = 1 + maior(altura(base->esq), altura(base->dir));
	int balanco = balanceamento(base);
	if(balanco > 1 && balanceamento(base->esq) >= 0)
		return rotacaoDir(base);
	if(balanco > 1 && balanceamento(base->esq) < 0)
	{
		base->esq = rotacaoEsq(base->esq);
		return rotacaoDir(base);
	}
	if(balanco < -1 && balanceamento(base->dir) <= 0)
		return rotacaoEsq(base);
	if(balanco < -1 && balanceamento(base->dir) > 0)
	{
		base->dir = rotacaoDir(base->dir);
		return rotacaoEsq(base);
	}
	return base;
}

no *menorValor(no *base)
{
	no *atual = base;
	while(atual->esq != NULL)
		atual = atual->esq;
	return atual;
}

void cls()
{
	for(int i = 0; i < 50; i++)
		printf("\n");
}

void pause()
{
	printf("pressione qualquer tecla para continuar...\n");
	getchar();
	getchar();
}