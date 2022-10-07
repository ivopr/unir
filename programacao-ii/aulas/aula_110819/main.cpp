#include "banco.cpp"

using namespace std;

int main()
{
    banco b = banco();
    conta cliente;
    int menu, id;

    do
    {
        limpar();
        
        cout    << "1 - adicionar um cliente" << endl
                << "2 - exibir todos os clientes" << endl
                << "3 - buscar cliente por numero da conta" << endl
                << "0 - sair" << endl
                << "menu> ";
        cin >> menu;

        switch(menu)
        {
            case 1:
            {
                limpar();
                b.adicionarCliente();
                cout << "cliente adicionado" << endl;
                parar();
            break;
            }

            case 2:
            {
                limpar();
                b.exibirTodosClientes();
                parar();
            break;
            }

            case 3:
            {
                limpar();
                cout << "numero da conta: ";
                cin >> id;
                b.buscarConta(id);
                parar();
            break;
            }
        }
        
    }while(menu != 0);
}