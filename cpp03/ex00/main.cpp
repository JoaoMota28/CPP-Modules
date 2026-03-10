/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:09:52 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 12:29:42 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	// Constructors
    ClapTrap A("A");
    ClapTrap B("B");

	// Attack
    A.attack("B");
    B.takeDamage(0);

	// Take damage
    B.takeDamage(5);
    
    // Repair
    B.beRepaired(3);

    // Deplete energy
    for (int i = 0; i < 10; i++)
        A.attack("Dummy");
    
    // Attack with no energy
    A.attack("Dummy");

    // Lethal damage
    B.takeDamage(20);
    
    // Repair and attack while being dead
    B.beRepaired(10);
    B.attack("Dummy");

    return 0;
}
