/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:32 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 15:17:31 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &Obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = Obj.type;
	this->brain = new Brain();
	*this->brain = *Obj.brain;
}

Cat &Cat::operator=(const Cat &Obj) {
	std::cout << "Cat copy assignment constructor called" << std::endl;
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	this->brain = new Brain();
	*this->brain = *Obj.brain;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
