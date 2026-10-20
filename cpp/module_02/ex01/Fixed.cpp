/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:57:52 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/08 09:17:05 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() {
	this->fixedPoint = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int number) {
	this->fixedPoint = number * (1 << fractionalBits);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number) {
	this->fixedPoint = roundf (number * (1 << fractionalBits));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &Obj) {
	std::cout << "Copy constructor called\n";
	*this = Obj;
}

Fixed	&Fixed::operator=(const Fixed &Obj) {
	std::cout << "Copy assignment operator called\n";
	if (this == &Obj)
		return *this;
	this->fixedPoint = Obj.getRawBits();
	return *this;
}

int	Fixed::toInt(void) const {
	return (int) (this->fixedPoint / (1 << fractionalBits));
}

float	Fixed::toFloat (void) const {
	return (float)this->fixedPoint / (1 << fractionalBits);
}

int	Fixed::getRawBits(void) const {
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &Obj) {
	os << Obj.toFloat();
	return os;
}
