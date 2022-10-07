#include <iostream>
#include <vector>

int lcs(std::string seq, std::string seq1, int seqSize, int seq1Size, std::vector<std::vector<int>> &memo) {
	if (seqSize == 0 || seq1Size == 0) {
		return 0;
	}

	if (seq.at(seqSize - 1) == seq1.at(seq1Size - 1)) {
		return memo[seqSize][seq1Size] = 1 + lcs(seq, seq1, seqSize - 1, seq1Size - 1, memo);
	}
	
	if (memo[seqSize][seq1Size] != -1) {
		return memo[seqSize][seq1Size];
	}

	return memo[seqSize][seq1Size] = std::max(lcs(seq, seq1, seqSize - 1, seq1Size, memo), lcs(seq, seq1, seqSize, seq1Size - 1, memo));
}

int main() {
	std::string seq = "ABCBDAB", seq1 = "BDCABA";
	std::vector<std::vector<int>> memo(seq.size() + 1, std::vector<int>(seq1.size() + 1, -1));

	int res = lcs(seq, seq1, seq.size(), seq1.size(), memo);
	std::cout << res << "\n";

	std::cout << "\n";
	return 0;
}