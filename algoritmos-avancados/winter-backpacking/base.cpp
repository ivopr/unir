#include <iostream>
#include <numeric>
#include <vector>

/**
 * @brief Desafio 04 - Viagem de mochilão de inverno
 * @author Ivo Vieira
 * @author Murilo Fuza
 */

int shouldDecrementMax(int avg, int N, int K, std::vector<int> distances) {
	int sum = 0, count = 0;

	for (int i = 0; i <= N; i++) {
		if (distances.at(i) > avg) {
			return 0;
		}

		if (sum + distances.at(i) > avg) {
			sum = distances.at(i);
			count += 1;
		} else {
			sum += distances.at(i);
		}
	}

	if (sum) {
		count += 1;
	}

	return count <= K;
}

int main() {
	int N, K;
	std::vector<int> campsites;
	std::cin >> N >> K;
	N++, K++;

	if (N <= 0 || N > 600 || K < 0 || K > 300) return EXIT_FAILURE;

	for (int i = 0; i <= N; i++) {
		int distN;
		std::cin >> distN;
		campsites.push_back(distN);
	}

	int min = 0, max = std::accumulate(campsites.begin(), campsites.end(), decltype(campsites)::value_type(0)), avg;

	while (min <= max) {
		avg = (min + max) / 2;
		if (shouldDecrementMax(avg, N, K, campsites)) {
			max = avg - 1;
		} else {
			min = avg + 1;
		}
	}

	std::cout << max << "\n";

	return EXIT_SUCCESS;
}