/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:23:00 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 15:32:57 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Global Form"), Signed(false), gradeRequiredToSign(100) , gradeRequiredToExec(75)  {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, bool sign, short reqGradeSign, short reqGradeExec) : name(name), Signed(sign), gradeRequiredToSign(reqGradeSign), gradeRequiredToExec(reqGradeExec) {
	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(const AForm &Obj) : name(Obj.name), Signed(Obj.Signed), gradeRequiredToSign(Obj.gradeRequiredToSign), gradeRequiredToExec(Obj.gradeRequiredToExec) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &Obj) {
	(void) Obj;
	std::cout << "AForm copy assignment operator called" << std::endl;
	return *this;
}

void	AForm::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeRequiredToSign) {
		this->Signed = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}

std::string	AForm::getName() const {
	return this->name;
}

void	AForm::setSign(bool sign) {
	this->Signed = sign;
}

short	AForm::getGradeRequiredToSign() const {
	return this->gradeRequiredToSign;
}

short	AForm::getGradeRequiredToExec() const {
	return this->gradeRequiredToExec;
}

bool	AForm::getSign() const {
	return this->Signed;
}

std::ostream	&operator<<(std::ostream &os, AForm &form) {
	os << "Name : " << form.getName() << std::endl;
	os << "GradeRequiredToSign : " << form.getGradeRequiredToSign() << std::endl;
	os << "GradeRequiredToExec : " << form.getGradeRequiredToExec() << std::endl;
	os << "Signed : " << form.getSign() << std::endl;
	return os;
}

AForm::GradeTooLowException::GradeTooLowException() {

}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Error : The Grade Too Low";
}

AForm::NotSignedException::NotSignedException() {

}

const char *AForm::NotSignedException::what() const throw() {
	return "Error : The form not signed";
}