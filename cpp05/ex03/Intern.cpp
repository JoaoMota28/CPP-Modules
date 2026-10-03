/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:41:09 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/23 15:19:51 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef AForm* (*FormCreator)(const std::string&);

struct FormEntry {
    const char*  name;
    FormCreator  creator;
};

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern()
{
	std::cout << "Default constructor for Intern was called: " << std::endl;
}

Intern::~Intern()
{
	std::cout << "Default destructor for Intern was called: " << std::endl;
}

Intern::Intern(const Intern&)
{
	std::cout << "Copy constructor for Intern was called: " << std::endl;
}

Intern& Intern::operator=(const Intern&)
{
    return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    const FormEntry table[] = {
        { "shrubbery creation", makeShrubbery },
        { "robotomy request",   makeRobotomy },
        { "presidential pardon", makePardon }
    };
    const int size = 3;

    for (int i = 0; i < size; i++) {
        if (name == table[i].name) {
            std::cout << "Intern creates " << name << std::endl;
            return table[i].creator(target);
        }
    }
    std::cout << "Intern: unknown form name: " << name << std::endl;
    return NULL;
}
