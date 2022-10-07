#include <stdio.h>
#include <iostream>

typedef struct No
{
    int elem, count;
    No *prox;
} no;

typedef struct
{
    no *head;
    no *tail;
} lista;

class Lista
{
    public:
        lista *l, *l1;
        Lista();
        void inserir(int elem);
        int ordenadaCrescente();
        int ordenadaDecrescente();
        int copiar();
        int copiarNaoRepetidos();
        void inverter();
        void intercalar();
        void relatorioRepeticaoNumeros();
        void relatorioMaisMenos();
};