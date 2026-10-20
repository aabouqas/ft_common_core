/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:51:15 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:15:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45),  target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Obj) {
	*this = Obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &Obj) {
	if (this == &Obj)
		return *this;
	return *this;
}

void	RobotomyRequestForm::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeRequiredToSign()) {
		this->setSign(true);
		return;
	}
	throw AForm::GradeTooLowException();
}

int	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false)
	{
		throw AForm::NotSignedException();
		return 1;
	}
	if (executor.getGrade() <= this->getGradeRequiredToExec()) {
		if (((time(NULL)) % 2 == 0))
			std::cout << this->target << " has been robotomized" << std::endl;
		else
			std::cout << "failed to " << "robotomization " << this->target  << std::endl;
		return 0;
	}
	throw AForm::GradeTooLowException();
	return 1;
}
