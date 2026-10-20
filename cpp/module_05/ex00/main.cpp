#include "Bureaucrat.hpp"

int main() {
	Bureaucrat *b = new Bureaucrat("alice", 10);

	try {
		for (int i = 0; i < 160; i++){
			b->decrementGrade();
		}
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
