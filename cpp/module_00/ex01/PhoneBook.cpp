/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:43:53 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/24 09:59:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	PhoneBook::addContact(Contact contact) {
	if (index > 7)
		index = 0;
	PhoneBook::contacts[index].setFirstName(contact.getFirstName());
	PhoneBook::contacts[index].setLastName(contact.getLastName());
	PhoneBook::contacts[index].setNickName(contact.getNickName());
	PhoneBook::contacts[index].setPhoneNumber(contact.getPhoneNumber());
	PhoneBook::contacts[index].setDarkestSecret(contact.getDarkestSecret());
	PhoneBook::index++;
}

void	PhoneBook::displayContacts() {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;

	std::cout << std::setw(10) << "|" << std::setw(10) << "Index|" << std::setw(10) << "FirstName|" << std::setw(10) << "LastName|" << std::setw(10) << "NickName|" << std::endl;
	for (int n = 0; n < Amount; n++)
	{
		first_name = contacts[n].getFirstName();
		last_name = contacts[n].getLastName();
		nickname = contacts[n].getNickName();
		if (first_name.length() >= 10)
		{
			if (first_name.length() > 10)
				first_name[9] = '.';
			first_name = first_name.substr(0, 10);
		}
		if (last_name.length() >= 10)
		{
			if (first_name.length() > 10)
				last_name[9] = '.';
			last_name = last_name.substr(0, 10);
		}
		if (nickname.length() >= 10)
		{
			if (first_name.length() > 10)
				nickname[9] = '.';
			nickname = nickname.substr(0, 10);
		}
		std::cout << std::setw(10) << "|" << std::setw(10) << std::to_string(n) + "|" << std::setw(10) << first_name + "|" << std::setw(10) << last_name + "|" << std::setw(10) << nickname + "|" << "\n";
	}
}

void	PhoneBook::displayContactAtIndex(int index) {
	std::string first_name = contacts[index].getFirstName();
	std::string last_name = contacts[index].getLastName();
	std::string nickname = contacts[index].getNickName();
	std::string phone_number = contacts[index].getPhoneNumber();
	std::string secret = contacts[index].getDarkestSecret();
	std::cout << "\n";
	std::cout << std::setw(10) << "" << "First Name       :   " + first_name.append("\n");
	std::cout << std::setw(10) << "" << "Last Name        :   " + last_name.append("\n");
	std::cout << std::setw(10) << "" << "Nick Name        :   " + nickname.append("\n");
	std::cout << std::setw(10) << "" << "Phone Name       :   " + phone_number.append("\n");
	std::cout << std::setw(10) << "" << "Darkest Secret   :   " + secret.append("\n");
	std::cout << "\n";
}

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

