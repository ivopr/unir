#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <map>

int main() {
	int numberOfCages, animals;
	std::deque<int> mass;
	std::vector<std::pair<int, int>> cages;

	std::cin >> numberOfCages;
	std::cin >> animals;

	if (animals > 2 * numberOfCages) {
		return EXIT_FAILURE;
	}

	int tempMass;
	for (int i = 0; i < animals; i++) {
		std::cin >> tempMass;
		mass.push_back(tempMass);
	}

	for (int i = animals; i < 2 * numberOfCages; i++) {
		mass.push_back(0);
	}

	std::sort(mass.begin(), mass.end());

	for(int i = 0; i < numberOfCages; i++) {
		std::pair<int, int> newCage(mass.front(), mass.back());

		cages.push_back(newCage);

		mass.pop_front();
		mass.pop_back();
	}

	int helper = 1;
	for (auto cage : cages) {
		std::cout << "#Jaula " << helper << ": ";
		if (cage.first != 0) {
			std::cout << cage.first << " ";
		}

		if (cage.second != 0) {
			std::cout << cage.second;
		}
		std::cout << "\n";
		helper++;
	}

	return EXIT_SUCCESS;
}