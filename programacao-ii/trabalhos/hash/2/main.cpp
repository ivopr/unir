#include "hash.cpp"

int main()
{
    int menu;
    char inicial, nome[50];
    Hash h = Hash();

    do
    {
        limpar();
        printf("1 - inserir apenas o nome\n");
        printf("2 - consultar todas as pessoas\n");
        printf("3 - consultar uma pessoa\n");
        printf("4 - consultar todas as pessoas com uma inicial\n");
        printf("0 - sair\n");

        printf("menu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                limpar();
                printf("insira o nome que deseja inserir: ");
                std::cin.ignore();
                fgets(nome, 50, stdin);
                if(h.inserir(nome))
                    printf("inserido com sucesso\n");
                else
                    printf("nao foi possivel inserir, a tabela está cheia!\n");
                pararA();
            break;
            }

            case 2:
            {
                limpar();
                h.exibir();
                parar();
            break;
            }

            case 3:
            {
                limpar();
                printf("qual o nome que deseja buscar: ");
                std::cin.ignore();
                fgets(nome, 50, stdin);
                if(h.exibirPessoa(nome))
                    printf("a pessoa pesquisada se encontra na tabela.\nnome> %s", nome);
                else
                    printf("a pessoa pesquisada nao se encontra na tabela.\nnome> %s", nome);
                pararA();
            break;
            }

            case 4:
            {
                limpar();
                printf("qua inicial buscar: ");
                std::cin.ignore();
                inicial = std::cin.get();
                h.exibirPessoasPorInicial(inicial);
                parar();
            break;
            }
        }
    } while(menu != 0);
    return 0;
}