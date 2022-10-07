#include "arq.h"
#include <iostream>

lolja::lolja()
{
	tlIndice = 0;
	for (int i = 0; i < MAX; i++)
	{
		indice[i].chave = 0;
		indice[i].posDado = -1;
	}
}

int lolja::buscaBinaria(int codigo)
{
	int inicio = 0, fim = tlIndice - 1, meio = (inicio + fim) / 2;

	while (inicio < fim && codigo != indice[meio].chave)
	{
		if (codigo > indice[meio].chave)
			inicio = meio + 1;
		else
			fim = meio;
		meio = (inicio + fim) / 2;
	}
	if (codigo > indice[meio].chave)
		return meio + 1;
	else
		return meio;
}

int lolja::particao(int inicio, int fim)
{
	int pivo = indice[fim].chave;
	int i = inicio - 1;
	for (int j = inicio; j <= fim - 1; j++)
	{
		if (indice[j].chave < pivo)
		{
			i = i + 1;
			troca(&indice[i], &indice[j]);
		}
	}
	troca(&indice[i + 1], &indice[fim]);
	return i + 1;
}

p lolja::leMaterial()
{
	p m;
	std::cout << "codigo: ";
	std::cin >> m.codigo;
	std::cout << "descricao: ";
	cleanbuffer;
	fgets(m.desc, MAX, stdin);
	std::cout << "quantidade minima: ";
	std::cin >> m.qtdMin;
	std::cout << "quantidade em estoque: ";
	std::cin >> m.qtdAtual;
	return m;
}

void lolja::consulta(int codigo)
{
	int posDado, posIndice;
	p m;
	FILE* arq = fopen(db, "rb");
	if (arq == NULL)
		std::cout << "o arquivo de dados nao existe." << std::endl;
	else
	{
		posIndice = buscaBinaria(codigo);
		if (indice[posIndice].chave == codigo && tlIndice > 0)
		{
			posDado = indice[posIndice].posDado;
			fseek(arq, posDado * sizeof(p), SEEK_SET);
			fread(&m, sizeof(p), 1, arq);
			exibeProduto(m);
		}
		fclose(arq);
	}
}

void lolja::exibeProduto(p m)
{
	std::cout	<< "codigo: " << m.codigo << std::endl
				<< "descricao: " << m.desc << std::endl
				<< "quantidade em estoque: " << m.qtdAtual << std::endl
				<< "quantidade minima para estoque: " << m.qtdMin << std::endl
				<< "--------------------------------------------------------------------------" << std::endl;
}

void lolja::exibeIndice()
{
	for (int i = 0; i < tlIndice; i++)
		std::cout	<< "codigo do produto: " << indice[i].chave << std::endl
					<< "posicao no arquivo: " << indice[i].posDado << std::endl
					<< "-----------------------------------------------------------------------" << std::endl;
}

void lolja::exibeOrdenado()
{
	int i = 0, posDado;
	p m;
	FILE* arq = fopen(db, "rb");
	if (arq == NULL)
		std::cout << "o arquivo de dados nao existe." << std::endl;
	else
	{
		std::cout << "relatorio ordenado" << std::endl;
		while (i < tlIndice)
		{
			posDado = indice[i].posDado;
			fseek(arq, posDado * sizeof(p), SEEK_SET);
			fread(&m, sizeof(p), 1, arq);
			exibeProduto(m);
			i++;
		}
		fclose(arq);
	}
}

void lolja::exibeDesordenado()
{
	p m;
	FILE* arq = fopen(db, "rb");
	if (arq == NULL)
		std::cout << "o arquivo de dados nao existe." << std::endl;
	else
	{
		fread(&m, sizeof(p), 1, arq);
		while (!feof(arq))
		{
			exibeProduto(m);
			fread(&m, sizeof(p), 1, arq);
		}
		fclose(arq);
	}
}

void lolja::iniciaIndice()
{
	p m;
	parTab aux;
	FILE* arq = fopen(db, "rb");
	if (arq == NULL)
	{
		std::cout << "o arquivo de dados nao existe." << std::endl;
		tlIndice = 0;
	}
	else
	{
		tlIndice = 0;
		fread(&m, sizeof(p), 1, arq); 
		while (!feof(arq))
		{
			indice[tlIndice].chave = m.codigo;
			indice[tlIndice].posDado = tlIndice;
			tlIndice++;
			fread(&m, sizeof(p), 1, arq);
		}
		fclose(arq);
		quickSort(0, tlIndice - 1);
	}
}

void lolja::inserirProduto()
{
	int posIdeal;
	p m;
	FILE* arq = fopen(db, "rb");
	if (arq == NULL)
		arq = fopen(db, "wb");
	else
		arq = fopen(db, "ab");
	
	if (arq == NULL)
		std::cout << "nao foi possivel criar o arquivo de dados." << std::endl;
	else
	{
		m = leMaterial();
		fwrite(&m, sizeof(p), 1, arq);
		if (tlIndice == 0)
			posIdeal = 0;
		else
			posIdeal = buscaBinaria(m.codigo);

		for (int i = tlIndice; i > posIdeal; i--)
			indice[i] = indice[i - 1];

		indice[posIdeal].chave = m.codigo;
		indice[posIdeal].posDado = tlIndice;
		tlIndice++;
		fclose(arq);
	}
}

void lolja::quickSort(int inicio, int fim)
{
	if (inicio < fim)
	{
		int pivo = particao(inicio, fim);
		quickSort(inicio, pivo - 1);
		quickSort(pivo + 1, fim);
	}
}

void lolja::troca(parTab* m, parTab* m1)
{
	parTab aux = *m;
	*m = *m1;
	*m1 = aux;
}
