/**
 * @file base.cpp
 * @author Ivo Henrique Provensi Vieira (ivoprovensi1@gmail.com)
 * @author Murilo Fuza da Cunha (muriloacademix@gmail.com)
 * @brief Primeira Avaliação de Algoritmos Avançados
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright (c) 2022
 */

#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <climits>

#define N 3

// baixo, esquerda, cima, direita
int lin[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

struct No {
	No* pai;
	int mat[N][N];
	int x, y;
	int custo;
	int prof;
};

struct comp {
	bool operator()(const No* lhs, const No* rhs) const {
		return (lhs->custo + lhs->prof) > (rhs->custo + rhs->prof);
	}
};

void exibirMat(int mat[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
 
No* novoNo(int mat[N][N], int x, int y, int novoX, int novoY, int prof, No* pai) {
	No* no = new No;
	no->pai = pai;
	memcpy(no->mat, mat, sizeof no->mat);
	std::swap(no->mat[x][y], no->mat[novoX][novoY]);
	no->custo = INT_MAX;
	no->prof = prof;
	no->x = novoX;
	no->y = novoY;
	return no;
}

std::vector<int> encontrarValor(int mat[N][N], int val) {
	std::vector<int> ij;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (val == mat[i][j]) {
				ij.push_back(i);
				ij.push_back(j);
			}
		}
	}

	return ij;
}

int calcularCusto(int inicial[N][N], int final[N][N]) {
	int manhattan = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val = inicial[i][j];
			std::vector<int> ij = encontrarValor(final, val);

			manhattan += (abs(i - ij.at(0)) + abs(j - ij.at(1)));
		}
	}

	return manhattan;
}
 
int seguro(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}
 
void exibirCaminho(No* raiz, int flag) {
	if (raiz == NULL) {
		return;
	}
	exibirCaminho(raiz->pai, 1);
	exibirMat(raiz->mat);
	if (flag == 1) {
		printf("\n");
	}
}
 
void resolver(int inicial[N][N], int x, int y, int final[N][N]) {
	std::priority_queue<No*, std::vector<No*>, comp> pq;

	No* raiz = novoNo(inicial, x, y, x, y, 0, NULL);
	raiz->custo = calcularCusto(inicial, final);

	pq.push(raiz);

	while (!pq.empty()) {
		No* min = pq.top();
		pq.pop();

		if (calcularCusto(min->mat, final) == 0) {
			exibirCaminho(min, 0);
			printf("#Movimentos: %d\n", min->prof);
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (seguro(min->x + lin[i], min->y + col[i])) {
				No* filho = novoNo(min->mat, min->x, min->y, min->x + lin[i], min->y + col[i], min->prof + 1, min);
				filho->custo = calcularCusto(filho->mat, final);
				filho->custo = filho->custo + filho->prof;

				pq.push(filho);
			}
		}
	}
}
 
int main() {
	int inicial[N][N], final[N][N], x, y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &(inicial[i][j]));

			if (inicial[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &(final[i][j]));
		}
	}

	resolver(inicial, x, y, final);
	return 0;
}