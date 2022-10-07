#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	int tCount, tHolder;
	std::cin >> tCount;

	std::vector<int> tStart, tEnd;
	std::vector<std::pair<std::pair<int, int>, int>> tVec;
	std::vector<int> eVec;

	// Leitura Inicios
	for (int i = 0; i < tCount; i++) {
		std::cin >> tHolder;
		tStart.push_back(tHolder);
	}

	// Leitura Fins
	for (int i = 0; i < tCount; i++) {
		std::cin >> tHolder;
		tEnd.push_back(tHolder);
	}

	for (int i = 0; i < tCount; i++) {
		tVec.push_back(std::pair<std::pair<int, int>, int>(std::pair<int, int>(tStart.at(i), tEnd.at(i)), 0));
	}

	std::sort(tVec.begin(), tVec.end(), [](std::pair<std::pair<int, int>, int> &a, std::pair<std::pair<int, int>, int> &b) {
		return a.first.second < b.first.second;
	});

	for (int i = 0; i < tVec.size() - 1; i++) {
		if (tVec.at(i).first.first < tVec.at(i + 1).first.first) {
			tVec.at(i).second = 1;
		} else {
			tVec.at(i).second = 0;
		}
		if (i == tVec.size() - 1) tVec.at(i).second = 1;
	}

	for (auto it : tVec) {
		std::cout << it.second << " ";
	}

	return EXIT_SUCCESS;
}