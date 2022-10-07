#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[200][20];
int roupas[20][20];
int roupasAux[20];
int numcasos, dinheiro, numroupas;

int comprar(int dindin, int grupo) {
    if (dindin < 0) {
        return -1;
    }

    if (grupo == numroupas) {
        return dinheiro - dindin;
    }

    if (memo[dindin][grupo] != -1) {
        return memo[dindin][grupo];
    }

    int resp = -1;
    for (int i = 0; i < roupasAux[grupo]; i++) {
        resp = max(resp, comprar(dindin - roupas[grupo][i], grupo + 1));
    }

    return memo[dindin][grupo] = resp;
}

int main() {
    scanf("%d", &numcasos);

    while(numcasos--) {
        scanf("%d %d", &dinheiro, &numroupas);

        for(int i = 0; i < numroupas; i++) {
            scanf("%d", &roupasAux[i]);
            for(int j = 0; j < roupasAux[i]; j++) {
                scanf("%d", &roupas[i][j]);
            }
        }

        memset(memo, -1, 200 * 20 * 4);

        int resp = comprar(dinheiro, 0);

        if (resp > 0) {
            printf("%d\n", resp);
        } else {
            printf("no solution\n");
        }
    }

    return 0;
}