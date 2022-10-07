/*
  estrutura de dados I
  lista 4 - ex 5
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;

int Faith::pot(int base, int potencia)
{
  return pow(base, potencia);
}

int main()
{
  int base, potencia;
  Faith f = Faith();

  cout << "insira a base e a potencia: ";
  cin >> base >> potencia;

  cout << base << "^" << potencia << " = " << f.pot(base, potencia) << endl;

  return 0;
}