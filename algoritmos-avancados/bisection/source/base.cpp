#include <iostream>
#include <cmath>

double f(double val) {
	int loan = 1000;
	double tax = 1.1;

	return (loan * tax - val + (loan * tax - val) * tax - val);
}

int main() {
	double start, end, tol, mean, error = 1;
	int iterations = 0;

	std::cin >> start;
	std::cin >> end;
	std::cin >> tol;

	while (error > tol) {
		mean = (start + end) / 2;
		if (f(mean) == 0 || error <= tol) {
			break;
		}

		if (f(mean) * f(start) < 0) {
			end = mean;
		} else {
			start = mean;
		}
		iterations += 1;
		error = (end - start) / 2;
	}

	std::cout << abs(mean) << "\n" << iterations << " iterations!\n";

	return EXIT_SUCCESS;
}