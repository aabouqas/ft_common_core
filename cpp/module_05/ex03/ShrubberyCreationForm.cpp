/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:32:14 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/15 16:16:30 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm ("ShrubberyCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Obj) : AForm(Obj.getName(), Obj.getGradeRequiredToSign(), Obj.getGradeRequiredToExec()) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Obj) {
	if (this == &Obj)
		return *this;
	return *this;
}

int	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeRequiredToExec()) {
		std::ofstream	output(this->target + "_shrubbery");
		if (output.is_open() == false) {
			std::cout << "Cannot open file" << std::endl;
			return 1;
		}
		int n3 = 0;
		for (int n0 = 0; n0 < 20; n0++) {
			int n1 = 0;
			while (n1 < 20) {
				if (n1 + n3 == 10) {
					int n4 = 0;
					while (n4 < n3) {
						if (n4 % 2 == 0)
							output << "o";
						else
							output << "*";
						n4++;
					}
					int skip = n4;
					while (n4 >= 0) {
						if (n4 % 2 == 0)
							output << "x";
						else
							output << "*";
						n4--;
					}
					n1 += skip;
				} else {
					if (n0 > 10 && n1 > 5 && n1 < 15)
						output << "*";
					else
						output << " ";
				}
				n1++;
			}
			output << std::endl;
			n3++;
		}
		output.close();
		return 0;
	}
	throw AForm::GradeTooLowException();
	return 1;
}
