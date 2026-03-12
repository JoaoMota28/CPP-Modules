/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:09:50 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/12 14:59:37 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default")
{
	_hit_points = 10; 
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_hit_points = 10; 
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "ClapTrap parameterized constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	
	if (this != &other) {
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}
		
void ClapTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points)
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > 0)
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points > 0 && _energy_points)
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " repairs " << amount << " points of damage!" << std::endl;
	}
	else if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
}
