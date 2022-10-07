void parar()
{
	cout << "pressione enter para continuar..." << endl;
	cin.ignore();
	cin.get();
}

void limpar()
{
	cout << string(100, '\n');
}

/*
	CRIAR
	Cria o vetor aleatóriamente
*/
void Prog::criarVetor()
{
	srand(time(NULL));
	for(int i = 0; i < tf; i =  i + 1) 
		vetor[i] = rand() % MAX;
	ordem = false;
}

/*
	EXIBE
	Exibe o vetor, ordenado, desordenado... do jeito que está...
*/
void Prog::exibirVetor()
{
	for(int i = 0; i < tf; i ++)
		printf("%.2d\t", vetor[i]);
	cout << endl;
}
