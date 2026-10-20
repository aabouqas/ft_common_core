/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:49:37 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/24 11:55:08 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>


class	Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		Contact();
		~Contact();
		void			setFirstName(std::string first_name);
		void			setLastName(std::string last_name);
		void			setNickName(std::string nickname);
		void			setPhoneNumber(std::string phone_number);
		void			setDarkestSecret(std::string darkest_secret);
		std::string		getFirstName();
		std::string		getLastName();
		std::string		getNickName();
		std::string		getPhoneNumber();
		std::string		getDarkestSecret();
};

# endif
