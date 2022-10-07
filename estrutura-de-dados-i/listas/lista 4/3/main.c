/*
  estrutura de dados I
  lista 4 - ex 3
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows
*/
#include <azrael.h>

using namespace std;

void Faith::endMemRand(double *endMemo)
{
  srand(time(NULL));
  for(int i = 0; i < te; i++)
  {
    vetor[i] = rand() % MAX;
    endMemo = &vetor[i];
    cout << "vetor[" << i << "]: " << vetor[i] << endl
         << "endereco: " << endMemo << endl;
  }

}

int main()
{
  Faith f = Faith();
  double endMemo;

  f.endMemRand(&endMemo);
  return 0; 
}