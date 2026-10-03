/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:01:28 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/24 17:04:00 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::list<int> l;
	
	for (int i = 0; i < 6; i++)
		l.push_back(i);
	
	std::list<int>::const_iterator it = ::easyfind(l, 3);
	std::list<int>::const_iterator it2 = ::easyfind(l, 7);
	
	if (it != l.end())
		std::cout << "Found it value: " << *it << std::endl;
	else
		std::cout << "Found no it value!" << std::endl;
		
	if (it2 != l.end())
		std::cout << "Found it value: " << *it2 << std::endl;
	else
		std::cout << "Found no it2 value!" << std::endl;
	

	std::vector<int> v;

	for (int i = 0; i < 6; i++)
		v.push_back(i);
	
	std::vector<int>::const_iterator it3 = ::easyfind(v, 3);
	std::vector<int>::const_iterator it4 = ::easyfind(v, 7);
	
	if (it3 != v.end())
		std::cout << "Found it3 value: " << *it3 << std::endl;
	else
		std::cout << "Found no it3 value!" << std::endl;
		
	if (it4 != v.end())
		std::cout << "Found it4 value: " << *it4 << std::endl;
	else
		std::cout << "Found no it4 value!" << std::endl;
	
	return 0;
}
