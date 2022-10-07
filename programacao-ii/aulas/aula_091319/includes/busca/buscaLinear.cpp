int Prog::buscaLinear(int num)
{
  int pos;
  for(int i = 0; i < tf; i++)
  {
    if(vetor[i] == num)
      pos = i;
    else
      pos = -1;
  }
  return pos;
}
