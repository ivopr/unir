#include <stdio.h>
#include <iostream>
#define n 100

typedef struct
{
    int chave;
}elemento;

class lista
{
    public:
        elemento array[n];
        int ultimo;
        lista();


        int busca(int num);
        int inserir(int num);
        int remover(int num);
        void exibir();
        void inverter();
        void pausar();
        void limpar();
};