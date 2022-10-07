#include <stdio.h>
#include <string.h>
#include <iostream>
#define tamanho 15

typedef struct No
{
    int codigo;
    float nota;
    char nome[50];
    No *prox;
} no;

typedef struct
{
    int codigo;
    no *head;
} parTab;

class Hash
{
    public:
        parTab alunos[tamanho];
        Hash();
        int hash(int codigo);
        int inserir(int codigo, char *nome, float nota);
        int exibir();
        int exibirAprovados();
};
