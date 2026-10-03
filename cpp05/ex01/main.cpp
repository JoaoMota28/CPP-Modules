/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:55:39 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/22 12:29:41 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{

	// TEST 1: Valid Form construction and operator<<

	try {
		Form olympusPermit("Mount Olympus Entry Permit", 10, 5);
		std::cout << olympusPermit << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 2: Form with invalid grade -> GradeTooHighException (grade_to_sign < 1)

	try {
		Form forbidden("Forbidden Scroll", 0, 5);
		(void)forbidden;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 3: Form with invalid grade -> GradeTooLowException (grade > 150)

	try {
		Form cursed("Cursed Papyrus", 10, 200);
		(void)cursed;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 4: Successful signing

	try {
		Bureaucrat athena("Athena", 5);
		Form wisdomDecree("Wisdom Decree", 10, 3);
		std::cout << "Before: " << wisdomDecree << std::endl;
		athena.signForm(wisdomDecree);
		std::cout << "After:  " << wisdomDecree << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 5: Failed signing (grade too low)

	try {
		Bureaucrat sisyphus("Sisyphus", 150);
		Form divineDecree("Divine Decree", 1, 1);
		std::cout << "Before: " << divineDecree << std::endl;
		sisyphus.signForm(divineDecree);
		std::cout << "After:  " << divineDecree << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 6: Boundary — bureaucrat grade exactly equals required sign grade

	try {
		Bureaucrat hephaestus("Hephaestus", 50);
		Form forgeLicense("Forge License", 50, 20);
		std::cout << "Before: " << forgeLicense << std::endl;
		hephaestus.signForm(forgeLicense);
		std::cout << "After:  " << forgeLicense << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return 0;
}
