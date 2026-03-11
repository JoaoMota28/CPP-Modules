/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:07:47 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/11 11:01:00 by jomanuel         ###   ########.fr       */
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
	
		void	announce(void);

	private:
		std::string _name;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
