/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:09:50 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 16:05:24 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap parameterized constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
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
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else if (_hit_points <= 0)
		std::cout << "ClapTrap " << getName() << " is dead." << std::endl;
	else
		std::cout << "ClapTrap " << getName() << " is out of energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > 0)
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << getName() << " is already dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points > 0 && _energy_points)
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << getName() << " repairs " << amount << " points of damage!" << std::endl;
	}
	else if (_hit_points <= 0)
		std::cout << "ClapTrap " << getName() << " is dead." << std::endl;
	else
		std::cout << "ClapTrap " << getName() << " is out of energy." << std::endl;
}

std::string	ClapTrap::getName() const
{
	return _name;
}

void ClapTrap::setName(const std::string& name)
{
	_name = name;
}
		
int	ClapTrap::getHitPoints() const
{
	return _hit_points;
}

void ClapTrap::setHitPoints(int points)
{
	_hit_points = points;
}
		
int	ClapTrap::getEnergyPoints() const
{
	return _energy_points;
}

void ClapTrap::setEnergyPoints(int points)
{
	_energy_points = points;
}
		
int	ClapTrap::getAttackDamage() const
{
	return _attack_damage;
}

void ClapTrap::setAttackDamage(int points)
{
	_attack_damage = points;
}
