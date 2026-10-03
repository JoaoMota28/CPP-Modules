/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:37:33 by jomanuel          #+#    #+#             */
/*   Updated: 2026/09/30 17:31:38 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data data;

	data.number = 42;
	data.name = "Hello";

	Data *original = &data;

	uintptr_t raw = Serializer::serialize(original);

	std::cout << "original: " << original << std::endl;
	std::cout << "raw: " << raw << std::endl << std::endl;

	Data *result = Serializer::deserialize(raw);

	std::cout << "original: " << original << std::endl;
	std::cout << "result: " << result << std::endl;

	if (result == original)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are different" << std::endl;
}
