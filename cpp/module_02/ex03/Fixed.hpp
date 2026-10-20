/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:48:48 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/02 19:01:38 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &Obj);
		Fixed			&operator=(const Fixed &Obj);
		Fixed			operator+(const Fixed Obj);
		Fixed			operator-(const Fixed Obj);
		Fixed			operator*(const Fixed Obj);
		Fixed			operator/(const Fixed Obj);
		Fixed			operator++(int n);
		Fixed			operator--(int n);
		Fixed			&operator++();
		Fixed			&operator--();
		bool			operator>(const Fixed Obj)  const;
		bool			operator<(const Fixed Obj)  const;
		bool			operator>=(const Fixed Obj) const;
		bool			operator<=(const Fixed Obj) const;
		bool			operator==(const Fixed Obj) const;
		bool			operator!=(const Fixed Obj) const;
		void			setRawBits(int const raw);
		int				getRawBits(void) const;
		float			toFloat(void) const;
		int				toInt(void) const;
		static Fixed				&min(Fixed &number1, Fixed &number2);
		static const Fixed			&min(const Fixed &number1, const Fixed &number2);
		static Fixed				&max(Fixed &number1, Fixed &number2);
		static const Fixed			&max(const Fixed &number1, const Fixed &number2);
};
std::ostream	&operator<<(std::ostream &os, const Fixed &Obj);