/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:35:39 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/12 15:11:48 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hit_points = 100; S_hit_points = 100;
	this->_energy_points = 50; S_energy_points = 50;
	this->_attack_damage = 20; S_attack_damage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100; S_hit_points = 100;
	this->_energy_points = 50; S_energy_points = 50;
	this->_attack_damage = 20; S_attack_damage = 20;
	std::cout << "ScavTrap parameterized constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name)
{
	_name = other._name;
	_hit_points = other._hit_points; S_hit_points = other.S_hit_points;
	_energy_points = other._energy_points; S_energy_points = other.S_energy_points;
	_attack_damage = other._attack_damage; S_attack_damage = other.S_attack_damage;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	
	if (this != &other) {
		ClapTrap::operator=(other);
		S_hit_points = other.S_hit_points;
		S_energy_points = other.S_energy_points;
		S_attack_damage = other.S_attack_damage;
	}
	return *this;
}
	
void ScavTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points)
	{
		_energy_points -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else if (_hit_points <= 0)
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is out of energy." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}
