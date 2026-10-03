/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:55:39 by jomanuel          #+#    #+#             */
/*   Updated: 2026/04/14 20:34:48 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
    // Test 1: Valid Bureaucrat and << operator
	
    try {
        Bureaucrat b1("Hermes", 42);
        std::cout << b1;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 2: Grade too high at construction
    try {
        Bureaucrat b2("Zeus", 0);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    // Test 3: Grade too low at construction
    try {
        Bureaucrat b3("Mortal", 151);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    // Test 4: Increment/Decrement boundaries
    try {
        Bureaucrat b4("Athena", 2);
        std::cout << b4;
        b4.incrementGrade();
        std::cout << "After increment: " << b4;
        b4.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Apollo", 149);
        std::cout << b5;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5;
        b5.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    return 0;
}