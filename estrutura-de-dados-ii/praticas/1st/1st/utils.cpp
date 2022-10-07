#include "utils.h"

void utils::clrscr() {
	cout << string(100, '\n');
}

void utils::pause() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	cout << "Pressione [Enter] para continuar...";
	cin.get();
}