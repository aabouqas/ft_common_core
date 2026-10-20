/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:57:55 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 15:14:38 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie	*zombie = newZombie("Zombozo 1");
	if (zombie == NULL)
		return 1;
	zombie->announce();
	randomChump("Zombozo 2");
	delete zombie;
	return 0;
}
