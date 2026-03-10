/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:14:01 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 19:53:44 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Default constructor called for Dog." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog." << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	this->_type = other.getType();
	std::cout << "Copy constructor called for Dog." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator called for Dog." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof." << std::endl;
}
