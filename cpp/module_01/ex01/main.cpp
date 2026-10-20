/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:57:55 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 15:56:13 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int	nZombies = 3;
	Zombie	*zombies = zombieHorde(nZombies, "zombie");
	if (zombies == NULL)
		return 1;
	for (int n = 0;n < nZombies; n++)
		zombies[n].announce();
	delete[] zombies;
	return 0;
}
