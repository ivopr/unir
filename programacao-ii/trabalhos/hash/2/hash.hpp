#include <stdio.h>
#include <string.h>
#include <iostream>
#define tamanho 26

typedef struct
{
    char inicial, nome[50];
    int link;
} tabela;

class Hash
{
    public:
        tabela pessoas[tamanho];
        Hash();
        int hash(char tipo);
        int hashOverflow();
        int inserir(char *nome);
        int exibir();
        int exibirPessoa(char *nome);
        int exibirPessoasPorInicial(char inicial);
};
