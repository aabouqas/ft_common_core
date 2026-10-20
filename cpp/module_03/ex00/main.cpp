/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/24 13:59:26 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap alice("alice");
	ClapTrap alan("alan");
	alan.attack("alice");
	alan.takeDamage(50);
	alan.attack("alice");
	alan.attack("alice");
	alan.attack("alice");
	alan.beRepaired(9);
	alan.beRepaired(1);
	return 0;
}
