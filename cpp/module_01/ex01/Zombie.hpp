/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:58:20 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/25 09:22:47 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void	announce(void);
};
Zombie	*zombieHorde(int N, std::string name);

#endif