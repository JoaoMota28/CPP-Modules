/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:09:52 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 19:09:08 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap F;
    ClapTrap H;
    
    F.attack("Other");
    F.highFivesGuys();

    H.attack("Clap");
    return 0;
}
