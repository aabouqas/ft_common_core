/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:58:20 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 11:08:50 by aabouqas         ###   ########.fr       */
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
Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

#endif