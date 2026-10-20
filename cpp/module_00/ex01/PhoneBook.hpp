/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:44:04 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/24 11:58:23 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"



class PhoneBook {
	private:
		Contact			contacts[8];
		unsigned short	index;
	public:
		PhoneBook();
		~PhoneBook();
		int					Amount;
		void				addContact(Contact contact);
		void				displayContactAtIndex(int index);
		void				displayContacts();
};

bool	isValidNumber(std::string input);
int		isValidName(std::string &String);
int		isValidIndex(std::string input, PhoneBook phoneBook);

# endif
