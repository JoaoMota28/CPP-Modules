/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:55:43 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 20:07:26 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		virtual ~DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator= (const DiamondTrap& other);
		
		virtual void attack(const std::string& target);
		void whoAmI(void);
		std::string getName() const;
	
	private:
		std::string _name;
};

#endif