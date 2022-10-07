#include "lista.hpp"

lista::lista()
{
    ultimo = 0;
}

int lista::busca(int num)
{
    int i;
    for(i = 0; i <= ultimo; i++)
    {
        if(array[i].chave == num)
            return i;
    }
    return -1;
}

int lista::inserir(int num)
{
    if(ultimo < n)
    {
        if(busca(num) != -1)
        {
            printf("número já inserido na lista.\n");
            pausar();
            return -1;
        }
        array[ultimo].chave = num;
        ultimo = ultimo + 1;
        printf("número inserido com sucesso!\n");
        pausar();
        return 1;
    }
    else
    {
        printf("a lista está cheia, não é possível inserir mais números.\n");
        pausar();
        return 0;
    }
}

int lista::remover(int num)
{
    if(busca(num) != -1)
    {
        printf("não é possível remover o número pois ele não está presente na lista.\n");
        pausar();
        return 0;
    }
    else
    {
        for(int i = busca(num); i <= ultimo - 1; i++)
        {
            array[i] = array[i + 1];
        }
        ultimo = ultimo - 1;
        return 1;
    }
}

void lista::exibir()
{
    for(int i = 0; i <= ultimo - 1; i++)
    {
        printf("idx: %d, chave: %d\n", i, array[i].chave);
    }
}

void lista::inverter()
{
    int aux, i, j;
    for(i = 0, j = ultimo - 1; i < j; i++, j--)
    {
        aux = array[i].chave;
        array[i] = array[j];
        array[j].chave = aux;
    }
}

void lista::pausar()
{
    printf("pressione qualquer tecla para continuar.");
    std::cin.ignore();
    std::cin.get();
}

void lista::limpar()
{
    for(int i = 0; i < 100; i++)
        printf("\n");
}
