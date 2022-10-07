#include "banco.hpp"

void parar()
{
    std::cout << "pressione qualquer tecla para continuar";
    std::cin.ignore();
    std::cin.get();
}

void limpar()
{
    for(int i = 0; i < 100; i++)
        std::cout << std::endl;
}

conta banco::leCliente()
{
    using namespace std;
    conta cliente;
    cout << "insira o numero da conta: ";
    cin >> cliente.id;
    do
    {
        cout << "insira o tipo da conta: ";
        cin.ignore();
        cliente.tipo = cin.get();
    }while(!(cliente.tipo == 'C' || cliente.tipo == 'E'));
    cout << "insira o nome do cliente: ";
    cin.ignore();
    fgets(cliente.nome, 50, stdin);
    if(cliente.tipo == 'C')
        cliente.limite = 0;
    else
    {
        cout << "insira o limite da conta: ";
        cin >> cliente.limite;
    }
    cout << "insira o saldo da conta: ";
    cin >> cliente.saldo;
    return cliente;
}

void banco::adicionarCliente()
{
    using namespace std;
    conta cliente = leCliente();
    FILE *db = fopen(database, "rb");
    if(db == NULL)
        db = fopen(database, "wb");
    else
        db = fopen(database, "ab");
    fwrite(&cliente, sizeof(conta), 1, db);
    fclose(db);
}

void banco::exibirCliente(conta cliente)
{
    using namespace std;
    cout    << endl << "id> " << cliente.id << endl
            << "nome> " <<  cliente.nome 
            << "tipo> " << cliente.tipo << endl 
            << "limite> " << cliente.limite << endl 
            << "saldo> " << cliente.saldo << endl;
}

void banco::exibirTodosClientes()
{
    using namespace std;
    conta cliente;
    FILE *db = fopen(database, "rb");
    if(db == NULL)
        cout << "nao ha dados para serem exibidos" << endl;
    else
    {
        fread(&cliente, sizeof(conta), 1, db);
        while(!feof(db))
        {
            exibirCliente(cliente);
            fread(&cliente, sizeof(conta), 1, db);
        }
        fclose(db);
    }
}


void banco::buscarConta(int id)
{
    using namespace std;
    conta cliente;
    FILE *db = fopen(database, "rb");
    if(db == NULL) 
        cout << "nao ha dados para serem pesquisados" << endl;
    else
    {
        fread(&cliente, sizeof(conta), 1, db);
        while(!feof(db) && cliente.id != id)
            fread(&cliente, sizeof(conta), 1, db);
        if(!feof(db))
            exibirCliente(cliente);
        else
            cout << "nao existe uma conta com este numero" << endl;
        fclose(db);
    }
}