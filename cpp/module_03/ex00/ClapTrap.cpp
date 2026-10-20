/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:29:13 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/29 09:54:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	this->name = "Unkown";
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) {
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	this->name = name;
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &Obj) {
	std::cout << "ClapTrap copy constructor called\n";
	*this = Obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &Obj) {
	std::cout << "ClapTrap copy assignment constructor called\n";
	if (this == &Obj)
		return *this;
	this->attackDamage = Obj.attackDamage;
	this->hitPoint = Obj.hitPoint;
	this->name = Obj.name;
	this->energyPoint = Obj.energyPoint;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called\n";
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energyPoint == 0 || this->hitPoint == 0) {
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
	if (this->energyPoint > 0)
		this->energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->energyPoint == 0 || this->hitPoint == 0) {
		return ;
	}
	std::cout << "ClapTrap " << this->name << " takes damage causing loss " << amount << " points of hit point!\n";
	this->hitPoint -= amount;
	if (this->hitPoint <= 0)
		this->hitPoint = 0;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoint == 0 || this->hitPoint == 0) {
		return ;
	}
	std::cout << "ClapTrap " << this->name << " rest " << amount << " hit point!\n";
	this->hitPoint += amount;
	if (this->energyPoint > 0)
		this->energyPoint--;
}
