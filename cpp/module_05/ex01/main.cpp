#include "Bureaucrat.hpp"

int main() {

	try {
		Form form ("Google form", false, 100, 100);
		Bureaucrat b("alice", 3);
		b.signForm(form);
		form.beSigned(b);
		b.signForm(form);
		std::cout << std::endl;
		std::cout << "Grade before increment : " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "Grade after increment : " << b.getGrade() << std::endl;
		std::cout << std::endl;
		for (int i = 0; i <= 10; i++){
			b.incrementGrade();
		}
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
