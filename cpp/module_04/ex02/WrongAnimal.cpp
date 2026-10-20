/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:56:33 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/03 09:41:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Obj) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = Obj;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &Obj) {
	std::cout << "WrongAnimal copy assignment constructor called" << std::endl;
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}
