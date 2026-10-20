/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:34:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/25 16:46:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl = Harl();
	std::string s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int n = 0;
	while (n <= 3)
	{
		std::cout << s[n] + " : ";
		harl.complain(s[n]);
		n++;
	}
}
