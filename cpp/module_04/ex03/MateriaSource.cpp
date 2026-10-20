/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 07:41:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 10:59:34 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int n = 0;n < 4; n++)
		this->materias[n] = NULL;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int n = 0;n < 4; n++)
		delete this->materias[n];
}

MateriaSource::MateriaSource(const MateriaSource &Obj) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	if (this == &Obj)
		return ;
	for (int n = 0;n < 4; n++)
		this->materias[n] = NULL;
	for (int n = 0;n < 4; n++) {
		if (Obj.materias[n] != NULL)
			this->materias[n] = Obj.materias[n]->clone();
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &Obj) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this == &Obj)
		return *this;
	for (int n = 0;n < 4; n++) {
		delete this->materias[n];
		if (Obj.materias[n] != NULL)
			this->materias[n] = Obj.materias[n]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m) {
	int n = 0;
	while (n < 4 && this->materias[n] != NULL)
		n++;
	if (n < 4 && this->materias[n] == NULL)
		this->materias[n] = m;
}


AMateria	*MateriaSource::createMateria(std::string const &type) {
	if (type == "ice")
		return new Ice();
	else if (type == "cure")
		return new Cure();
	return 0;
}
