#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
	Intern	intern;
	AForm *robotomy = NULL;
	AForm *shrubbery = NULL;
	AForm *president = NULL;
	try {
		Bureaucrat bureaucrat("Alice", 3);
		robotomy = intern.makeForm("robotomy request", "Bender");
		shrubbery = intern.makeForm("shrubbery creation", bureaucrat.getName());
		president = intern.makeForm("presidentidal pardon", bureaucrat.getName());
		std::cout << "---------------------------" << std::endl;
		bureaucrat.signForm(*shrubbery);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*president);
		bureaucrat.signForm(*robotomy);

		std::cout << "---------------------------" << std::endl;
		shrubbery->execute(bureaucrat);
		robotomy->execute(bureaucrat);
		president->execute(bureaucrat);
		std::cout << "---------------------------" << std::endl;
		std::cout << "---------------------------" << std::endl;
		bureaucrat.executeForm(*robotomy);
		bureaucrat.executeForm(*shrubbery);
		bureaucrat.executeForm(*president);
		std::cout << "---------------------------" << std::endl;
		std::cout << "---------------------------" << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete robotomy;
	delete shrubbery;
	delete president;
	return 0;
}
