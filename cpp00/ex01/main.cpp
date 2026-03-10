/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:15:06 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/09 15:08:08 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string buff;
	PhoneBook pb;
	void (PhoneBook::*fn)();

	while (true)
	{
		std::cout << "Input phonebook command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, buff))
		{
			std::cerr << "EOF detected, aborting." << std::endl;
			return EXIT_FAILURE;
		}
		std::cout << std::endl;

		fn = pb.phonebook_option_selector(buff);
		if (!fn)
		{
			std::cout << "Invalid option. Use 'ADD' to add a new contact, 'SEARCH' to search for a contact, or 'EXIT' to exit the phonebook." << std::endl << std::endl;
			continue ;
		}
		
		(pb.*fn)();
		if (pb.eof_detected())
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
