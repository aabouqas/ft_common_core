/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:48:48 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/02 12:37:20 by aabouqas         ###   ########.fr       */
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
		void			setRawBits(int const raw);
		int				getRawBits(void) const;
		float			toFloat(void) const;
		int				toInt( void ) const;
};
std::ostream	&operator<<(std::ostream &os, const Fixed &Obj);
