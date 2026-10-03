/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:55:37 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/23 11:34:20 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Assigned grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Assigned grade is too low!";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor for Bureaucrat was called: " << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "Parameterized constructor for Bureaucrat was called: " << *this << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for Bureaucrat was called: " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Copy constructor for Bureaucrat was called: " << *this << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade() throw(Bureaucrat::GradeTooHighException)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() throw(Bureaucrat::GradeTooLowException)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try {
		form.Form::beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	
	catch (Form::GradeTooLowException& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because his grade is too low." << std::endl;
	}
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
}
