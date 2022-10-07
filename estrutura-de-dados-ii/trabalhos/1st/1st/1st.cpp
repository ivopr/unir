// 1st.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib>

using namespace std;

// declara variaveis
bool grafo[700][700];
bool visitados[700];
int n, p;

void prof(int p) {
	// se o p já foi percorrido, retorna para a função principal
	if (visitados[p]) {
		return;
	// se o p não foi percorrido, marca ele como percorrido, e percorre seus adjacentes e faz a mesma verificação com eles
	} else {
		visitados[p] = true;
		for (int i = 1; i <= n; i++)
			if (grafo[p][i] && !visitados[i]) prof(i);
	}
}

int main() {
	cin >> n;
	while (n != 0) {
		cin >> p;

		// inicia o vetor de visitados e a matriz de adjacencia 
		for (int i = 1; i <= n; i++) {
			visitados[i] = false;
			for (int j = 1; j <= n; j++) {
				grafo[i][j] = false;
			}
		}

		// adiciona a aresta de forma correta, com OP==1 aresta direcionada, OP==2 aresta não direcionada
		for (int i = 1; i <= p; i++) {
			int a, b, op;
			cin >> a >> b >> op;
			if (op == 1) grafo[a][b] = true;
			else {
				grafo[a][b] = true;
				grafo[b][a] = true;
			}
		}

		// percorre o primeiro vertice
		prof(1);

		bool resp = true;

		// se houver algum vértice ainda não visitado, marca a resposta como falsa
		for (int i = 1; i <= n; i++) {
			if (!visitados[i]) resp = false;
		}

		// se a resposta for verdadeira, percorre o vetor de visitados marcando todos como falsos
		// percorre a matriz de adjacencia verificando. se a rua for mão dupla, continua o programa,
		// se a rua for mão única (aresta direcionada) inverte a direção
		if (resp) {
			for (int i = 1; i <= n; i++) {
				visitados[i] = false;
				for (int j = i + 1; j <= n; j++) {
					if (grafo[i][j] && grafo[j][i]) continue;
					else if (grafo[i][j])
						grafo[j][i] = true, grafo[i][j] = false;
					else if (grafo[j][i])
						grafo[i][j] = true, grafo[j][i] = false;
				}
			}
		}

		// percorre mais uma vez o primeiro vertice
		prof(1);


		// se houver algum vértice ainda não visitado, marca a resposta como falsa novamente
		for (int i = 1; i <= n; i++)
			if (!visitados[i]) resp = false;

		// retorna 1 se o requisito de conexidade está satisfeito e 0 se não.
		if (resp) cout << 1 << endl;
		else cout << 0 << endl;

		cin >> n;
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
