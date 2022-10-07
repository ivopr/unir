#include "Pilha.hpp"

void define (pilha *p)
{
	p->topo=-1;	
}
/* Cria pilha vazia. Deve ser usada antes de qqr outra opera��o opera��o */

int Push (tipo_elem c, pilha *p)
{
	if(p->topo==MAXP) return 0;
	p->topo++;
	p->A[p->topo].info=c.info;
	return 1;
}
/* Insere item no topo da pilha. Retorna true se sucesso, false c.c. */

int Vazia (pilha *p)
{
	return(p->topo==-1);
}
/* Retorna true se pilha vazia, false c.c. */

void Esvaziar (pilha *p)
{
	define(p);
}
/* Reinicializa pilha */

tipo_elem Top (pilha *p)
{
	return p->A[p->topo];
}
/* Devolve o elemento do topo sem remov�-lo. Chamada apenas se pilha n�o
vazia */

void Pop_up (pilha *p)
{
	p->topo--;
}
/* Remove item do topo da pilha. Chamada apenas se pilha n�o vazia */

tipo_elem Pop (pilha *p)
{
	Pop_up(p);
	return(p->A[p->topo+1]);
}
 /* Remove e retorna o item do topo da pilha. Chamada apenas se pilha
n�o vazia */
