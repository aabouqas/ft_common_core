/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:23:12 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:15:09 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				Signed;
		const short			gradeRequiredToSign;
		const short			gradeRequiredToExec;
	public:
		AForm();
		virtual ~AForm();
		AForm (const std::string &name, short reqGradeSign, short reqGradeExec);
		AForm(const AForm &Obj);
		AForm&operator=(const AForm &Obj);
		void		beSigned(Bureaucrat &bureaucrat);
		std::string	getName() const;
		bool		getSign() const;
		short		getGradeRequiredToSign() const;
		short		getGradeRequiredToExec() const;
		virtual int	execute(Bureaucrat const &executor) const = 0;
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#include "Bureaucrat.hpp"
