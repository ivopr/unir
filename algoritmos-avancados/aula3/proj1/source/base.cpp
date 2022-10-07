#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>

int main() {
	int N;
	std::cin >> N;

	int prefers[2 * N][N];

	for (int i = 0; i < 2 * N; i++) {
		for (int j  = 0; j < N; j++) {
			std::cin >> prefers[i][j];
		}
	}

	int wPartner[N];
	bool mFree[N];
	memset(wPartner, -1, sizeof(wPartner));
	memset(mFree, false, sizeof(mFree));
	int freeCount = N;

	while (freeCount > 0) {
		int m;
		for (m = 0; m < N; m++) {
			if (mFree[m] == false) {
				break;
			}
		}

		for (int i = 0; i < N && mFree[m] == false; i++) {
			int w = prefers[m][i];

			if (wPartner[w - N] == -1) {
				wPartner[w - N] = m;
				mFree[m] = true;
				freeCount--;
			} else {
				int m1 = wPartner[w - N];
				bool prefersM1M;

				for (int i = 0; i < N; i++) {
					if (prefers[w][i] == m1) prefersM1M = false;

					if (prefers[w][i] == m) prefersM1M = true;
				}

				if (prefersM1M == false) {
					wPartner[w - N] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			}
		}

	}
	std::cout << "mulher homem" << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << " " << i+N << " " << wPartner[i] << std::endl;

	return EXIT_SUCCESS;
}