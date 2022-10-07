#include <stdio.h>
#include <stdbool.h>
#define MAXP 100


typedef struct
{
    int info;
}tipo_elem;

typedef struct
{
    tipo_elem A[MAXP];
    int topo;
}pilha;

void Define (pilha *p);
/* Cria pilha vazia. Deve ser usada antes de qqr outra opera��o opera��o */
int Push (tipo_elem c, pilha *p);
/* Insere item no topo da pilha. Retorna true se sucesso, false c.c. */
int Vazia (pilha *p);
/* Retorna true se pilha vazia, false c.c. */
void Esvaziar (pilha *p);
/* Reinicializa pilha */
tipo_elem Top (pilha *p);
/* Devolve o elemento do topo sem remov�-lo. Chamada apenas se pilha n�o
vazia */
void Pop_up (pilha *p);
/* Remove item do topo da pilha. Chamada apenas se pilha n�o vazia */
tipo_elem Pop (pilha *p);
 /* Remove e retorna o item do topo da pilha. Chamada apenas se pilha
n�o vazia */

