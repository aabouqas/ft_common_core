/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:14:18 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 16:32:15 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie *zombies = new (std::nothrow) Zombie[N];
	if (zombies == NULL)
		return NULL;
	for (int n = 0; n < N; n++)
		new (&zombies[n]) Zombie(name);
	return zombies;
}
