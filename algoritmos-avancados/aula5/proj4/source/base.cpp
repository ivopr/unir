#include <iostream>
#include <vector>

/**
 * Algoritmos Avançados - Atividade das Rainhas
 * Alunos: Ivo Vieira e Murilo Fuza
 */
void showBoard(std::vector<std::vector<int>> & board, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool isSecureSpot(std::vector<std::vector<int>> & board, int n, int line, int column) {
	// check attack on line and column
	for (int i = 0; i < n; i++) {
		if (board[line][i] == 1) {
			return false;
		}

		if (board[i][column] == 1) {
			return false;
		}
	}

	// check attack on primary diagonal
	for (int i = line, j = column; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 1) {
			return false;
		}
	}

	for (int i = line, j = column; i < n && j < n; i++, j++) {
		if (board[i][j] == 1) {
			return false;
		}
	}

	// check attack on secondary diagonal
	for(int i = line, j = column; i >= 0 && j < n; i--, j++) {
		if(board[i][j] == 1) {
			return false;
		}
	}

	for(int i = line, j = column; i < n && j >= 0; i++, j--) {
		if(board[i][j] == 1) {
			return false;
		}
	}

	return true;
}

void findMatch(std::vector<std::vector<int>> & board, int n, int column) {
	if (column == n) {
		showBoard(board, n);
		exit(EXIT_SUCCESS);
	}

	for (int i = 0; i < n; i++) {
		if (isSecureSpot(board, n, i, column)) {
			board[i][column] = 1;

			findMatch(board, n, column + 1);

			board[i][column] = 0;
		}
	}
}

int main() {
	int n;

	std::vector<std::vector<int>> board;

	std::cin >> n;

	for(int i = 0; i < n; i++) {
		std::vector<int> line(n);
		board.push_back(line);
	}

	findMatch(board, n, 0);

	return EXIT_SUCCESS;
}