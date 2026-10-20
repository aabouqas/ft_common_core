/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:44:45 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/25 09:39:41 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon {
	private:
		std::string type;
		
	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);
		const std::string	&getType();
		void	setType(std::string type);
	
};
