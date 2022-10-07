#include "hash.cpp"

int main()
{
    int menu;
    char tipo, desc[50];
    Hash h = Hash();

    do
    {
        limpar();
        printf("LEMBRE-SE: Todas as letras de categoria/tipo tem de ser digitadas em MAIUSCULO, caso contrario, nada vai funcionar!!\n");
        printf("1 - inserir item\n");
        printf("2 - listar itens em uma categoria/tipo\n");
        printf("3 - exibir a quantidade de produtos em cada tipo\n");
        printf("0 - sair\n");

        printf("menu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                limpar();
                printf("insira o tipo do item (A = Alimento, H = Higiene, L = Limpeza e V = Vestimenta)\ntipo> ");
                std::cin.ignore();
                tipo = std::cin.get();
                printf("insira uma descricao do item: ");
                std::cin.ignore();
                fgets(desc, 50, stdin);
                if(h.inserir(tipo, desc))
                    printf("inserido com sucesso\n");
                else
                    printf("nao foi possivel inserir, verifique o tipo especificado!\n");
                pararA();
            break;
            }

            case 2:
            {
                limpar();
                printf("qual tipo de item deseja exibir? (A = Alimento, H = Higiene, L = Limpeza, V = Vestimenta)\ntipo> ");
                std::cin.ignore();
                tipo = std::cin.get();
                h.exibir(tipo);
                parar();
            break;
            }

            case 3:
            {
                limpar();
                h.estoque();
                parar();
            break;
            }
        }
    } while(menu != 0);
    return 0;
}