/*
  estrutura de dados I
  lista 4 - ex 6
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;

void Faith::alt(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

int main()
{
  Faith f = Faith();
  int x, y;

  cout << "insira dois valores: ";
  cin >> x >> y;

  cout << "antes da troca" << endl << "x: " << x << endl << "y: " << y << endl;
  f.alt(&x, &y);
  cout << "apos a troca: " << endl << "x: " << x << endl << "y: " << y << endl;

  return 0;
}