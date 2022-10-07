/*
  estrutura de dados I
  lista 4 - ex 7
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;

double x, y;
void  troca_ab(int a, int b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
}

int main()
{
  int a,b;
  a=10;
  b=20;
  troca_ab(b,a);
  if ((a > 5) && (b < 15)){
    x = a / 3 + b / 2;
    y = a;
  }
  else
  {
    x = a;
    y = (a > b);
  }
  cout << "a = " << a << ", b = " << b << endl;
  cout << "x = " << x << ", y = " << y << endl;

  return 0;
}