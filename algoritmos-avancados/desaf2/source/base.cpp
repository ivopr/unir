#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

/**
 * Algoritmos Avançados - Desafio 02
 * Alunos: Ivo Vieira e Murilo Fuza
 */
int main() {
	int n, aux;
	std::vector<int> startTimes, endTimes;
	std::vector<std::pair<int, int>> schedule;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> aux;
		startTimes.push_back(aux);
	}

	for (int i = 0; i < n; i++) {
		std::cin >> aux;
		endTimes.push_back(aux);
	}

	for (int i = 0; i < n; i++) {
		schedule.push_back(std::pair<int, int>(startTimes.at(i), endTimes.at(i)));
	}

	std::sort(schedule.begin(), schedule.end(), [](auto a, auto b) {
		return a.second < b.second;
	});

	int lastEndTime = 0;
	for (int i = 0; i < n; i++) {
		std::pair<int, int> item = schedule.at(i);
		std::string out = std::to_string(item.first) + " " + std::to_string(item.second) + ": ";
		if (item.first >= lastEndTime) {
			out.append("1");
			lastEndTime = item.second;
		} else {
			out.append("0");
		}
		std::cout << out << "\n";
	}

	return EXIT_SUCCESS;
}