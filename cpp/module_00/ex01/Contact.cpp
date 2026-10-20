/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:49:28 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/22 16:53:18 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string first_name) {
	this->first_name = first_name;
}

void	Contact::setLastName(std::string last_name) {
	this->last_name = last_name;
}

void	Contact::setNickName(std::string nickname) {
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number) {
	this->phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}

std::string	Contact::getFirstName()
{
	return this->first_name;
}

std::string	Contact::getLastName()
{
	return this->last_name;
}

std::string	Contact::getNickName()
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber() {
	return this->phone_number;
}

std::string	Contact::getDarkestSecret()
{
	return this->darkest_secret;
}

Contact::Contact()
{
}

Contact::~Contact() {

}
