#include <stdio.h>
#include <vector>

// Andreia De Oliveira

using namespace std;

int merge(vector<int> &vetor, int init, int quite, int end)
{
  int k = 0;
  int i = init;
  int j = quite + 1;
  int temp[(end - init) + 1];

  int inversion = 0;

  while (i <= quite && j <= end)
  {
    // printf("\nComparacao = %d < %d \n\n", vetor[i], vetor[j]);

    if ((vetor[i] < vetor[j]))
    {
      temp[k++] = vetor[i++];
    }
    else
    {
      inversion++;
      temp[k++] = vetor[j++];
    }
    if ((temp[i + 1] < temp[j - 1]))
    {
      inversion++;
    }
  }

  while (i <= quite)
  {
    temp[k++] = vetor[i++];
  }
  while (j <= end)
  {
    temp[k++] = vetor[j++];
  }

  for (k = init; k <= end; k++)
  {
    vetor[k] = temp[k - init];
  }

  return inversion;
}

void mergesort(vector<int> &list, int init, int end, int &result)
{
  int quite;
  if (init < end)
  {
    quite = (init + end) / 2;
    mergesort(list, init, quite, result);
    mergesort(list, quite + 1, end, result);
    result += merge(list, init, quite, end);
  }
  // printf("%d ", result);
}

int main()
{

  int len = 0;
  vector<int> list;
  int result = 0;

  // leitura do tamanho do vetor
  scanf("%d", &len);

  // leitura do vetor que terá as inversões
  for (int i = 0; i < len; i++)
  {
    int aux = 0;
    scanf("%d", &aux);
    list.push_back(aux);
  }
  mergesort(list, 0, len - 1, result);
  printf("%d", result);
  return 0;
}