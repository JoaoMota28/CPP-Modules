/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:13:55 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 19:53:40 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Default constructor called for Cat." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat." << std::endl;
}

Cat::Cat(const Cat& other) : Animal()
{
	this->_type = other.getType();
	std::cout << "Copy constructor called for Cat." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment operator called for Cat." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow." << std::endl;
}
