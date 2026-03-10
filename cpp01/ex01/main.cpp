/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:28:13 by jomanuel          #+#    #+#             */
/*   Updated: 2025/09/24 21:39:38 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 5;
	Zombie *zombieHorde = Zombie::zombieHorde(N, "NEE");

	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].announce();
	}

	delete[] zombieHorde;
}