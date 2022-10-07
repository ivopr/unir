#include "hash.cpp"

int main()
{
    int menu, codigo;
    float nota;
    char nome[50];
    Hash h = Hash();

    do
    {
        limpar();
        printf("1 - cadastrar aluno (codigo, nome e nota final)\n");
        printf("2 - consultar alunos aprovados (nota final >= 7)\n");
        printf("3 - consultar todos os alunos\n");
        printf("0 - sair\n");

        printf("menu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                limpar();
                printf("insira o codigo do aluno> ");
                scanf("%d", &codigo);
                printf("nome do aluno de codigo %d> ", codigo);
                std::cin.ignore();
                fgets(nome, 50, stdin);
                printf("nota final do aluno e codigo %d> ", codigo);
                scanf("%f", &nota);
                if(h.inserir(codigo, nome, nota))
                    printf("aluno cadastrado com sucesso\n");
                else
                    printf("nao foi possivel cadastrar o aluno, a tabela está cheia!\n");
                pararA();
            break;
            }

            case 2:
            {
                limpar();
                h.exibirAprovados();
                parar();
            break;
            }

            case 3:
            {
                limpar();
                h.exibir();
                parar();
            break;
            }
        }
    } while(menu != 0);
    return 0;
}