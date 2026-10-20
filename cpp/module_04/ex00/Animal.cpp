/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:09:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/03 09:39:33 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &Obj) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = Obj;
}

Animal	&Animal::operator=(const Animal &Obj) {
	std::cout << "Animal copy assignment constructor called" << std::endl;
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType() const {
	return this->type;
}
