/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:12:47 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/25 11:20:01 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	
    try {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << "Attempting shortestSpan with 1 element..." << std::endl;
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }


    try {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        std::cout << "Attempting to add 3rd element to Span of size 2..." << std::endl;
        sp.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }


    try {
        unsigned int size = 15000;
        Span bigSpan(size);

        std::vector<int> randomNumbers;
        randomNumbers.reserve(size);
        
        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < size; ++i) {
            randomNumbers.push_back(std::rand());
        }

        bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Successfully added " << size << " numbers via Iterator Range!" << std::endl;
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception in large test: " << e.what() << std::endl;
    }

    return 0;
}