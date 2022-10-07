void Prog::selectionSortCrescente()
{
	int i, j, posmenor;
	for(i = 0; i < tf - 1; i++)
	{
		posmenor = i;

		for(j = i + 1; j < tf; j++)
		{
			if(vetor[j] < vetor[posmenor])
				posmenor = j;
			
			troca(&vetor[posmenor], &vetor[i]);
		}
	}
	ordem = true;
}

void Prog::selectionSortDecrescente()
{

}