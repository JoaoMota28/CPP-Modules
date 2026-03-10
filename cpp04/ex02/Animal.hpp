/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:13:46 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/18 16:33:22 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		virtual ~Animal();
		virtual void makeSound() const = 0;
		virtual const std::string& getType(void) const;

	protected:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
	
		std::string _type;
};

#endif