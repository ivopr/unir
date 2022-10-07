#include <iostream>
#include <vector>
#include <algorithm>

void change(int v, std::vector<int> *coins, std::vector<int> *usedCoins, int startingCoin) {
	int vNew = v;
	
	if ((long unsigned int) startingCoin >= coins->size()) {
		return;
	}

	if (vNew >= coins->at(startingCoin)) {
		vNew -= coins->at(startingCoin);
		usedCoins->push_back(coins->at(startingCoin));
		change(vNew, coins, usedCoins, startingCoin);
	} else {
		change(vNew, coins, usedCoins, startingCoin + 1);
	}
}


int main() {
	std::vector<int> coins, usedCoins;

	int v;
	std::cin >> v;

	int c;
	std::cin >> c;

	for (int i = 0; i < c; i++) {
		int vc;
		std::cin >> vc;

		coins.push_back(vc);
	}

	std::sort(coins.begin(), coins.end(), [](int a, int b) {
		return a > b;
	});

	change(v, &coins, &usedCoins, 0);

	std::vector<int>::iterator coinsIt;

	for (coinsIt = usedCoins.begin(); coinsIt != usedCoins.end(); coinsIt++) {
		std::cout << *coinsIt << " ";
	}
	std::cout << "\n" << usedCoins.size() <<  "\n";

	return EXIT_SUCCESS;
}