/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:56:29 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 17:12:50 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Obj) : AForm(Obj.getName(), Obj.getGradeRequiredToSign(), Obj.getGradeRequiredToExec()) {

}

PresidentialPardonForm&PresidentialPardonForm::operator=(const PresidentialPardonForm &Obj) {
	(void) Obj;
	return *this;
}

int	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeRequiredToExec()) {
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return 0;
	}
	throw GradeTooLowException();
	return 1;
}
