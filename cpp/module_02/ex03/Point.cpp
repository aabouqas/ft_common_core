/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:04:02 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/09 10:37:57 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}

Point::~Point() {
}

Point::Point(const float X, const float Y) : x(X), y(Y) {
}

Point::Point(const Point &Obj) : x(Obj.x) , y(Obj.y)
{
	(void) Obj;
}

Point	&Point::operator=(const Point &Obj) {
	(void) Obj;
	return *this;
}

float	Point::getX() const {
	return this->x.toFloat();
}

float	Point::getY() const {
	return this->y.toFloat();
}
