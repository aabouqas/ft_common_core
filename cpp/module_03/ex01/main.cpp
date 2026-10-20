/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/29 10:16:39 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main() {
	ScavTrap alice = ScavTrap("alice");
	alice.guardGate();
	alice.attack("alan");
	alice.takeDamage(500);
	alice.takeDamage(500);
	alice.takeDamage(500);
	alice.takeDamage(500);
	alice.takeDamage(500);
	alice.takeDamage(500);
	alice.attack("alan");
	alice.attack("alan");
	alice.attack("alan");
	alice.beRepaired(9);
	alice.beRepaired(1);
	return 0;
}
