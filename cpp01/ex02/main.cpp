/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:46:48 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/09 17:03:15 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain; 
	std::string &stringREF = brain;

	std::cout << "String memory address: " << &brain << std::endl;
	std::cout << "Pointer memory address: " << stringPTR << std::endl;
	std::cout << "Reference memory address: " << &stringREF << std::endl;

	std::cout << "String value: " << brain << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl << std::endl;

	
	std::cout << "Changing string value..." << std::endl;
	brain = "BRAIN IS NOT BRAINING";
	
	std::cout << "String memory address: " << &brain << std::endl;
	std::cout << "Pointer memory address: " << stringPTR << std::endl;
	std::cout << "Reference memory address: " << &stringREF << std::endl;

	std::cout << "String value: " << brain << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl << std::endl;

	
	std::cout << "Changing pointer value..." << std::endl;
	*stringPTR = "BRAIN NEVER BRAINED";
	
	std::cout << "String memory address: " << &brain << std::endl;
	std::cout << "Pointer memory address: " << stringPTR << std::endl;
	std::cout << "Reference memory address: " << &stringREF << std::endl;

	std::cout << "String value: " << brain << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl << std::endl;

	
	std::cout << "Changing reference value..." << std::endl;
	stringREF = "IS BRAIN EVEN SUPPOSED TO BRAIN?";
	
	std::cout << "String memory address: " << &brain << std::endl;
	std::cout << "Pointer memory address: " << stringPTR << std::endl;
	std::cout << "Reference memory address: " << &stringREF << std::endl;

	std::cout << "String value: " << brain << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl << std::endl;

	
	std::cout << "Changing pointer address..." << std::endl;
	stringPTR = new std::string("BUT THIS BRAIN BRAINS");
	
	std::cout << "String memory address: " << &brain << std::endl;
	std::cout << "Pointer memory address: " << stringPTR << std::endl;
	std::cout << "Reference memory address: " << &stringREF << std::endl;

	std::cout << "String value: " << brain << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl << std::endl;
	delete stringPTR;
}
