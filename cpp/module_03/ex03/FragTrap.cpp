/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:50:22 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/27 09:55:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	this->name = "Unknown";
}

FragTrap::FragTrap(std::string fragTrapName) {
	std::cout << "FragTrap constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	this->name = fragTrapName;
}

FragTrap	&FragTrap::operator=(const FragTrap &Obj) {
	std::cout << "FragTrap copy assignment called\n";
	if (this == &Obj)
		return *this;
	this->attackDamage = Obj.attackDamage;
	this->energyPoint = Obj.energyPoint;
	this->hitPoint = Obj.hitPoint;
	this->name = Obj.name;
	return *this;
}

FragTrap::FragTrap(const FragTrap &Obj) {
	std::cout << "FragTrap copy destructor called\n";
	*this = Obj;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called\n";
}

void	FragTrap::highFivesGuys() {
	std::cout << "High five guys ^^\n";
}
