/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:47:37 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/23 11:34:40 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Assigned grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Assigned grade is too low!";
}

Form::Form() : _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "Default constructor for Form was called: " << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) throw(GradeTooHighException, GradeTooLowException)
	: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	std::cout << "Parameterized constructor for Form was called: " << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor for Form was called: " << *this << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	std::cout << "Copy constructor for Form was called: " << *this << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return *this;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_is_signed = true;
}

std::ostream& operator<< (std::ostream& os, const Form& form)
{
	os << form.getName() << ", " << (form.getIsSigned() ? "is signed" : "is not signed");
	os << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}
