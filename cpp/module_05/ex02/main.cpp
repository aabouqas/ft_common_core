#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	ShrubberyCreationForm	*shrubbery = NULL;
	AForm					*president = NULL;
	RobotomyRequestForm		*robotomy = NULL;
	try {
		Bureaucrat bureaucrat("Alice", 3);
		shrubbery = new ShrubberyCreationForm("Alan");
		president = new PresidentialPardonForm("Alan");
		robotomy = new RobotomyRequestForm("Alan");
		std::cout << "---------------------------" << std::endl;
		shrubbery->beSigned(bureaucrat);
		bureaucrat.signForm(shrubbery);

		president->beSigned(bureaucrat);
		bureaucrat.signForm(president);

		shrubbery->execute(bureaucrat);
		robotomy->beSigned(bureaucrat);
		robotomy->execute(bureaucrat);
		
		president->execute(bureaucrat);
		std::cout << "---------------------------" << std::endl;
		bureaucrat.executeForm(*robotomy);
		std::cout << "---------------------------" << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete shrubbery;
	delete president;
	delete robotomy;
	return 0;
}
