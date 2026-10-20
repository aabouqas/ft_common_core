/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:42:05 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 15:06:05 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int n = 0; n < 100; n++)
		this->ideas[n] = "";
}

Brain::Brain(const Brain &Obj) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int n = 0; n < 100; n++)
		this->ideas[n] = Obj.ideas[n];
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &Obj) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this == &Obj)
		return *this;
	for (int n = 0; n < 100; n++)
		this->ideas[n] = Obj.ideas[n];
	return *this;
}
