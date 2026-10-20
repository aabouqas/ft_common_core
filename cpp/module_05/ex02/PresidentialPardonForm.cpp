/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:56:29 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:16:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), target(target) {
	
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Obj) {
	*this = Obj;
}

PresidentialPardonForm&PresidentialPardonForm::operator=(const PresidentialPardonForm &Obj) {
	if (this == &Obj)
		return *this;
	return *this;
}

void	PresidentialPardonForm::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeRequiredToSign()) {
		this->setSign(true);
		return ;
	}
	throw AForm::GradeTooLowException();
}

int	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false)
	{
		throw AForm::NotSignedException();
		return 1;
	}
	if (executor.getGrade() <= this->getGradeRequiredToExec()) {
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return 0;
	}
	throw GradeTooLowException();
	return 1;
}
