#include "hash.hpp"

Hash::Hash()
{
    for(int i = 0; i < tamanho; i++)
    {
        tabela[i].head = NULL;
        tabela[i].mes = i + 1;
    }
}

int Hash::hash(int mes)
{
    return mes % tamanho;
}

int Hash::inserir(char *nome, int dia, int mes, int ano)
{
    int endereco = hash(mes);
    if(tabela[endereco].head == NULL)
    {
        no *novo = new no;
        strcpy(novo->nome, nome);
        novo->dia = dia;
        novo->mes = mes;
        novo->ano = ano;
        novo->prox = NULL;
        tabela[endereco].head = novo;
        return 1;
    }
    else if(tabela[endereco].head != NULL)
    {
        no *novo = new no;
        strcpy(novo->nome, nome);
        novo->dia = dia;
        novo->mes = mes;
        novo->ano = ano;
        novo->prox = NULL;
        tabela[endereco].head->prox = novo;
        return 1;
    }
    else
    {
        no *novo = new no;
        strcpy(novo->nome, nome);
        novo->dia = dia;
        novo->mes = mes;
        novo->ano = ano;
        novo->prox = tabela[endereco].head->prox;
        tabela[endereco].head->prox = novo;
        return 1;
    }
    return 0;
}

int Hash::aniversariantesMes(int mes)
{
    no *atual = new no;
    int endereco = hash(mes);
    atual = tabela[endereco].head;
    while(atual != NULL)
    {
        printf("%.2d/%.2d/%.4d - %s", atual->dia, atual->mes, atual->ano, atual->nome);
        atual = atual->prox;
    }
    return 1;
}

int Hash::superiorDezoito()
{
    int cont = 0;
    no *atual = new no;
    for(int i = 0; i < tamanho; i++)
    {
        atual = tabela[i].head;
        while(atual != NULL)
        {
            if(2019 - atual->ano > 18)
                cont++;
            else if(2019 - atual->ano == 18)
            {
                if(11 - atual->mes > 0)
                    cont++;
                else if(11 - atual->mes == 0)
                {
                    if(11 - atual->dia >= 0)
                        cont++;
                }
            }
            atual = atual->prox;
        }
    }
    return cont;
}

int Hash::excluirNome(char *nome)
{
    no *atual, *antecessor = NULL;
    for(int i = 0; i < tamanho; i++)
    {
        atual = tabela[i].head;
        while(atual)
        {
            if(strcmp(atual->nome, nome) == 0)
            {
                if(antecessor == NULL)
                {
                    tabela[i].head = atual->prox;
                    free(atual);
                }
                else
                {
                    antecessor->prox = atual->prox;
                    free(atual);
                }
                return 1;
            }
        }
    }
    return 0;
}

int Hash::excluirMes(int mes)
{
    int endereco = hash(mes);
    tabela[endereco].head = NULL;
    return 1;
}

void parar()
{
    printf("pressione qualquer tecla para continuar...");
    std::cin.ignore();
    getchar();
}

void pararA()
{
    printf("pressione qualquer tecla para continuar...");
    getchar();
}

void limpar()
{
    for(int i = 0; i < 100; i++)
        printf("\n");
}