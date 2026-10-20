/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:38:14 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 07:45:01 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	
}

Harl::~Harl() {
	
}

void	Harl::complain(std::string level) {
	std::string s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int n = 0;
	while (n < 3) {
		if (level == s[n])
			break;
		n++;
	}
	if (level != s[n])
	{
		std::cerr << "[ Probably complaining about insignificant problems ]\n";
		return ;
	}
	switch (n) {
		case 0:
			std::cout << "[ " << s[n] << " ]\n";
			(this->*ptr[n])();
			n++;
		case 1:
			std::cout << "[ " << s[n] << " ]\n";
			(this->*ptr[n])();
			n++;
		case 2:
			std::cout << "[ " << s[n] << " ]\n";
			(this->*ptr[n])();
			n++;
		case 3:
			std::cout << "[ " << s[n] << " ]\n";
			(this->*ptr[n])();
		default:
			break;
	}
}

void	Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}
void	Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";

}
