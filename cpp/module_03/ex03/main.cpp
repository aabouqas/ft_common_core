/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/27 14:01:21 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {
	DiamondTrap alice = DiamondTrap("alice");
	alice.whoAmI();
	alice.attack("alan");
	alice.highFivesGuys();
	alice.attack("alan");
	alice.highFivesGuys();
	alice.takeDamage(99);
	alice.takeDamage(0);
	alice.attack("alan");
	alice.attack("alan");
	alice.attack("alan");
	alice.beRepaired(99);
	alice.beRepaired(1);
	return 0;
}
