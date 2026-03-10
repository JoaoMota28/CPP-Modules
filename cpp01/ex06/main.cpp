/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:34:53 by jomanuel          #+#    #+#             */
/*   Updated: 2025/09/29 15:05:13 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./harlFilter <Filter word>" << std::endl;
		return 1;
	}
	
	Harl	harl;
	
	harl.complain(argv[1]);
}