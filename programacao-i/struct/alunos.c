#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tf 100

  //define um novo tipo (int, void, etc...) com o nome turma.
  typedef struct {
    char nome[tf];
    int matricula, tl;
    double nota, nota1, nota2;
  } turma; //sim, o nome da classe fica aqui embaixo por que não é o que a professora ensinou. aqui você ta definindo um novo tipo, não só criando um struct

  //função para inserir os dados dos alunos numa turma
  void insere(turma alunos[tf]) {
    printf("qual o tamanho da turma? ");
    scanf("%d", &alunos->tl); //aqui se usa -> pois a variavel alunos não é um vetor, logo, não e um ponteiro. e não me pergunta porque isso funciona porque eu também não sei...
    for(int i = 0; i < alunos->tl; i++) {
      system("cls");
      printf("aluno %d\n", i);
      printf("nome: ");
      fflush(stdin); //limpa o teclado antes de ler o nome do indivíduo...
      fgets(alunos[i].nome, tf, stdin); //recebe o nome completo da pessoa. foi usado o fgets por causa dos espaços.. pois é.. o scanf não lê nada depos de um espaço.
      printf("matricula: ");
      scanf("%d", &alunos[i].matricula); //aqui é o que você já sabe...

      printf("\nnotas\n");
      printf("prova 1: ");
      scanf("%lf", &alunos[i].nota); //aqui é o que você já sabe...
      printf("prova 2: ");
      scanf("%lf", &alunos[i].nota1); //aqui é o que você já sabe...
      printf("prova 3: ");
      scanf("%lf", &alunos[i].nota2); //aqui é o que você já sabe...
      system("pause");
    }//for i
  }//função

  //função para exibir os dados inseridos, não preciso comentar o que cada coisa faz, eu acho....
  void exibe(turma alunos[tf]) {
    for(int i = 0; i < alunos->tl; i++) {
      system("cls");
      printf("\naluno %d\n", i);
      printf("nome: %s", alunos[i].nome);
      printf("matricula: %d\n", alunos[i].matricula);
      printf("notas\n");
      printf("prova 1: %.2lf\n", alunos[i].nota);
      printf("prova 2: %.2lf\n", alunos[i].nota1);
      printf("prova 3: %.2lf\n", alunos[i].nota2);
      printf("media: %.2lf\n", (alunos[i].nota + alunos[i].nota1 + alunos[i].nota2) / 3);
      system("pause");
    }//for i
  }//função

  //função para exportar os dados inseridos no programa
  void exporta(turma alunos[tf]) {
    system("cls");
    char file[30], buf[30]; //definir duas variaveis char para o nome do arquivo
    printf("com qual nome de arquivo deseja salvar? ");
    scanf("%s", &file); //recebe o nome do arquivo que vai ser gerado com as informações dos alunos
    snprintf(buf, sizeof(buf), "%s.txt", file); //faz com que o nome recebido anteriormente ganhe um .txt no final
    FILE *f = fopen(buf, "a"); //abre o documento de nome buf, é basicamente o nome que você inseriu no scanf com o .txt que foi adicionado no comando anterior
    for(int i = 0; i < alunos->tl; i++) {
      fprintf(f, "aluno %d\n", i); //escreve alunos indice
      fprintf(f, "nome: %s", alunos[i].nome); //escreve o nome do aluno
      fprintf(f, "matricula: %d\n", alunos[i].matricula); //escreve a matricula do aluno
      fprintf(f, "notas\n"); //escreve 'notas'
      fprintf(f, "prova 1: %.2lf\n", alunos[i].nota); //escreve a primeira nota do aluno
      fprintf(f, "prova 2: %.2lf\n", alunos[i].nota1); //escreve a segunda nota do aluno
      fprintf(f, "prova 3: %.2lf\n", alunos[i].nota2); //escreve a terceira nota do aluno
      fprintf(f, "media: %.2lf\n", (alunos[i].nota + alunos[i].nota1 + alunos[i].nota2) / 3); //escreve a média aritmetica do aluno
      fprintf(f, "────────────────────────────────────────────────────────────────────────────────\n"); //escreve um separador
    }//for i
    fclose(f); //fecha o arquivo
    printf("EXPORTADO COM SUCESSO PARA O ARQUIVO %s\n", buf);
    system("pause");
    system("cls");
  }//função
  //NOTE QUE O FPRINTF NÃO EXIBE NADA NA TELA, E É PRA ISSO ACONTECER MESMO, ENTÃO NÃO TILTA NÃO

  //aqui é a função principal, onde a gente tem o menu e blá blá blá
  int main() {
    turma t1[tf], t2[tf]; //define os vetores de alunos da classe turma ── veja a classe no começo do código, no struct.
    int menu = 999;

    while(menu != 0) {
      printf("1 - inserir turma 1\n");
      printf("2 - inserir turma 2\n");
      printf("3 - exibir turma 1\n");
      printf("4 - exibir turma 2\n");
      printf("5 - exportar turma 1\n");
      printf("6 - exportar turma 2\n");
      printf("0 - sair\n");

      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          insere(t1);
          system("pause");
          system("cls");
        break;
        case 2:
          insere(t2);
          system("pause");
          system("cls");
        break;
        case 3:
          exibe(t1);
        break;
        case 4:
          exibe(t2);
        break;
        case 5:
          exporta(t1);
        break;
        case 6:
          exporta(t2);
        break;
      }//switch
    }//while
  return 0;
}//main
