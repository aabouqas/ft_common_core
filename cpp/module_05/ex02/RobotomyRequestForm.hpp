/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:49:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:15:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string	target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &Obj);
		RobotomyRequestForm&operator=(const RobotomyRequestForm &Obj);
		void	beSigned(Bureaucrat bureaucrat);
		int		execute(Bureaucrat const &executor) const;
};