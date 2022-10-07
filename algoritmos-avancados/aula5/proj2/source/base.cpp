#include <iostream>

void criarPalavra(char *palavra, int pos) {
	if (pos > 3) {
		std::cout << palavra << "\n";
	} else {
		for (char letra = 'a'; letra <= 'z'; letra++) {
			palavra[pos] = letra;
			criarPalavra(palavra, pos + 1);
		}
	}
}

int main() {
	char palavra[4] = "\0";

	criarPalavra(palavra, 0);
	// int count = 0;
	// for (char i = 'a'; i <= 'z'; i++) {
	// 	palavra[0] = i;
	// 	for (char j = 'a'; j <= 'z'; j++) {
	// 		palavra[1] = j;
	// 		for (char k = 'a'; k <= 'z'; k++) {
	// 			palavra[2] = k;
	// 			for (char l = 'a'; l <= 'z'; l++) {
	// 				palavra[3] = l;
	// 				palavra[4] = '\0';
	// 				std::cout << count << " - " << palavra << "\n";
	// 				count++;
	// 			}
	// 		}
	// 	}
	// }
	return EXIT_SUCCESS;
}