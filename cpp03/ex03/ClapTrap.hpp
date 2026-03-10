/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:09:47 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 19:53:25 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator= (const ClapTrap& other);
		
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
	
	protected:
		virtual std::string	getName() const;
		void		setName(const std::string& name);
		
		int			getHitPoints() const;
		void		setHitPoints(int points);
		
		int			getEnergyPoints() const;
		void		setEnergyPoints(int points);
		
		int			getAttackDamage() const;
		void		setAttackDamage(int points);
};

#endif