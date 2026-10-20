/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:48:48 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/30 18:03:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &Obj);
		Fixed &operator=(const Fixed &Obj);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		
};