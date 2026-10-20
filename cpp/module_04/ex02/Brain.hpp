/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:12:39 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 11:57:36 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
	protected:
		std::string	ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &Obj);
		Brain&operator=(const Brain &Obj);
};
