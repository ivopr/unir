#include <bits/stdc++.h>
#define MAX 100
#define tf 10

using namespace std;

class Prog
{
	public:
		int vetor[tf], ordem;
		void criarVetor();
		void exibirVetor();
		void bubbleSortCrescente();
		void bubbleSortDecrescente();
		void insertionSortCrescente();
		void insertionSortDecrescente();
		void selectionSortCrescente();
		void selectionSortDecrescente();
		void quickSortCrescente(int inicio, int fim);
		void quickSortDecrescente(int inicio, int fim);
		void heapSort();
		int particaoCrescente(int inicio, int fim);
		int particaoDecrescente(int inicio, int fim);
		int buscaLinear(int num);
		int buscaSequencial(int num);
		int buscaBinaria(int num);
		int buscaBinariaRecursiva(int num, int inicio, int fim);
};

// UTILIDADES
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\misc\main.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\misc\troca.cpp"

// MÉTODOS DE BUSCA
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\busca\buscaBinaria.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\busca\buscaBinariaRecursiva.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\busca\buscaLinear.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\busca\buscaSequencial.cpp"

// MÉTODOS DE ORDENAÇÃO
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\ordenacao\bubbleSort.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\ordenacao\heapSort.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\ordenacao\insertionSort.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\ordenacao\quickSort.cpp"
#include "C:\Users\azraelthedeath\Desktop\codigos\programação II\aulas\20190913\includes\ordenacao\selectionSort.cpp"
