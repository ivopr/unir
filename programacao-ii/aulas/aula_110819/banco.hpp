#include <iostream>
#include <string>
#define database "database.dat"

typedef struct
{
    int id;
    char tipo, nome[50];
    float saldo, limite;
}conta;

class banco
{
    public:
        conta leCliente();
        void adicionarCliente();
        void exibirCliente(conta c);
        void exibirTodosClientes();
        void buscarConta(int id);
};