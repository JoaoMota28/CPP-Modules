/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:13:07 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/12 15:10:07 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hit_points = 100; F_hit_points = 100;
	this->_energy_points = 100; F_energy_points = 100;
	this->_attack_damage = 30; F_attack_damage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100; F_hit_points = 100;
	this->_energy_points = 100; F_energy_points = 100;
	this->_attack_damage = 30; F_attack_damage = 100;
	std::cout << "FragTrap parameterized constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other._name)
{
	_name = other._name;
	_hit_points = other._hit_points; F_hit_points = other.F_hit_points;
	_energy_points = other._energy_points; F_energy_points = other.F_energy_points;
	_attack_damage = other._attack_damage; F_attack_damage = other.F_attack_damage;
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	
	if (this != &other) {
		ClapTrap::operator=(other);
		F_hit_points = other.F_hit_points;
		F_energy_points = other.F_energy_points;
		F_attack_damage = other.F_attack_damage;
	}
	return *this;
}
	
void FragTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points)
	{
		_energy_points -= 1;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else if (_hit_points <= 0)
		std::cout << "FragTrap " << _name << " is dead." << std::endl;
	else
		std::cout << "FragTrap " << _name << " is out of energy." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " wants to high-five you." << std::endl;
}