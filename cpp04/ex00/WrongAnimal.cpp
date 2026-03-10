/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:08:48 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 21:12:52 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Default constructor called for WrongAnimal." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "Copy constructor called for WrongAnimal." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Copy assignment operator called for WrongAnimal." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

const std::string& WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong kind of no sound." << std::endl;
}