/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:48:22 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/23 16:01:37 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	readUserInput(PhoneBook &phonebook)
{
	Contact		contact;
	std::string	input;
	bool		first;

	std::string red = "\033[31m";
	std::string green = "\033[32m";
	std::string reset = "\033[0m";
	first = true;
	while (std::cin.eof() != true)
	{
		if (first)
		{
			std::cout << "  Enter your first name : ";
			first = false;
		} else
			std::cout << red << "  Enter your first name : " << reset;
		std::getline(std::cin, input);
		if (isValidName(input))
			break ;
	}
	first = true;
	contact.setFirstName(input);
	while (std::cin.eof() != true)
	{
		if (first)
		{
			std::cout << "  Enter your last name : ";
			first = false;
		} else {
			std::cout << red << "  Enter your last name : " << reset;
		}
		std::getline(std::cin, input);
		if (isValidName(input))
			break;
	}
	first = true;
	contact.setLastName(input);
	while (std::cin.eof() != true)
	{
		if (first) {
			std::cout << "  Enter a nickname : ";
			first = false;
		} else {
			std::cout << red << "  Enter a nickname : " << reset;
		}
		std::getline(std::cin, input);
		if (isValidName(input))
			break ;
	}
	first = true;
	contact.setNickName(input);
	while (std::cin.eof() != true)
	{
		if (first) {
			std::cout << "  Enter your phone number : ";
			first = false;
		} else {
			std::cout << red << "  Enter your phone number : " << reset;
		}
		std::getline(std::cin, input);
		if (isValidNumber(input))
			break ;
	}
	first = true;
	contact.setPhoneNumber(input);
	while (std::cin.eof() != true)
	{
		if (first) {
			std::cout << "  Enter your secret : ";
			first = false;
		} else {
			std::cout << red << "  Enter your secret : " << reset;
		}
		std::getline(std::cin, input);
		if (input.length() == 0)
			continue;
		contact.setDarkestSecret(input);
		break;
	}
	if (std::cin.eof() == true)
		return -1;
	phonebook.addContact (contact);
	std::cout<< green << "  #AddedSuccessfully" << reset.append("\n");
	if (phonebook.Amount < 8)
		phonebook.Amount++;
	return (0);
}


int	searchContact(PhoneBook phonebook)
{
	std::string	input;
	int			index;
	bool		first;

	index = 0;
	first = true;
	if (phonebook.Amount == 0)
	{
		std::cout << " Empty\n";
		return 0;
	}
	while (std::cin.eof() != true)
	{
		if (index == 0)
			phonebook.displayContacts();
		if (first)
		{
			std::cout << "Enter an index ";
			first = false;
		} else
			std::cout << "\033[31m" << "Enter an index " << "\033[0m";
		std::getline(std::cin, input);
		index = isValidIndex(input, phonebook);
		if (index == -1)
			continue ;
		phonebook.displayContactAtIndex(index);
		break ;
	}
	return (0);
}

int main() {

	std::string	command;
	PhoneBook	phonebook;

	while (std::cin.eof() != true)
	{
		std::cout << "PhoneBook > ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		if (command == "ADD") {
			readUserInput(phonebook);
		} else if (command == "SEARCH") {
			searchContact(phonebook);
		}
	}
	if (command != "EXIT")
		std::cout << "EXIT\n";
	return 0;
}
