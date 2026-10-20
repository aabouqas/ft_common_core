/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:15:51 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 10:55:08 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &Obj) {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = Obj;
}

Cure &Cure::operator=(const Cure &Obj) {
	std::cout << "Cure copy assignment constructor called" << std::endl;
	if (this == &Obj)
		return *this;
	return *this;
}

AMateria	*Cure::clone() const {
	Cure *cure = new Cure();
	return cure;
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *";
}
