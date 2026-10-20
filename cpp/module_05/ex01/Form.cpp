/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:23:00 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/09 12:59:27 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Global Form"), Signed(false), gradeRequiredToSign(100) , gradeRequiredToExec(75)  {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, bool sign, short reqGradeSign, short reqGradeExec) : name(name), Signed(sign), gradeRequiredToSign(reqGradeSign), gradeRequiredToExec(reqGradeExec) {
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &Obj) : name(Obj.name), Signed(Obj.Signed), gradeRequiredToSign(Obj.gradeRequiredToSign), gradeRequiredToExec(Obj.gradeRequiredToExec) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &Obj) {
	(void) Obj;
	std::cout << "Form copy assignment operator called" << std::endl;
	return *this;
}

void	Form::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeRequiredToSign) {
		this->Signed = true;
		return ;
	}
	throw Form::GradeTooLowException();
}

std::string	Form::getName() const {
	return this->name;
}

short	Form::getGradeRequiredToSign() const {
	return this->gradeRequiredToSign;
}

short	Form::getGradeRequiredToExec() const {
	return this->gradeRequiredToExec;
}

bool	Form::getSign() const {
	return this->Signed;
}

std::ostream	&operator<<(std::ostream &os, Form &form) {
	os << "Name : " << form.getName() << std::endl;
	os << "GradeRequiredToSign : " << form.getGradeRequiredToSign() << std::endl;
	os << "GradeRequiredToExec : " << form.getGradeRequiredToExec() << std::endl;
	os << "Signed : " << form.getSign() << std::endl;
	return os;
}

Form::GradeTooLowException::GradeTooLowException() {
	
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Error : The Grade Too Low";
}