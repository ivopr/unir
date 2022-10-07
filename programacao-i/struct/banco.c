#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tf 100

  typedef struct {
    char nome[tf], tipo;
    int conta, tl;
    double limite, saldo;
  } banco;

  //inserir clientes
  void insere(banco clientes[tf]) {
    printf("quantos clientes? ");
    scanf("%d", &clientes->tl);
    for(int i = 0; i < clientes->tl; i++) {
      printf("nome: ");
      fflush(stdin); //limpa o teclado pra não pegar sujeira
      fgets(clientes[i].nome, 30, stdin); //recebe e guarda o nome completo do indivíduo
      printf("tipo de conta: ");
      scanf("%c", &clientes[i].tipo); //pega o tipo da conta do indivíduo (c ou e)
      printf("numero da conta: ");
      scanf("%d", &clientes[i].conta); //numero da conta
      printf("limite da conta: ");
      scanf("%lf", &clientes[i].limite); //limite da conta
      printf("saldo na conta: ");
      scanf("%lf", &clientes[i].saldo); //saldo q tem
    }//for i
  }//função insere

  //função para exibir o último cliente inserido no programa
  //clientes->tl - 1 é pra pegar o ultimo ID inserido, como é uma função 'estática' o ultimo id sempre vai ser o valor de tl - 1, tl, nesse caso ta dentro da variável clientes, que por sua vez é um ponteiro, por iso o '->'
  /* void exibe(banco clientes[tf]) {
      printf("nome: %s", clientes[clientes->tl - 1].nome);
      printf("tipo de conta: %c\n", clientes[clientes->tl - 1].tipo);
      printf("numero da conta: %d\n", clientes[clientes->tl - 1].conta);
      printf("limite: %.2lf\n", clientes[clientes->tl - 1].limite);
      printf("saldo: %.2lf\n", clientes[clientes->tl - 1].saldo);
   }//função exibe
  */

    void exibecomum(banco clientes[tf]) {
      for(int i = 0; i < clientes->tl; i++) {
        if(clientes[i].tipo == 'c') {
          printf("nome: %s", clientes[i].nome);
          printf("tipo de conta: %c\n", clientes[i].tipo);
          printf("numero da conta: %d\n", clientes[i].conta);
          printf("limite: %.2lf\n", clientes[i].limite);
          printf("saldo: %.2lf\n", clientes[i].saldo);
        } //if conta comum
      }//for i
    }//função exibe

    void exibeesp(banco clientes[tf]) {
      for(int i = 0; i < clientes->tl; i++) {
        if(clientes[i].tipo == 'e') {
          printf("nome: %s", clientes[i].nome);
          printf("tipo de conta: %c\n", clientes[i].tipo);
          printf("numero da conta: %d\n", clientes[i].conta);
          printf("limite: %.2lf\n", clientes[i].limite);
          printf("saldo: %.2lf\n", clientes[i].saldo);
        } //if conta especial
      }//for i
    }//função exibe

  //função para exportar os dados do programa para um arquivo.txt
  void exporta(banco clientes[tf]) {
    char file[30], buf[30]; //definir duas variaveis char para o nome do arquivo
    printf("com qual nome de arquivo deseja salvar? ");
    scanf("%s", &file); //recebe o nome do arquivo que vai ser gerado com as informações dos alunos
    snprintf(buf, sizeof(buf), "%s.txt", file); //faz com que o nome recebido anteriormente ganhe um .txt no final
    FILE *f = fopen(buf, "a"); //abre o documento de nome buf, é basicamente o nome que você inseriu no scanf com o .txt que foi adicionado no comando anterior
    for(int i = 0; i < clientes->tl; i++) {
      fprintf(f, "cliente %d\n", i); //escreve o id do cliente
      fprintf(f, "nome: %s", clientes[i].nome); //escreve o nome do cliente
      fprintf(f, "tipo da conta: %c\n", clientes[i].tipo); //escreve o tipo da conta
      fprintf(f, "numero da conta: %d\n", clientes[i].conta); //escreve o numero da conta
      fprintf(f, "limite: %.2lf\n", clientes[i].limite); //escreve o limite que a conta possui
      fprintf(f, "saldo: %.2lf\n", clientes[i].saldo); //escreve o saldo que tem na conta
      fprintf(f, "────────────────────────────────────────────────────────────────────────────────\n"); //separador
    }//for i
    fclose(f);
    printf("EXPORTADO COM SUCESSO PARA O ARQUIVO %s\n", buf);
  }//função exporta

  //aqui é a função principal, onde a gente tem o menu e blá blá blá
  int main() {
    banco clientes[tf]; //define os vetores de alunos da classe turma ── veja a classe no começo do código, no struct.
    int menu = 999;

    while(menu != 0) {
      printf("1 - Cadastrar\n");
      printf("2 - Exibir contas comuns\n");
      printf("3 - Exibir contas especiais\n");
      printf("4 - Exportar\n");
      printf("0 - Sair\n");

      printf("\nO que deseja fazer? ");
      scanf("%d", &menu);
      switch(menu) {
        case 1:
          insere(clientes);
          system("pause");
          system("cls");
        break;
        case 2:
          exibecomum(clientes);
          system("pause");
          system("cls");
        break;
        case 3:
          exibeesp(clientes);
          system("pause");
          system("cls");
        break;
        case 4:
          exporta(clientes);
          system("pause");
          system("cls");
        break;
      }//switch
    }//while
  return 0;
}//main
