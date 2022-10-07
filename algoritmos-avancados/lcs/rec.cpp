#include <iostream>

int lcs(std::string seq, std::string seq1, int seqSize, int seq1Size) {
	if (seqSize == 0 || seq1Size == 0) {
		return 0;
	}

	if (seq.at(seqSize - 1) == seq1.at(seq1Size - 1)) {
		return 1 + lcs(seq, seq1, seqSize - 1, seq1Size - 1);
	} else {
		return std::max(lcs(seq, seq1, seqSize - 1, seq1Size), lcs(seq, seq1, seqSize, seq1Size - 1));
	}
}

int main() {
	std::string seq = "ABCBDAB", seq1 = "BDCABA";
	std::cout << lcs(seq, seq1, seq.size(), seq1.size()) << "\n";

	return 0;
}