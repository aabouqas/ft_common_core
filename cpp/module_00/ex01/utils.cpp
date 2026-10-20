/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:02:37 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/22 16:12:04 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	isValidIndex(std::string input, PhoneBook phoneBook)
{
	int	index;

	if (isValidNumber(input.c_str()) == false || input.length() != 1)
		return -1;
	index = atoi(input.c_str());
	if (index > 7 || index > (phoneBook.Amount - 1))
		return -1;
	return (index);
}

bool	isValidNumber(std::string input)
{
	int i = 0;
	if (input == "")
		return false;
	while (input[i] != '\0')
	{
		if (isnumber(input[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

int	isValidName(std::string &String) {
	int	i = 0;

	if (String == "")
		return (0);
	while (String[i]) {
		if (String[i] != ' ' && !isalpha(String[i]))
			return 0;
		i++;
	}
	return 1;
}
