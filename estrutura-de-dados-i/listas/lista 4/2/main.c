/*
  estrutura de dados I
  lista 4 - ex 2
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;

void Faith::endMem()
{
  cout << "enderecos de memoria: " << endl;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cout << "matriz[" << i << "][" << j << "]: " << &matriz[i][j] << endl;
    }
  }
}

int main()
{ 
  Faith f = Faith();

  f.endMem();
  return 0;
}