/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:28:24 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/11 11:09:44 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
	
		void	setName(std::string name);
		void	announce(void);

	private:
		std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif