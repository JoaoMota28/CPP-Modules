/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:14:01 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/18 13:36:42 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	std::cout << "Default constructor called for Dog." << std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog." << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& other) : Animal(), _brain(new Brain())
{
	std::cout << "Copy constructor called for Dog." << std::endl;
	this->_type = other.getType();
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

Brain* Dog::getBrain() const
{
	return _brain;
}
