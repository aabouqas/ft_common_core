/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:17:17 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/08 16:13:14 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat {
	private:
		const std::string	name;
		short				grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException();
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
