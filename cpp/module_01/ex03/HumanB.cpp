/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:34:39 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/28 10:53:21 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::~HumanB() {
	
}

HumanB::HumanB(std::string name, Weapon &weapon) {
	this->name = name;
	this->weapon = &weapon;
}


HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
