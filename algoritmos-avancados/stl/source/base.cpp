#include <base.hpp>

int main(int argc, char* argv[]) {
	/**
	 * @brief Vetores
	 */
	std::vector<int> vec0;
	vec0.push_back(1);
	std::cout << "VETORES" << std::endl << vec0[0] << std::endl;

	/**
	 * @brief Iteradores
	 */
	std::vector<int> vec1;
	std::vector<int>::iterator i1;
	std::cout << "ITERADORES" << std::endl;
	for(int i = 0; i <= 4; i++) vec1.push_back(i);
	for(i1 = vec1.begin(); i1 != vec1.end(); i1++) std::cout << *i1 << " ";
	std::cout << std::endl;

	/**
	 * @brief Reverse Iterator
	 */
	std::vector<int>::reverse_iterator ri1;
	std::cout << "REVERSE ITERATOR" << std::endl;
	for(ri1 = vec1.rbegin(); ri1 != vec1.rend(); ri1++) std::cout << *ri1 << " ";
	std::cout << std::endl;

	/**
	 * @brief Map
	 */
	std::map<char, int> m0;
	std::map<char, int>::iterator mi0;
	std::cout << "MAP" << std::endl;
	for(int i = 0; i <= 4; i++) m0.insert(std::pair<char, int>(60 + i, i));
	for(mi0 = m0.begin(); mi0 != m0.end(); mi0++) std::cout << mi0->first << " " << mi0->second << " ";
	std::cout << std::endl;

	/**
	 * @brief Queue
	 */


	/**
	 * @brief Stack
	 */
	std::stack<int> s0;
	std::cout << "STACK" << std::endl;
	s0.push(1);
	s0.push(2);
	s0.push(3);
	std::cout << s0.top() << " ";
	s0.pop();
	std::cout << s0.top() << std::endl;
	
	/**
	 * @brief Deque
	 */
	std::deque<char> d0;
	std::cout << "DEQUE" << std::endl;
	d0.push_back('c');
	d0.push_front('a');
	d0.insert(d0.begin() + 1, 'b');
	for(std::deque<char>::size_type i = 0; i < d0.size(); i++) std::cout << d0[i];
	std::cout << std::endl;
	std::cout << d0.front();
	std::cout << d0.back();
	d0.pop_front();
	d0.pop_back();
	std::cout << d0[0] << std::endl;

	return EXIT_SUCCESS;
}