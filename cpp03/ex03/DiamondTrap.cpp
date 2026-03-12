/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:55:45 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/12 15:12:26 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name")
{
	this->_name = "Default";
	this->_hit_points = FragTrap::F_hit_points;
    this->_energy_points = ScavTrap::S_energy_points;
    this->_attack_damage = FragTrap::F_attack_damage;
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit_points = FragTrap::F_hit_points;
    this->_energy_points = ScavTrap::S_energy_points;
    this->_attack_damage = FragTrap::F_attack_damage;
    std::cout << "DiamondTrap parameterized constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called." << std::endl;
	
	if (this != &other) {
		ClapTrap::operator=(other);
        this->_name = other._name;
	}
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
