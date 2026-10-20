/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:50:42 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/26 16:27:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(const FragTrap &Obj);
		FragTrap &operator=(const FragTrap &Obj);
		~FragTrap();
		FragTrap(std::string fragTrapName);
		void	highFivesGuys(void);
};