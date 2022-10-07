#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>> vec) {
	for (auto i : vec) {
		for (auto j : i) {
			std::cout << j << "\t";
		}
		std::cout << "\n";
	}
}

void lcs(std::string seq, std::string seq1, int seqSize, int seq1Size, std::vector<std::vector<int>> &memo, std::vector<std::vector<int>> &memoAux) {
	for (int i = 1; i <= seqSize; i++) {
		for (int j = 1; j <= seq1Size; j++) {
			if (seq.at(i - 1) == seq1.at(j - 1)) {
				memo[i][j] = 1 + memo[i - 1][j - 1];
				memoAux[i][j] = 1;
			} else if (memo[i - 1][j] >= memo[i][j - 1]) {
				memo[i][j] = memo[i - 1][j];
				memoAux[i][j] = 2;
			} else {
				memo[i][j] = memo[i][j - 1];
				memoAux[i][j] = 3;
			}
		}
	}
}

void printlcs(std::vector<std::vector<int>> memoAux, std::string seq, int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}

	if (memoAux[i][j] == 1) {
		printlcs(memoAux, seq, i - 1, j - 1);
		std::cout << seq.at(i);
	} else if (memoAux[i][j] == 2) {
		printlcs(memoAux, seq, i - 1, j);
	} else {
		printlcs(memoAux, seq, i, j - 1);
	}
}

int main() {
	std::string seq = "ABCBDAB", seq1 = "BDCABA";
	std::vector<std::vector<int>> memo(seq.size() + 1, std::vector<int>(seq1.size() + 1, 0)), memoAux(seq.size() + 1, std::vector<int>(seq1.size() + 1, 0));

	lcs(seq, seq1, seq.size() - 1, seq1.size() - 1, memo, memoAux);

	std::cout << memo[seq.size() - 1][seq1.size() - 1] << "\n";

	std::cout << "Memo\n";
	printMatrix(memo);
	std::cout << "Memo Aux\n";
	printMatrix(memoAux);

	printlcs(memoAux, seq, seq.size() - 1, seq1.size() - 1);
	std::cout << "\n";
	return 0;
}