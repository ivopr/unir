#include <iostream>

typedef struct
{
    int num;
}info;

typedef struct No
{
    info data;
    No *esq, *dir;
}no;

typedef struct
{
    no *raiz;
}arvore;

class Arvore
{
    public:
        arvore a1;
        void imprimir();
        int preOrdem();
};