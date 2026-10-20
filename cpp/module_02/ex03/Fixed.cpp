/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:57:52 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/08 06:52:39 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() {
	this->fixedPoint = 0;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int number) {
	this->fixedPoint = number * (1 << fractionalBits);
}

Fixed::Fixed(const float number) {
	this->fixedPoint = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &Obj) {
	*this = Obj;
}

Fixed	&Fixed::operator=(const Fixed &Obj) {
	if (this == &Obj)
		return *this;
	this->fixedPoint = Obj.getRawBits();
	return *this;
}

int	Fixed::toInt(void) const {
	return (int) (this->fixedPoint / (1 << fractionalBits));
}

float	Fixed::toFloat (void) const {
	return (float) this->fixedPoint / (1 << fractionalBits);
}

int	Fixed::getRawBits(void) const {
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

// STREAM OPERATOR
std::ostream	&operator<<(std::ostream &os, const Fixed &Obj) {
	os << Obj.toFloat();
	return os;
}

// OPERATORS
Fixed	Fixed::operator+(const Fixed Obj) {
	return Fixed(this->toFloat() + Obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed Obj) {
	return Fixed(this->toFloat() - Obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed Obj) {
	return Fixed(this->toFloat() * Obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed Obj) {
	return Fixed(this->toFloat() / Obj.toFloat());
}

// PRE-INCREMENT
Fixed	Fixed::operator++(int) {
	Fixed point = *this;
	this->fixedPoint++;
	return point;
}

// INCREMENT
Fixed	&Fixed::operator++() {
	this->fixedPoint++;
	return *this;
}

// DECREMENT
Fixed	Fixed::operator--(int) {
	Fixed point = *this;
	this->fixedPoint--;
	return point;
}

// PRE-DECREMENT
Fixed	&Fixed::operator--() {
	this->fixedPoint--;
	return *this;
}

// LOGICAL OPERATOR
bool	Fixed::operator>(const Fixed Obj) const {
	return (this->fixedPoint > Obj.fixedPoint);
}

bool	Fixed::operator<(const Fixed Obj) const {
	return (this->fixedPoint < Obj.fixedPoint);
}

bool	Fixed::operator>=(const Fixed Obj) const {
	return (this->fixedPoint >= Obj.fixedPoint);
}

bool	Fixed::operator<=(const Fixed Obj) const {
	return (this->fixedPoint <= Obj.fixedPoint);
}

bool	Fixed::operator==(const Fixed Obj) const {
	return (this->fixedPoint == Obj.fixedPoint);
}

// MIN AND MAX
Fixed	&Fixed::min(Fixed &number1, Fixed &number2) {
	if (number1.fixedPoint < number2.fixedPoint)
		return number1;
	return number2;
}

const Fixed	&Fixed::min(const Fixed &number1, const Fixed &number2) {
	if (number1.fixedPoint < number2.fixedPoint)
		return number1;
	return number2;
}

Fixed	&Fixed::max(Fixed &number1, Fixed &number2) {
	if (number1.fixedPoint > number2.fixedPoint)
		return number1;
	return number2;
}

const Fixed	&Fixed::max(const Fixed &number1, const Fixed &number2) {
	if (number1.fixedPoint > number2.fixedPoint)
		return number1;
	return number2;
}
