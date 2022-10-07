#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#define tamanho 12

typedef struct No
{
    char nome[50];
    int dia, mes, ano;
    No *prox;
} no;

typedef struct
{
    int mes;
    no *head;
} parTab;

class Hash
{
    public:
        parTab tabela[tamanho];
        Hash();
        int hash(int mes);
        int inserir(char *nome, int dia, int mes, int ano);
        int aniversariantesMes(int mes);
        int superiorDezoito();
        int excluirNome(char *nome);
        int excluirMes(int mes);
};