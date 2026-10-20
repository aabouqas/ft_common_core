#include <iostream>

int main(int argc, char *argv[]) {
	int i = 1;
	int j = 0;
	char c = 0;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}
	while (argv[i]) {
		j = 0;
		while (argv[i][j]) {
			c = argv[i][j];
			if (islower(c))
				c -= 32;
			j++;
			std::cout << c;
		}
		i++;
	}
	std:: cout << "\n";
	return 0;
}
