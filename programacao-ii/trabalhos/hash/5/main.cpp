#include "hash.cpp"

int main()
{
    int menu, dia, mes, ano;
    char nome[50];
    Hash h = Hash();

    do
    {
        limpar();
        printf("1 - cadastrar amigo\n");
        printf("2 - aniversariantes do mes\n");
        printf("3 - contar pessoas com idade superior a 18 anos\n");
        printf("4 - excluir pessoa por nome\n");
        printf("5 - excluir pessoas de um determinado mes\n");
        printf("0 - sair\n");

        printf("menu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                limpar();
                printf("nome: ");
                std::cin.ignore();
                fgets(nome, 50, stdin);
                printf("data de nascimento (xx xx xxxx): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                if(h.inserir(nome, dia, mes, ano))
                    printf("inserido com sucesso!\n");
                else
                    printf("nao foi possivel inserir\n");
                parar();
            break;
            }

            case 2:
            {
                limpar();
                printf("deseja exibir os aniversariantes de que mes? ");
                scanf("%d", &mes);
                h.aniversariantesMes(mes);
                parar();
            break;
            }

            case 3:
            {
                limpar();
                printf("existem %d pessoas maiores de 18 anos inseridas\n", h.superiorDezoito());
                parar();
            break;
            }

            case 4:
            {
                limpar();
                printf("quem deseja remover da lista? ");
                std::cin.ignore();
                fgets(nome, 50, stdin);
                h.excluirNome(nome);
                printf("removido> %s", nome);
                parar();
            break;
            }

            case 5:
            {
                limpar();
                printf("qual mes deseja apagar? ");
                scanf("%d", &mes);
                h.excluirMes(mes);
                printf("aniversariantes do mes %d excluidos com sucesso!\n", mes);
                parar();
            break;
            }
        }
    } while(menu != 0);
}