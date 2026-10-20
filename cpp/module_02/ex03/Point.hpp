/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:18:16 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/09 10:36:05 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point ();
		~Point ();
		Point (const float _x, const float _y);
		Point (const Point &Obj);
		Point	&operator=(const Point &Obj);
		float	getX(void) const;
		float	getY(void) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);