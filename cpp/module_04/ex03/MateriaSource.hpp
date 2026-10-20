/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:08:54 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 10:54:38 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "Character.hpp"

#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource&operator=(const MateriaSource &obj);
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};