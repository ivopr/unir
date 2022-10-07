#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#define tamanho 30
#define overflow 26

typedef struct
{
    char tipo, desc[50];
    int link;
} tabela;

class Hash
{
    public:
        tabela item[tamanho];
        Hash();
        int hash(char tipo);
        int hashOverflow();
        int inserir(char tipo, char desc[50]);
        int exibir(char tipo);
        int estoque();
};
