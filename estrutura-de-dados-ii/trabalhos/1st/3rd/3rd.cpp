// 2nd.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <queue>

#define T 100
#define MAX 10000000

int n, grafo[T][T], grau[T], dist[T];

using namespace std;

void dijksks(int fonte) {
	// inicia o vetor de distancias com um numero surreal
	for (int i = 0; i < n; i++)
		dist[i] = MAX;

	// a distancia da fonte até a fonte é...
	dist[fonte] = 0;

	// inicia uma fila de prioridade ordenada (heap sort)
	priority_queue<pair<int, int>> fila;

	// adiciona o par 0, fonte a fila
	fila.push(make_pair(0, fonte));

	while(!fila.empty()) {
		// pega o vertice que está no topo (é o segundo elemento, o primeiro é a distancia para a fonte)
		int u = fila.top().second;

		// remove o vertice da fila
		fila.pop();
		
		for (int i = 0; i < grau[u]; i++) {
			int z = grafo[u][i];
			// aumenta a distancia do vertice u à fonte
			int tDist = dist[u] + 1;
			// se a distancia do vertice u for menor ou igual a distancia do vertice z
			// adiciona o par distancia(u), vertice z
			if (tDist <= dist[z]) {
				dist[z] = tDist;
				fila.push(make_pair(tDist, z));
			}
		}
	}
}

int main() {
	int a, b, t = 0;
	while (cin >> n) {
		if (n == 0) break;

		// inicia o vetor de grau
		for (int i = 0; i < n; i++)
			grau[i] = 0;

		// le os vertices a e b
		// a aresta a-1,grau[a-1] recebe peso b-1
		// a aresta b-1,grau[b-1] recebe peso a-1
		// e aumenta o grau dos vértices a-1 e b-1
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			grafo[a - 1][grau[a - 1]] = b - 1;
			grau[a - 1]++;

			grafo[b - 1][grau[b - 1]] = a - 1;
			grau[b - 1]++;
		}

		int vila = 0, mMCaminho = MAX;

		// invoca o dijksks com fonte i
		// se a distancia de i ate j for maior que o valor no max, ela se torna o novo valor do max
		// se o menor caminho for maior que o max, o menor caminho se torna o max, e a vila maix proxima é definida
		for (int i = 0; i < n; i++) {
			dijksks(i);
			int max = 0;
			for (int j = 0; j < n; j++) {
				if (dist[j] > max)
					max = dist[j];
			}

			if (mMCaminho > max) {
				mMCaminho = max;
				vila = i + 1;
			}
		}

		// imprime o numero do teste e a vila em que foi realizado
		cout << "Teste " << ++t << endl
			<< vila << endl
			<< endl;
	}
	exit(EXIT_SUCCESS);
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
