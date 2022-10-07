#include "hash.hpp"

Hash::Hash()
{
    for(int i = 0; i < tamanho; i++)
    {
        alunos[i].head = NULL;
        alunos[i].codigo = i;
    }
}

int Hash::hash(int codigo)
{
    return codigo % tamanho;
}

int Hash::inserir(int codigo, char *nome, float nota)
{
    int endereco = hash(codigo);
    if(alunos[endereco].head == NULL)
    {
        no *novo = new no;
        novo->codigo = codigo;
        strcpy(novo->nome, nome);
        novo->nota = nota;
        novo->prox = NULL;
        alunos[endereco].head = novo;
        return 1;
    }
    else if(alunos[endereco].head != NULL)
    {
        no *novo = new no;
        novo->codigo = codigo;
        strcpy(novo->nome, nome);
        novo->nota = nota;
        novo->prox = NULL;
        alunos[endereco].head->prox = novo;
        return 1;
    }
    else
    {
        no *novo = new no;
        novo->codigo = codigo;
        strcpy(novo->nome, nome);
        novo->nota = nota;
        novo->prox = alunos[endereco].head->prox;
        alunos[endereco].head->prox = novo;
        return 1;
    }
    return 0;
}

int Hash::exibir()
{
    no *atual = new no;
    for(int i = 0; i < tamanho; i++)
    {
        atual = alunos[i].head;
        if(atual != NULL)
        {
            do
            {
                printf("codigo> %d\nnome> %snota> %.2f\n", atual->codigo, atual->nome, atual->nota);
                atual = atual->prox;
            } while(atual != NULL);
        }
    }
    return 1;
}

int Hash::exibirAprovados()
{
    no *atual = new no;
    for(int i = 0; i < tamanho; i++)
    {
        atual = alunos[i].head;
        if(atual != NULL)
        {
            do
            {
                if(atual->nota >= 7.0)
                    printf("codigo> %d\nnome> %snota> %.2f\n", atual->codigo, atual->nome, atual->nota);
                atual = atual->prox;
            } while(atual != NULL);
        }
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