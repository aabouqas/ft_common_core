/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:23:12 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/09 09:41:45 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool Signed;
		const short gradeRequiredToSign;
		const short gradeRequiredToExec;
	public:
		Form();
		~Form();
		Form (const std::string &name, bool sign, short reqGradeSign, short reqGradeExec);
		Form(const Form &Obj);
		Form&operator=(const Form &Obj);
		void		beSigned(Bureaucrat bureaucrat);
		std::string	getName() const;
		bool		getSign() const;
		short		getGradeRequiredToSign() const;
		short		getGradeRequiredToExec() const;
		class GradeTooLowException : std::exception {
			public:
				GradeTooLowException();
				const char *what() const throw();
		};
};