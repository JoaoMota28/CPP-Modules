/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:33:15 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 18:28:56 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	
}

Weapon::~Weapon()
{
	
}

const std::string&	Weapon::getType(void)
{
	return type;
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}