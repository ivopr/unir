#include "hash.hpp"

Hash::Hash()
{
    for(int cont = 0, i = 13, j = 65; cont < tamanho; cont++)
    {
        pessoas[i].head = NULL;
        pessoas[i].inicial = (char)j;
        j++;
        i++;
        if(i == tamanho)
            i = 0;
    }
}

int Hash::hash(char inicial)
{
    return inicial % tamanho;
}

int Hash::inserir(char *nome)
{
    char inicial = toupper(nome[0]);
    int endereco = hash(inicial);
    if(pessoas[endereco].head == NULL)
    {
        no *novo = new no;
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        pessoas[endereco].head = novo;
        return 1;
    }
    else if(pessoas[endereco].head != NULL)
    {
        no *novo = new no;
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        pessoas[endereco].head->prox = novo;
        return 1;
    }
    else
    {
        no *novo = new no;
        strcpy(novo->nome, nome);
        novo->prox = pessoas[endereco].head->prox;
        pessoas[endereco].head->prox = novo;
        return 1;
    }
    return 0;
}

int Hash::exibir()
{
    no *atual = new no;
    for(int i = 0; i < tamanho; i++)
    {
        atual = pessoas[i].head;
        if(atual != NULL)
        {
            do
            {
                printf("nome> %s", atual->nome);
                atual = atual->prox;
            } while(atual != NULL);
        }
    }
    return 1;
}

int Hash::exibirPessoa(char *nome)
{
    char inicial = toupper(nome[0]);
    int endereco = hash(inicial);
    no *atual = new no;
    atual = pessoas[endereco].head;
    if(atual == NULL)
        return 1;
    do
    {
        if(strcmp(atual->nome, nome))
            return 1;
        atual = atual->prox;
    } while(atual->prox != NULL);
    return 0;
}

int Hash::exibirPessoasPorInicial(char inicial)
{
    inicial = toupper(inicial);
    int endereco = hash(inicial);
    no *atual = new no;
    atual = pessoas[endereco].head;
    do
    {
        if(atual == NULL)
            return 0;
        printf("nome> %s", atual->nome);
        atual = atual->prox;
    } while(1);
    return 1;
}

void limpar()
{
    for(int i = 0; i < 100; i++)
        printf("\n");
}
void parar()
{
    printf("pressione uma tecla para continuar...");
    std::cin.ignore();
    std::cin.get();
}
void pararA()
{
    printf("pressione uma tecla para continuar...");
    std::cin.get();
}