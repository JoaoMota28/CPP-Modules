/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:09:52 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 20:10:19 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt1;
    dt1.whoAmI();
    dt1.attack("Enemy1");

    DiamondTrap dt2("Bob");
    dt2.whoAmI();
    dt2.attack("Enemy2");

    DiamondTrap dt3(dt2);
    dt3.whoAmI();
    dt3.attack("Enemy3");

    dt1 = dt2;
    dt1.whoAmI();
    dt1.attack("Enemy4");

    DiamondTrap dt4("Alice");
    dt4.whoAmI();
    dt4.attack("Enemy5");

    return 0;
}
