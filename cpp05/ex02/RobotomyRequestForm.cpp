/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:14:54 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/23 15:32:41 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::_isSeeded = false;

void RobotomyRequestForm::ensureSeeded() {
    if (!_isSeeded) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        _isSeeded = true; 
    }
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	ensureSeeded();
	std::cout << "Default constructor for RobotomyRequestForm was called: " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor for RobotomyRequestForm was called: " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	ensureSeeded();
	std::cout << "Parameterized constructor for RobotomyRequestForm was called: " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "Copy constructor for RobotomyRequestForm was called: " << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&)
{
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << "*drilling noises*" << std::endl;
	
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
