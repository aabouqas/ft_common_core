/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:29:51 by aabouqas          #+#    #+#             */
/*   Updated: 2024/09/03 13:23:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point a = Point(5, 0);
	Point b = Point(10, 5);
	Point c = Point(0, 5);
	Point	d(1, 5);
	std::cout << bsp(a, b, c, d) << "\n";
	return 0;
}
