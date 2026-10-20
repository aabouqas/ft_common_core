/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:31:25 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/27 10:31:34 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		int	energyPoint;
	public:
		ScavTrap();
		ScavTrap &operator=(const ScavTrap &Obj);
		ScavTrap (const ScavTrap &Obj);
		~ScavTrap ();
		ScavTrap (std::string name);
		void	attack(const std::string& target);
		void	guardGate();
};
