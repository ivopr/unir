#include "hash.hpp"

Hash::Hash()
{
    for(int i = 0; i < tamanho; i++)
    {
        pessoas[i].inicial = NULL;
        pessoas[i].link = NULL;
    }
}

int Hash::hash(char inicial)
{
    return inicial % tamanho;
}

int Hash::hashOverflow()
{
    for(int i = 0; i < tamanho; i++)
    {
        if(pessoas[i].inicial == NULL)
            return i;
    }
    return -1;
}

int Hash::inserir(char *nome)
{
    char inicial = nome[0];
    inicial = toupper(inicial);
    int endereco = hash(inicial);
    int enderecoOverflow = hashOverflow();
    if(pessoas[endereco].inicial == NULL)
    {
        pessoas[endereco].inicial = inicial;
        strcpy(pessoas[endereco].nome, nome);
        pessoas[endereco].link = NULL;
        return 1;
    }
    else if(pessoas[endereco].link == NULL)
    {
        pessoas[endereco].link = enderecoOverflow;
        pessoas[enderecoOverflow].inicial = inicial;
        strcpy(pessoas[enderecoOverflow].nome, nome);
        pessoas[enderecoOverflow].link = NULL;
        return 1;
    }
    else if(pessoas[endereco].link != NULL)
    {
        pessoas[enderecoOverflow].inicial = inicial;
        strcpy(pessoas[enderecoOverflow].nome, nome);
        pessoas[enderecoOverflow].link = pessoas[endereco].link;
        pessoas[endereco].link = enderecoOverflow;
        return 1;
    }
    return 0;
}

int Hash::exibir()
{
    for(int i = 0; i < tamanho; i++)
    {
        if(pessoas[i].inicial != NULL)
            printf("nome: %s", pessoas[i].nome);
    }
    return 1;
}

int Hash::exibirPessoa(char *nome)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(strcmp(pessoas[i].nome, nome))
            return 1;
    }
    return 0;
}

int Hash::exibirPessoasPorInicial(char inicial)
{
    inicial = toupper(inicial);
    printf("id - nome\n");
    for(int i = 0; i < tamanho; i++)
    {
        if(pessoas[i].inicial == inicial)
            printf("%d - %s", i + 1, pessoas[i].nome);
    }
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