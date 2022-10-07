int Prog::buscaBinariaRecursiva(int num, int inicio, int fim)
{
	int meio;
	if(inicio > fim)
		return -1;
	else
	{
		meio = (inicio + fim) / 2;
		if(num == vetor[meio])
			return meio;
		else if(num < vetor[meio])
			buscaBinariaRecursiva(num, inicio, meio - 1);
		else
			buscaBinariaRecursiva(num, meio + 1, fim);
	}
}