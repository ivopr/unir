int Prog::buscaBinaria(int num)
{
  int pos, inicio = 0, final = tf -1, meio = (inicio + final) / 2;

  while(inicio < tf && num != vetor[meio])
  {
    if(num < vetor[meio])
      final = meio - 1;
    else
      inicio = meio + 1;

    meio = (inicio + final) / 2;
  }
  if(num == vetor[meio])
    pos = meio;
  else
    pos = -1;

  return pos;
}