/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:22:05 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/03 12:01:46 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	getArea(Point const a, Point const b, Point const c)
{
	float	area = 0.0;

	area = (
			(a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY()))
	) ;
	if (area < 0)
		area *= -1;
	return area / 2.0f;
}


bool	bsp ( Point const a, Point const b, Point const c, Point const point) {
	float	MainTriangleArea;
	float	pac = 0;
	float	pbc = 0;
	float	pab = 0;

	MainTriangleArea = getArea(a, b, c);
	pac = getArea(point, a, c);
	pbc = getArea(point, b, c);
	pab = getArea(point, a, b);
	return (MainTriangleArea == (pac + pbc + pab));
}
