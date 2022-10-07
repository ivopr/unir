#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/**
 * @brief Desafio 1 Algoritmos Avançados
 * @author Ivo Henrique Provensi Vieira
 * @author Murilo Fuza da Cunha
 */

std::vector<int> performReversal(std::vector<int> sequence, int startIndex, int endIndex) {	
	std::vector<int> returnable;

	returnable.insert(returnable.end(), sequence.begin() + startIndex, sequence.begin() + endIndex);
	std::reverse(returnable.begin(), returnable.end());

	returnable.insert(returnable.begin(), sequence.begin(), sequence.begin() + startIndex);
	returnable.insert(returnable.end(), sequence.begin() + endIndex, sequence.end());

	return returnable;
	
	// std::reverse(sequence.begin() + startIndex, sequence.begin() + endIndex);

	// return sequence;
}

template <typename T>
std::pair<bool, int> findInVector(const std::vector<T> & vecOfElements, const T & element) {
	std::pair<bool, int> result;
	auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
	if (it != vecOfElements.end()) {
		result.second = std::distance(vecOfElements.begin(), it);
		result.first = true;
	} else {
		result.first = false;
		result.second = -1;
	}
	return result;
}

std::vector<int> findBreakpoints(std::vector<int> sequence, std::vector<int> targetSequence) {
	std::vector<int> breakpoints;
	for (long unsigned int i = 0; i < sequence.size() - 1; i++) {
		std::pair<bool, int> currentElement = findInVector<int>(targetSequence, sequence.at(i));
		std::pair<bool, int> adjacentElement = findInVector<int>(targetSequence, sequence.at(i + 1));

		if (abs(currentElement.second - adjacentElement.second) != 1) {
			breakpoints.push_back(i + 1);
		}
	}

	return breakpoints;
}

std::vector<std::vector<int>> findMinimumBreakpointReversals(std::vector<std::vector<int>> sequences, std::vector<int> targetSequence) {
	std::vector<std::vector<int>> reversals;

	for (auto sequence : sequences) {
		std::vector<int> breakpoints = findBreakpoints(sequence, targetSequence);
		for (long unsigned int i = 0; i < breakpoints.size() - 1; i++) {
			for (long unsigned int j = i + 1; j < breakpoints.size(); j++) {
				reversals.push_back(performReversal(sequence, breakpoints.at(i), breakpoints.at(j)));
			}
		}
		if (breakpoints.size() == 1) {
			reversals.push_back(performReversal(sequence, 1, sequence.size() - 1));
		}
	}

	int minBreakpoint = targetSequence.size();
	std::vector<std::vector<int>> minimumReversals;

	for (auto reversal : reversals) {
		int numBreakpoints = findBreakpoints(reversal, targetSequence).size();
		if (numBreakpoints < minBreakpoint) {
			minBreakpoint = numBreakpoints;
			minimumReversals = { reversal };
		} else if (numBreakpoints == minBreakpoint) {
			minimumReversals.push_back(reversal);
		}
	}

	return minimumReversals;
}

int getReversalDistance(std::vector<int> sequence, std::vector<int> targetSequence) {
	int reversals = 0;
	sequence.push_back(0);
	std::rotate(sequence.rbegin(), sequence.rbegin() + 1, sequence.rend());
	sequence.push_back(0);

	targetSequence.push_back(0);
	std::rotate(targetSequence.rbegin(), targetSequence.rbegin() + 1, targetSequence.rend());
	targetSequence.push_back(0);

	std::vector<std::vector<int>> currentSequences = { sequence };

	while (currentSequences.end() == std::find(currentSequences.begin(), currentSequences.end(), targetSequence)) {
		currentSequences = findMinimumBreakpointReversals(currentSequences, targetSequence);
		reversals += 1;
	}

	return reversals;
}

int main() {
	std::vector<std::vector<int>> sequences, targetSequences;
	std::vector<int> sHolder;
	int sCount, vHolder;
	std::cin >> sCount;

	if (sCount > 5) {
		sCount  = 5;
	}
	
	for (int i = 0; i < sCount * 2; i++) {
		for (int j = 0; j < 10; j++) {
			std::cin >> vHolder;
			sHolder.push_back(vHolder);
		}
		if (i == 0 || i % 2 == 0) {
			sequences.push_back(sHolder);
		} else {
			targetSequences.push_back(sHolder);
		}
		sHolder.clear();
	}

	for (long unsigned int i = 0; i < sequences.size(); i++) {
		std::cout << getReversalDistance(sequences.at(i), targetSequences.at(i)) << " ";
	}
	std::cout << "\n";
	return EXIT_SUCCESS;
}