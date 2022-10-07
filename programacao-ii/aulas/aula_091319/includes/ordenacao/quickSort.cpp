/*
	PARTICIONAMENTO
	Método utilizado pelo quickSort para separação das partes maiores e menores que o pivô
*/
int Prog::particaoCrescente(int inicio, int fim)
{
	int pivo = vetor[fim];
	int i = inicio - 1;

	for(int j = inicio; j <= fim - 1; j++)
	{
		if(vetor[j] < pivo)
		{
			i = i + 1;
			troca(&vetor[i], &vetor[j]);
		}
	}
	troca(&vetor[i + 1], &vetor[fim]);
	return i + 1;
}

int Prog::particaoDecrescente(int inicio, int fim)
{
	int pivo = vetor[fim];
	int i = inicio - 1;

	for(int j = inicio; j <= fim - 1; j++)
	{
		if(vetor[j] > pivo)
		{
			i = i + 1;
			troca(&vetor[i], &vetor[j]);
		}
	}
	troca(&vetor[i + 1], &vetor[fim]);
	return i + 1;
}

/*
	quickSort
	Função principal para ambos, decrescente e crescente
*/
void Prog::quickSortCrescente(int inicio, int fim)
{
	if(inicio < fim)
	{
		int pivo = particaoCrescente(inicio, fim);

		quickSortCrescente(inicio, pivo - 1);
		quickSortCrescente(pivo + 1, fim);
	}
	ordem = true;
}

void Prog::quickSortDecrescente(int inicio, int fim)
{
	if(inicio < fim)
	{
		int part = particaoDecrescente(inicio, fim);

		quickSortDecrescente(inicio, part - 1);
		quickSortDecrescente(part + 1, fim);
	}
	ordem = true;
}