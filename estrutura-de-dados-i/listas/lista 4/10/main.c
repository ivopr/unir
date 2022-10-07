/*
  estrutura de dados I
  lista 4 - ex 10
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;
typedef struct
{
  int rg, num_casa, idade;
  char nome[20], rua[20];
} pessoas;

int main()
{
  int soma = 0, menorid, maiorid, menor = 999, maior = 0;
  pessoas pessoa[7];

  for(int i = 0; i < 7; i++)
  {
    //entrada de dados
    cout << "rg: ";
    cin >> pessoa[i].rg;

    cout << "nome: ";
    cin >> pessoa[i].nome;

    cout << "idade: ";
    cin >> pessoa[i].idade;

    cout << "endereco (rua): ";
    cin >> pessoa[i].rua;

    cout << "numero da residencia: ";
    cin >> pessoa[i].num_casa;

    // verifica quem é o mais novo e o mais velho e salta os ids deles...
    if(pessoa[i].idade < menor)
    {
      menor = pessoa[i].idade;
      menorid = i;
    }
    if(pessoa[i].idade > maior)
    {
      maior = pessoa[i].idade;
      maiorid = i;
    }

    //soma das idades de todos
    soma += pessoa[i].idade;
  }

  for(int i = 0; i < 7; i++)
  {
    cout << "rg: " << pessoa[i].rg << endl;
    cout << "nome: " << pessoa[i].nome << endl;
    cout << "idade: " << pessoa[i].idade << endl;
    cout << "endereco: Rua/Av. " << pessoa[i].rua << ", " << pessoa[i].num_casa << endl; 
  }
  cout << endl << endl;

  cout << "os dados da pessoa mais nova: " << endl;

    cout << "rg: " << pessoa[menorid].rg << endl;
    cout << "nome: " << pessoa[menorid].nome << endl;
    cout << "idade: " << pessoa[menorid].idade << endl;
    cout << "endereco: Rua/Av. " << pessoa[menorid].rua << ", " << pessoa[menorid].num_casa << endl; 
  cout << endl;
  
  cout << "os dados da pessoa mais velha: " << endl;

    cout << "rg: " << pessoa[maiorid].rg << endl;
    cout << "nome: " << pessoa[maiorid].nome << endl;
    cout << "idade: " << pessoa[maiorid].idade << endl;
    cout << "endereco: Rua/Av. " << pessoa[maiorid].rua << ", " << pessoa[maiorid].num_casa << endl;
  cout << endl;

  cout << "a idade media eh: " << soma / 7 << endl;

  parar();
  return 0;
}