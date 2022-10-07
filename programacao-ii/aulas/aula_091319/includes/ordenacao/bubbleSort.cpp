void Prog::bubbleSortCrescente()
{
  int aux;
	for(int i = tf - 1; i > 0; i--)
  {
		for(int j = 0; j < i; j++)
    {
			if(vetor[j] > vetor[j + 1])
      {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
	ordem = true;
}

void Prog::bubbleSortDecrescente()
{
  int aux;
	for(int i = tf - 1; i > 0; i--)
  {
		for(int j = 0; j < i; j++)
    {
			if(vetor[j] < vetor[j + 1])
      {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
	ordem = true;
}