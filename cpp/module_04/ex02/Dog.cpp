/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:39 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 15:12:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &Obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = Obj.type;
	this->brain = new Brain();
	*this->brain = *Obj.brain;
}

Dog &Dog::operator=(const Dog &Obj) {
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	this->brain = new Brain();
	*this->brain = *Obj.brain;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}
