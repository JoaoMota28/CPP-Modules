/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:19:12 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/18 12:35:36 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called for Brain." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain." << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor called for Brain." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Copy assignment operator called for Brain." << std::endl;
	if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
	else
		std::cerr << "Idea index out of range." << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _ideas[index];
	std::cerr << "Idea index out of range." << std::endl;
	return NULL;
}
