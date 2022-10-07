#include <iostream>
#include <map>
#include <string>
#include <queue>

int main() {
	std::map<char, char> keymap;
	keymap.insert(std::pair<char, char>('W', 'Q'));
	keymap.insert(std::pair<char, char>('E', 'W'));
	keymap.insert(std::pair<char, char>('R', 'E'));
	keymap.insert(std::pair<char, char>('T', 'R'));
	keymap.insert(std::pair<char, char>('Y', 'T'));
	keymap.insert(std::pair<char, char>('U', 'Y'));
	keymap.insert(std::pair<char, char>('I', 'U'));
	keymap.insert(std::pair<char, char>('O', 'I'));
	keymap.insert(std::pair<char, char>('P', 'O'));
	keymap.insert(std::pair<char, char>('[', 'P'));
	keymap.insert(std::pair<char, char>(']', '['));
	keymap.insert(std::pair<char, char>('\\', ']'));
	keymap.insert(std::pair<char, char>('S', 'A'));
	keymap.insert(std::pair<char, char>('D', 'S'));
	keymap.insert(std::pair<char, char>('F', 'D'));
	keymap.insert(std::pair<char, char>('G', 'F'));
	keymap.insert(std::pair<char, char>('H', 'G'));
	keymap.insert(std::pair<char, char>('J', 'H'));
	keymap.insert(std::pair<char, char>('K', 'J'));
	keymap.insert(std::pair<char, char>('L', 'K'));
	keymap.insert(std::pair<char, char>(';', 'L'));
	keymap.insert(std::pair<char, char>('\'', ';'));
	keymap.insert(std::pair<char, char>('X', 'Z'));
	keymap.insert(std::pair<char, char>('C', 'X'));
	keymap.insert(std::pair<char, char>('V', 'C'));
	keymap.insert(std::pair<char, char>('B', 'V'));
	keymap.insert(std::pair<char, char>('N', 'B'));
	keymap.insert(std::pair<char, char>('M', 'N'));
	keymap.insert(std::pair<char, char>(',', 'M'));
	keymap.insert(std::pair<char, char>('.', ','));
	keymap.insert(std::pair<char, char>('/', '.'));
	keymap.insert(std::pair<char, char>(' ', ' '));
	keymap.insert(std::pair<char, char>('1', '\''));
	keymap.insert(std::pair<char, char>('2', '1'));
	keymap.insert(std::pair<char, char>('3', '2'));
	keymap.insert(std::pair<char, char>('4', '3'));
	keymap.insert(std::pair<char, char>('5', '4'));
	keymap.insert(std::pair<char, char>('6', '5'));
	keymap.insert(std::pair<char, char>('7', '6'));
	keymap.insert(std::pair<char, char>('8', '7'));
	keymap.insert(std::pair<char, char>('9', '8'));
	keymap.insert(std::pair<char, char>('0', '9'));
	keymap.insert(std::pair<char, char>('-', '0'));
	keymap.insert(std::pair<char, char>('=', '-'));

	std::queue<std::string> q;
	std::string input;

	do {
		std::getline(std::cin, input);
		q.push(input);
	} while(!input.empty());

	std::string::iterator si;
	std::map<char, char>::iterator mi;

	do {
		std::string in = q.front();
		q.pop();

		for(si = in.begin(); si != in.end(); si++) {
			for(mi = keymap.begin(); mi!=keymap.end(); mi++) {
				if (*si == mi->first) {
					std::cout << mi->second;
				}
			}
		};
		std::cout << std::endl;
	}while(q.size() > 1);

	return EXIT_SUCCESS;
}