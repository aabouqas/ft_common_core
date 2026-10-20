/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:39 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/03 09:40:13 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &Obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = Obj.type;
}

Dog &Dog::operator=(const Dog &Obj) {
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}
