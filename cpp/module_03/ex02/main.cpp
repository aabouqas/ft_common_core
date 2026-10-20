/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/26 16:40:54 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main() {
	FragTrap alice = FragTrap("alice");
	alice.highFivesGuys ();
	alice.attack("alan");
	alice.takeDamage(99);
	alice.takeDamage(0);
	alice.attack("alan");
	alice.attack("alan");
	alice.attack("alan");
	alice.beRepaired(99);
	alice.beRepaired(1);
	return 0;
}
