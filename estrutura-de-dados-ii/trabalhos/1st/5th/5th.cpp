// 5th.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib>

#define v 1000
#define nv 2

int n, locx[v], locy[v], grafo[v][nv];
bool vis[v];

using namespace std;

// inverte a por b
void troca(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// se a locx de a for igual a locx de b, retorna verdadeiro se a locy de a for menor que a locy de b, senão retorna falso
// se a primeira condição acima for falso, verifica de a locx de a é menor que a locx de b, se sim, retorna verdadeiro
// qualquer outro resultado, retorna falso
inline bool precede(int a, int b) {
    if (locx[a] == locx[b]) return locy[a] < locy[b];
    else if (locx[a] < locx[b]) return true;
    else return false;
}

// se a dist1 for menor que a dist ou se forem iguais e b preceder a
// troca a posição de dist com dist1 e a com b
void ordena(int& a, int& b, int& dist, int& dist1) {
    if(dist1 < dist || (dist1 == dist && precede(b, a))) {
        troca(dist, dist1);
        troca(a, b);
    }
}

// se a estação j não for a estação i, dx é a distancia no eixo x entre i e j, e dy é a distancia no eixo y entre i e j
// se a distancia da estação i para a estação principal for -1, essa distancia é alterada para j
void calcDist() {
    for (int i = 0; i < n; i++) {
        grafo[i][0] = -1;
        grafo[i][1] = -1;
        int dist0 = 0;
        int dist1 = 0;

        for (int j = 0; j < n; j++) {
            if (j != i) {
                int dx = locx[i] - locx[j];
                int dy = locy[i] - locy[j];
                int dist = dx * dx + dy * dy;

                if (grafo[i][0] == -1) {
                    grafo[i][0] = j;
                    dist0 = dist;
                } else if (grafo[i][1] == -1) {
                    grafo[i][1] = j;
                    dist1 = dist;

                    ordena(grafo[i][0], grafo[i][1], dist0, dist1);
                } else {
                    if (dist == dist1) {
                        if (precede(j, grafo[i][1])) {
                            grafo[i][1] = j;
                        }

                        ordena(grafo[i][0], grafo[i][1], dist0, dist1);
                    } else if (dist1 > dist) {
                        grafo[i][1] = j;
                        dist1 = dist;

                        ordena(grafo[i][0], grafo[i][1], dist0, dist1);
                    }
                }
            }
        }
    }
}

void dfs(int no) {
    vis[no] = true;

    for (int i = 0; i < nv; i++) {
        if (!vis[grafo[no][i]]) dfs(grafo[no][i]);
    }
}

int main() {
    while (cin >> n) {
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> locx[i] >> locy[i];
        }

        calcDist();
        for (int i = 0; i < n; i++) vis[i] = false;
        dfs(0);
        bool alcancaveis = true;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                alcancaveis = false;
                break;
            }
        }

        if (alcancaveis) cout << "Todos sao alcancaveis" << endl;
        else cout << "alguns nao sao alcancaveis" << endl;
    }
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
