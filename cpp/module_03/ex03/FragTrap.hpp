/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:50:42 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/27 10:31:05 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		int			hitPoint;
		int			attackDamage;
	public:
		FragTrap();
		FragTrap(const FragTrap &Obj);
		FragTrap &operator=(const FragTrap &Obj);
		~FragTrap();
		FragTrap(std::string fragTrapName);
		void	highFivesGuys(void);
};