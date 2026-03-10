/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:13:07 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 19:34:39 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap parameterized constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}
	
void FragTrap::attack(const std::string& target)
{
	if (getHitPoints() > 0 && getEnergyPoints())
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else if (getHitPoints() <= 0)
		std::cout << "FragTrap " << getName() << " is dead." << std::endl;
	else
		std::cout << "FragTrap " << getName() << " is out of energy." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " wants to high-five you." << std::endl;
}