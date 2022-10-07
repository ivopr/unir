#include "lista.hpp"

Lista::Lista()
{
    l->head = NULL;
    l->tail = l->head;
    l1->head;
    l1->tail = l1->head;
}

void Lista::inserir(int elem)
{
    no *novo = new no;
    if(l->head == NULL)
    {
        novo->elem = elem;
        novo->prox = NULL;
        l->head = novo;
        l->tail = l->head;
    }
    else if(l->head != NULL)
    {
        novo->elem = elem;
        novo->prox = NULL;
        l->tail->prox = novo;
        l->tail = l->tail->prox;
    }
}

int Lista::ordenadaCrescente()
{
    no *ant = l->head, *atual = ant->prox;
    while(atual != NULL)
    {
        if(atual->elem < ant->elem)
            return 0;
    }
    return 1;
}

int Lista::ordenadaDecrescente()
{
    no *ant = l->head, *atual = ant->prox;
    while(atual != NULL)
    {
        if(atual->elem > ant->elem)
            return 0;
    }
    return 1;
}

int Lista::copiar()
{
    no *atual = l->head, *atual_l1 = l1->head;
    atual_l1 = atual;
    atual = atual->prox;
    while(atual != NULL)
    {
        atual_l1->prox = atual;
        atual_l1 = atual_l1->prox;
        atual = atual->prox;
    }
    return 1;
}

int Lista::copiarNaoRepetidos()
{
    
}
