/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:20:22 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/27 11:35:35 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called\n";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
	ClapTrap::name = "Unknown_clap_name";
	this->name = "Unknown";
}

DiamondTrap::DiamondTrap(std::string diamondTrapName) {
	std::cout << "DiamondTrap constructor called\n";
	this->name = diamondTrapName;
	ClapTrap::name = diamondTrapName + "_clap_name";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &Obj) {
	std::cout << "DiamondTrap copy constructor called\n";
	*this = Obj;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &Obj) {
	std::cout << "DiamondTrap copy assignment constructor called\n";
	if (this == &Obj)
		return *this;
	this->attackDamage = Obj.attackDamage;
	this->energyPoint = Obj.energyPoint;
	this->hitPoint = Obj.hitPoint;
	this->name = Obj.name;
	return *this;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "ClapTrap name : " << ClapTrap::name + "\n";
	std::cout << "DiamondTrap name : " << this->name + "\n";
}
