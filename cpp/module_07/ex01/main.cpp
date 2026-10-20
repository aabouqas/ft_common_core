#include "iter.hpp"

#define SIZE 3

int main () {
	int integers[SIZE] = {10, 11, 12};
	double doubles[SIZE] = {10.2, 11.8, 12.94};
	char str[SIZE + 1] = "abc";

	std::cout << "integers : " << std::endl;
	iter(integers, SIZE, display<int>);

	std::cout << "chars : " << std::endl;
	iter(str, SIZE, display<char>);

	std::cout << "doubles : "<< std::endl;
	iter(doubles, SIZE, display<double>);

	return 0;
}
