/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:50:07 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/23 15:32:24 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "Default constructor for ShrubberyCreationForm was called: " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for ShrubberyCreationForm was called: " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parameterized constructor for ShrubberyCreationForm was called: " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "Copy constructor for ShrubberyCreationForm was called: " << *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&)
{
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	
	std::string filename = this->_target + "_shrubbery";
    
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open()) {
        std::cout << "Failure to open the file." << std::endl;
        return; 
    }

    outfile << "       _-_        " << std::endl;
    outfile << "    /~~   ~~\\     " << std::endl;
    outfile << " /~~         ~~\\  " << std::endl;
    outfile << "{               } " << std::endl;
    outfile << " \\  _-     -_  /  " << std::endl;
    outfile << "   ~  \\\\ //  ~    " << std::endl;
    outfile << " _- -  | | _- _   " << std::endl;
    outfile << "   _ - | |   -_   " << std::endl;
    outfile << "      // \\\\       " << std::endl;
    outfile << std::endl;

    outfile.close();
}
