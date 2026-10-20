/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:17:17 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:11:48 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string	name;
		short				grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &Obj);
		Bureaucrat&operator=(const Bureaucrat &Obj);
		Bureaucrat(const std::string &name, short grade);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
