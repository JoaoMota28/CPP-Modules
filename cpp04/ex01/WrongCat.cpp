/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:13:01 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 21:13:36 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Default constructor called for WrongCat." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
	this->_type = other.getType();
	std::cout << "Copy constructor called for WrongCat." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy assignment operator called for WrongCat." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Moo?" << std::endl;
}