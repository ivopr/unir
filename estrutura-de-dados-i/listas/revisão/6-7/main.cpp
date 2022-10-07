#include "lista.cpp"

int main()
{
    int num, menu;
    lista l = lista();

    do
    {
        l.limpar();
        printf("1 - inserir\n2 - remover\n3 - buscar\n4 - exibir\n5 - inverter\nmenu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                printf("insira um número: ");
                scanf("%d", &num);
                l.inserir(num);
            break;
            }

            case 2:
            {
                printf("remova um número: ");
                scanf("%d", &num);
                l.remover(num);
            break;
            }

            case 3:
            {
                printf("busque um número: ");
                scanf("%d", &num);

                if(l.busca(num) != 0)
                    printf("número encontrado no índice %d\n", l.busca(num));
                else
                    printf("número não encontrado na lista\n");
                l.pausar();
            break;
            }

            case 4:
            {
                l.exibir();
                l.pausar();
            break;
            }

            case 5:
            {
                l.inverter();
                printf("invertido\n");
                l.pausar();
            break;
            }
        }
    } while(menu != 0);
    return 0;
}