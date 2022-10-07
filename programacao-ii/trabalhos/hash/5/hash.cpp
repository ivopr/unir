#include "hash.hpp"

Hash::Hash()
{
    for(int i = 0; i < tamanho; i++)
    {
        tabela[i].mes = NULL;
    }
}

int Hash::hash()
{
    for(int i = 0; i < tamanho; i++)
        if(tabela[i].mes == NULL)
            return i;
    return -1;
}

int Hash::inserir(char *nome, int dia, int mes, int ano)
{
    int endereco = hash();
    if(endereco == -1)
        return 0;
    strcpy(tabela[endereco].nome, nome);
    tabela[endereco].dia = dia;
    tabela[endereco].mes = mes;
    tabela[endereco].ano = ano;
    return 1;
}

int Hash::aniversariantesMes(int mes)
{
    for(int i = 0; i < tamanho; i++)
        if(tabela[i].mes == mes)
            printf("%d/%d/%d - %s\n", tabela[i].dia, tabela[i].mes, tabela[i].ano, tabela[i].nome);
}

int Hash::superiorDezoito()
{
    int cont = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(tabela[i].ano > 0 && tabela[i].mes > 0 && tabela[i].dia > 0)
        {
            if(2019 - tabela[i].ano > 18)
                cont = cont + 1;
            else
            {
                if(11 - tabela[i].mes >= 0)
                    cont = cont + 1;
                else
                {
                    if(1 - tabela[i].dia >= 0)
                        cont = cont + 1;
                }
            }
        }
    }
    return cont;
}

int Hash::excluirNome(char *nome)
{
    int i;
    for(i = 0; i < tamanho, strcmp(tabela[i].nome, nome) == 1; i++);
    tabela[i].mes = 0;
    return 1;
}

int Hash::excluirMes(int mes)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(tabela[i].mes == mes)
            tabela[i].mes = NULL;
    }
    return 1;
}

void parar()
{
    printf("pressione qualquer tecla para continuar...");
    std::cin.ignore();
    getchar();
}


void limpar()
{
    for(int i = 0; i < 100; i++)
        printf("\n");
}