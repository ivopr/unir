int Prog::buscaSequencial(int num)
{
  int pos, i = 0;

  while(i < tf && num > vetor[i])
    i++;

  if(num == vetor[i] && i < tf)
    pos = i;
  else
    pos = -1;
  
	return pos;
}