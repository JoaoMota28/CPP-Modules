/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:13:55 by jomanuel          #+#    #+#             */
/*   Updated: 2026/04/14 18:20:35 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	std::cout << "Default constructor called for Cat." << std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat." << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Copy constructor called for Cat." << std::endl;
	this->_type = other.getType();
	this->_brain = new Brain(*other.getBrain());
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment operator called for Cat." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
		
		delete this->_brain;
		this->_brain = new Brain(*other.getBrain());
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow." << std::endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}
