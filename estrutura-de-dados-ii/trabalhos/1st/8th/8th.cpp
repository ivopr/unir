// 8th.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

using namespace std;

#define v 10
#define vf 10000

int incl[] = { -1, 0, 0, 1 };
int incc[] = { 0, -1, 1, 0 };

int cav[v][v];
int n, m;

// verifica se está dentro da caverna
bool dCav(int l, int c) {
    return l >= 0 && l < n && c >= 0 && c < m;
}

// enquanto não for o fim da caverna
// se não houver caminho entre o salão l e c, retorna a distancia atual
int bfs(int l, int c) {
    int ini = 0, fim = 0;
    int larguras[vf], comprimentos[vf], distOrigem[vf];
    int dist = 0;

    // adiciona um elemento a fila
    larguras[fim] = l;
    comprimentos[fim] = c;
    distOrigem[fim] = 0;
    fim++;

    while (ini != fim) {
        l = larguras[ini];
        c = comprimentos[ini];
        dist = distOrigem[ini];
        ini++;

        // se o salão atual for a saida, retorna a distancia
        if (cav[l][c] == 0) return dist;
        // se o salão atual não for a saida e não tem parede de cristal 
        else if (cav[l][c] == 1) {
            // verifica se o duende está na caverna e se o proximo salão não é de cristal
            // e aumenta a distancia percorrida
            for (int i = 0; i < 4; i++) {
                if (dCav(l + incl[i], c + incc[i]) &&
                    cav[l + incl[i]][c + incc[i]] < 2) {
                    larguras[fim] = l + incl[i];
                    comprimentos[fim] = c + incc[i];
                    distOrigem[fim] = dist + 1;
                    fim++;
                }
            }
        }

        // transforma a caverna como não retornavel
        cav[l][c] = 2;
    }

    return -1;
}

int main() {
    int x = 0, y = 0;
    cin >> n >> m;
    // iniciar os salões
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cav[i][j];
            // se esse for o salão que o duende está, salva esse salão, e transforma ele em salão comum
            if (cav[i][j] == 3) {
                x = i;
                y = j;
                cav[i][j] = 1;
            }
        }
    }

    // busca os salões em que o duende pode passar começando do salão x,y (o que voce colocou 3 ali em cima)
    cout << bfs(x, y) << endl;
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
