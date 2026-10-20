/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:22:12 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:20:32 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown") , grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name , short Grade) : name(Name) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (Grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	if (Grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade = Grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Obj) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->grade = Obj.grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &Obj) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this == &Obj)
		return *this;
	this->grade = Obj.grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int	Bureaucrat::getGrade() const {
	return this->grade;
}

void	Bureaucrat::incrementGrade() {
	if (this->grade < 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "the grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "the grade too low";
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	if (form.execute(*this) == 0)
		std::cout << this->name << " executed " << form.getName() << std::endl;
	else
		std::cout << this->name << " couldn’t execute " << form.getName() << std::endl;
}
