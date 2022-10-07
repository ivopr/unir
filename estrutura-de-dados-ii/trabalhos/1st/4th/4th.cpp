// 4th.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <queue>

#define mv 50
#define MAX 10000000

int grafo[mv][mv], dist[mv];

using namespace std;

// inicia o vetor de distancias com uma distancia incrivelmente absurda
// define a distancia da fonte pra fonte como 0
// a fila de prioridade é a mesma coisa do programa 3
// se existir a aresta u,i e a distacia de u para a fonte +1 for menor que a distancia de i para a fonte
// a distancia de i para a fonte passa a ser a distancia de u para a fonte +1
// e adiciona o par de distancia i e vertice i a fila de prioridade
void dijkstra(int n, int fonte) {
    for (int i = 0; i < n; i++) {
        dist[i] = MAX;
    }

    dist[fonte] = 0;
    priority_queue<pair<int, int>> fila;
    fila.push(make_pair(0, fonte));

    while(!fila.empty()) {
        int u = fila.top().second;
        fila.pop();

        for(int i = 0; i < n; i++) {
            if(grafo[u][i] == 1 && dist[u] + 1 <= dist[i]) {
                dist[i] = dist[u] + 1;
                fila.push(make_pair(dist[i], i));
            }
        }
    }
}

// a e b são os numeros de cidades e estradas existentes
// c é a cidade origem e d é o numero maximo de pedagios que o seu Juca quer pagar (crise ta foda)
// define as estradas da cidade E para a cidade F como sendo mão dupla
// invoca o dijksks enviando o numero total de cidades que devem er percorridas e a cidade origem
// depois se a cidade for diferente da origem e que tenha distancia menor ou igual a d (distancia maxima possivel de pagar),
// exibe ela como possivel caminho
int main() {
    int a, b, c, d, e, f;
    int teste = 1;

    while (1) {
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) break;

        for (int i = 0; i < a; i++)
            for (int j = 0; j < a; j++)
                grafo[i][j] = 0;

        for (int i = 0; i < b; i++) {
            cin >> e >> f;
            grafo[e - 1][f - 1] = 1;
            grafo[f - 1][e - 1] = 1;
        }

        dijkstra(a, c - 1);

        cout << "Teste " << teste++ << endl;
        bool primeiro = true;
        for (int i = 0; i < a; i++) {
            if (i != c - 1 && dist[i] <= d) {
                if (primeiro) cout << i + 1;
                else cout << " " << i + 1;
                primeiro = false;
            }
        }
        cout << endl << endl;
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
