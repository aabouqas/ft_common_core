/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:27:04 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 10:14:56 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << "Character constructor called" << std::endl;
	for (int n = 0; n < 4; n++) {
		this->materias[n] = NULL;
	}
	this->name = "unknown";
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int n = 0; n < 4; n++) {
		delete this->materias[n];
	}
}

Character::Character(const Character &Obj) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int n = 0; n < 4; n++) {
		this->materias[n] = NULL;
	}
	for (int n = 0; n < 4; n++) {
		if (Obj.materias[n] != NULL)
			this->materias[n] = Obj.materias[n]->clone();
	}
	this->name = Obj.name;
}

Character &Character::operator=(const Character &Obj) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this == &Obj)
		return *this;
	this->name = Obj.name;
	for (int n = 0; n < 4; n++) {
		delete this->materias[n];
		if (Obj.materias[n] != NULL)
			this->materias[n] = Obj.materias[n]->clone();
	}
	return *this;
}

void	Character::equip(AMateria *m) {
	int n = 0;
	while (n < 4 && this->materias[n] != NULL)
		n++;
	if (n < 4 && this->materias[n] == NULL)
		materias[n] = m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 4)
		return ;
	this->materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 4)
		return ;
	if (this->materias[idx] != NULL) {
		this->materias[idx]->use(target);
	}
}

std::string const	&Character::getName() const {
	return this->name;
}

Character::Character(const std::string &name) {
	this->name = name;
	for (int n = 0; n < 4; n++) {
		this->materias[n] = NULL;
	}
}
