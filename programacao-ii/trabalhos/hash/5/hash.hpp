#include <stdio.h>
#include <string.h>
#include <iostream>
#define tamanho 12

typedef struct Pessoas
{
    char nome[50];
    int dia, mes, ano;
    Pessoas *prox;
} pessoas;

class Hash
{
    public:
        pessoas tabela[tamanho];
        Hash();
        int hash();
        int inserir(char *nome, int dia, int mes, int ano);
        int aniversariantesMes(int mes);
        int superiorDezoito();
        int excluirNome(char *nome);
        int excluirMes(int mes);
};