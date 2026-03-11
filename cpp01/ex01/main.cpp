/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:28:13 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/11 11:11:10 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "NEE");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}