#include "hash.hpp"
Hash::Hash()
{
    for(int i = 0; i < tamanho; i++)
    {
        item[i].tipo = 'O';
        item[i].link = NULL;
    }
}

int Hash::hash(char tipo)
{
    return tipo % overflow;
}

int Hash::hashOverflow()
{
    for(int i = overflow; i < tamanho; i++)
    {
        if(item[i].tipo == 'O')
            return i;
        if(i + 1 == tamanho)
            i = 0;
    }
    return -1;
}

int Hash::inserir(char tipo, char desc[50])
{
    tipo = toupper(tipo);
    int endereco = hash(tipo);
    int enderecoOverflow = hashOverflow();
    if(endereco == -1)
        return 0;
    if(item[endereco].tipo == 'O')
    {
        item[endereco].tipo = tipo;
        strcpy(item[endereco].desc, desc);
        item[endereco].link = NULL;
        return 1;
    }
    else if(item[endereco].link == NULL)
    {
        item[endereco].link = enderecoOverflow;
        item[enderecoOverflow].tipo = tipo;
        strcpy(item[enderecoOverflow].desc, desc);
        item[enderecoOverflow].link = NULL;
        return 1;
    }
    else if(item[endereco].link != NULL)
    {
        item[enderecoOverflow].tipo = tipo;
        strcpy(item[enderecoOverflow].desc, desc);
        item[enderecoOverflow].link = item[endereco].link;
        item[endereco].link = enderecoOverflow;
        return 1;
    }
    return 0;
}

int Hash::exibir(char tipo)
{
    tipo = toupper(tipo);
    for(int i = hash(tipo); ; i = item[i].link)
    { 
        printf("desc: %s", item[i].desc);
        if(item[i].link == NULL)
            break;
    }
    return 0;
}

int Hash::estoque()
{
    int contA = 0, contH = 0, contL = 0, contV = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(item[i].tipo == 'A')
            contA++;
        if(item[i].tipo == 'H')
            contH++;
        if(item[i].tipo == 'L')
            contL++;
        if(item[i].tipo == 'V')
            contV++;
    }
    printf("Alimento: %2d produtos\nHigiene: %2d produtos\nLimpeza: %2d produtos\nVestimenta: %2d produtos\n", contA, contH, contL, contV);
    return 0;
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