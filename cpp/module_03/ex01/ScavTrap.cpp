/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:31:00 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/29 09:42:47 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	this->name = "Unkown";
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &Obj) {
	std::cout << "ScavTrap copy constructor called\n";
	*this = Obj;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &Obj) {
	std::cout << "ScavTrap copy assignment constructor called\n";
	if (this == &Obj)
		return *this;
	this->name = Obj.name;
	this->attackDamage = Obj.attackDamage;
	this->energyPoint = Obj.energyPoint;
	this->hitPoint = Obj.hitPoint;
	return *this;
}

ScavTrap::ScavTrap(std::string name) {
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	this->name = name;
	std::cout << "ScavTrap constructor called\n";
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energyPoint == 0 || this->hitPoint == 0) {
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
	if (this->energyPoint > 0)
		this->energyPoint--;
}


void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}
