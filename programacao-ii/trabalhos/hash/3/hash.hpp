#include <stdio.h>
#include <string.h>
#include <iostream>
#define tamanho 26

typedef struct No
{
    char nome[50];
    No *prox;
} no;

typedef struct
{
    char inicial;
    no *head;
} parTab;

class Hash
{
    public:
        parTab pessoas[tamanho];
        Hash();
        int hash(char tipo);
        int hashOverflow();
        int inserir(char *nome);
        int exibir();
        int exibirPessoa(char *nome);
        int exibirPessoasPorInicial(char inicial);
};
