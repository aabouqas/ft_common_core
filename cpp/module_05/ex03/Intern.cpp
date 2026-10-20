/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:18:24 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 18:22:52 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>
Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern &Obj) {
	(void) Obj;
}

Intern&Intern::operator=(const Intern &Obj) {
	(void)Obj;
	return *this;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &targetOfTheForm) {

	AForm	*form = NULL;
	std::string	formsName[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon",
	};
	AForm	*forms[3] = {
		new RobotomyRequestForm(targetOfTheForm),
		new ShrubberyCreationForm(targetOfTheForm),
		new PresidentialPardonForm(targetOfTheForm),
	};
	for (int n = 0; n < 3; n++) {
		if (formsName[n] == formName) {
			form = forms[n];
			forms[n] = NULL;
		}
	}
	for (int n = 0; n < 3; n++) {
		delete forms[n];
	}
	std::cout << form << std::endl;
	if (form == NULL)
		throw Intern::FormNameNotFoundException();
	return form;
}
const char *Intern::FormNameNotFoundException::what() const throw() {
	return "form name not found";
}
