/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:18:34 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 17:27:14 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &Obj);
		Intern&operator=(const Intern &Obj);
		AForm	*makeForm(const std::string &formName, const std::string &targetOfTheForm);
		class FormNameNotFoundException : public std::exception {
			public:
				const char *what() const throw();
		};
};