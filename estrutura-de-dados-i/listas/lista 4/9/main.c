/*
  estrutura de dados I
  lista 4 - ex 9
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;

typedef struct
{
  int numemp;
  char nomemp[20], endereco[20];
  int dia, mes, ano;
  float salario;
} ficha;

int main()
{
  ficha vfichas[10];
  int i;
  for (i = 0; i <= 10; i++)
  {
    printf("\nentre com o numero do empregado: ");
    scanf("%d", &vfichas[i].numemp);
    
    printf("\nentre com o nome do empregado: ");
    scanf("%s", vfichas[i].nomemp);
    
    printf("\nentre com o endereco do empregado: ");
    fflush(stdin);
    cin.getline(vfichas[i].endereco, 20);
    
    printf("\nentre com o dia da admissao: ");
    scanf("%d", &vfichas[i].dia);
    
    printf("\nentre com o mes da admissao: ");
    scanf("%d", &vfichas[i].mes);

    printf("\nentre com o ano da admissao: ");
    scanf("%d", &vfichas[i].ano);

    printf("\nentre com o salario do empregado: ");
    scanf("%f", &vfichas[i].salario);
    
  } //end for
  for(i = 0; i <= 10; i++)
  {
    printf("%d\n", vfichas[i].numemp);
    printf("%s\n", vfichas[i].nomemp);
    printf("%s\n", vfichas[i].endereco);
    printf("%d\n", vfichas[i].dia);
    printf("%d\n", vfichas[i].mes);
    printf("%d\n", vfichas[i].ano);
    printf("%f\n", vfichas[i].salario);
  } // end for

  return 0;
} // end main