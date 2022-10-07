void Prog::insertionSortCrescente()
{
	int i, aux, j;
	for(i = 1; i < tf; i++)
	{
		aux = vetor[i];
		j = i - 1;

		while(j >= 0 && vetor[j] > aux)
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = aux;
	}
	ordem = true;
}

void Prog::insertionSortDecrescente()
{

}