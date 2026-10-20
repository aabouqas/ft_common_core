/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:07:28 by aabouqas          #+#    #+#             */
/*   Updated: 2024/10/04 15:17:44 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define nOfAnimals 6

int main()
{
	Animal	*animals[nOfAnimals];
	for (int n = 0; n < nOfAnimals; n++) {
		if (n < (nOfAnimals / 2))
			animals[n] = new Dog();
		else
			animals[n] = new Cat();
	}
	std::cout << std::endl;
	for (int n = 0; n < nOfAnimals; n++) {
		animals[n]->makeSound();
	}
	std::cout << std::endl;
	for (int n = 0; n < nOfAnimals; n++) {
		delete animals[n];
	}
	std::cout << std::endl;
	std::cout << "TEST 2" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	std::cout << std::endl;
	Cat basic;
	{
		Cat tmp = basic;
	}
	return 0;
}
