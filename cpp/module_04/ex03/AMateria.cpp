/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:58:44 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/03 17:32:51 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	
}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

AMateria::~AMateria() {

}

AMateria::AMateria(const AMateria &Obj) {
	*this = Obj;
}

AMateria &AMateria::operator=(const AMateria &Obj) {
	if (this == &Obj)
		return *this;
	this->type = Obj.type;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->type;
}


void AMateria::use(ICharacter& target) {
	(void)target;
}

