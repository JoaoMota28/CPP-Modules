/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:34:34 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/10 15:34:29 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	
}

Harl::~Harl()
{
	
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl << std::endl;
}
		
void	Harl::complain(std::string level)
{
    static LevelFn fn_arr[4] = {
        {"DEBUG",   0},
        {"INFO",    1},
        {"WARNING", 2},
        {"ERROR",   3}
    };

	int	level_val = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == fn_arr[i].name)
		{
			level_val = fn_arr[i].val;
			break ;
		}
	}

	switch (level_val)
	{
		case 0:
			Harl::debug();
			/* fall through */
		case 1:
			Harl::info();
			/* fall through */
		case 2:
			Harl::warning();
			/* fall through */
		case 3:
			Harl::error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
