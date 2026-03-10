/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:41:21 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/04 11:21:26 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point a = Point(1, 3);
	Point b = Point(3, 7);
	Point c = Point(6, 3);
	
	//Inside triangle:
	std::cout << (bsp(a, b, c, Point(4, 5)) ? "True" : "False") << std::endl;

	//Outside triangle:
	std::cout << (bsp(a, b, c, Point(7, 6)) ? "True" : "False") << std::endl;

	//In triangle lines:
	std::cout << (bsp(a, b, c, Point(2, 5)) ? "True" : "False") << std::endl;
	
	return 0;
}
