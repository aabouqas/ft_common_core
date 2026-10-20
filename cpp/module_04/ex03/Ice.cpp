/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:10:46 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 10:03:49 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	std::cout << "Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &Obj) {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = Obj;
}

Ice &Ice::operator=(const Ice &Obj) {
	std::cout << "Ice copy assignment constructor called" << std::endl;
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	return *this;
}

AMateria *Ice::clone() const {
	std::cout << "Ice clone method called" << std::endl;
	Ice *ice = new Ice();
	return ice;
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

