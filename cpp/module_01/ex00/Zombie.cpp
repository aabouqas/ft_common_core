/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 08:43:50 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 15:14:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	this->name = "zombie";
}

Zombie::~Zombie() {
	std::cout << name << " destroyed\n";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << name << " : BraiiiiiiinnnzzzZ...\n";
}
