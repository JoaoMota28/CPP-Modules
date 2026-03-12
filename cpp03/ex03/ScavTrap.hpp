/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:35:37 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/12 15:07:32 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		virtual ~ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator= (const ScavTrap& other);
		
		void attack(const std::string& target);
		void guardGate();

	protected:
		int			S_hit_points;
		int			S_energy_points;
		int			S_attack_damage;
};

#endif