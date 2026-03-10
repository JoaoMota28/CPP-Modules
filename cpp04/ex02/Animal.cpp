/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:13:50 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/18 16:31:06 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default constructor called for Animal." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal." << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Copy constructor called for Animal." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy assignment operator called for Animal." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

const std::string& Animal::getType(void) const
{
	return _type;
}

/*void Animal::makeSound() const
{
	std::cout << "No sound." << std::endl;
}*/
